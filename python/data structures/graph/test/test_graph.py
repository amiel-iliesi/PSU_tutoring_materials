'''Testing suite for `graph.py`'''

from graph import Graph, Search, Path
from typing import Any
from utils import all_paths, generate_graph
from utils import Point
import pickle
import signal
from random import randint
import pytest

# TODO:
# - convert to pytest
# - create tests for individual pathing algorithms with example graphs


def test_cycles() -> None:
    '''Tests if each search algorithm is able to search despite the presence
    of cycles.'''

    graph = Graph()

    # -run test----------------------------------------------------------------
    for label in ('A', 'B', 'C', 'D'):
        graph.create_vertex(label)

    # create cycle
    graph.connect('A', 'B', weight=1.0)
    graph.connect('B', 'C', weight=1.0)
    graph.connect('C', 'A', weight=1.0)

    # create path to exit
    graph.connect('B', 'D', weight=1.0)

    # check paths on all search algorithms
    SOURCE = 'A'
    DESTINATION = 'D'
    for search in Search:
        path: Path = []

        try:
            signal.alarm(2)

            path = graph.path(SOURCE, DESTINATION, method=search)
        except TimeoutError:
            raise TimeoutError(f'{search.name}: timeout')
        else:
            signal.alarm(0)

            assert Graph.reaches(DESTINATION, path)


def test_keyerror() -> None:
    '''Tests all calls that should result in a `KeyError`.'''

    graph = Graph()

    # 1. DNE: A, B
    # 1.a. connect
    with pytest.raises(KeyError):
        graph.connect('A', 'B')

    # 1.b. disconnect
    with pytest.raises(KeyError):
        graph.disconnect('A', 'B')

    # 2. DNE: B
    graph.create_vertex('A')

    # 2.a. connect
    with pytest.raises(KeyError):
        graph.connect('A', 'B')

    # 2.b. disconnect
    with pytest.raises(KeyError):
        graph.disconnect('A', 'B')

    # 3. DNE: A
    graph.remove_vertex('A')
    graph.create_vertex('B')

    # 3.a. connect
    with pytest.raises(KeyError):
        graph.connect('A', 'B')

    # 3.b. disconnect
    with pytest.raises(KeyError):
        graph.disconnect('A', 'B')


def test_vertex_basics() -> None:
    '''Ensures vertex basic functions are valid.'''
    graph = Graph()

    created = ('A', 'B', 'C')
    not_created = ('D', 'E', 'F')
    created_then_removed = ('G', 'H', 'I')

    for label in created + created_then_removed:
        graph.create_vertex(label)

    for label in created_then_removed:
        graph.remove_vertex(label)

    for label in created:
        assert label in graph.vertices

    for label in not_created + created_then_removed:
        assert label not in graph.vertices


def test_bidirectionality() -> None:
    '''Tests creation, removal, and updating of edges and their weights with
    bidirectionality.'''

    graph = Graph()

    graph.create_vertex('A')
    graph.create_vertex('B')

    a = graph.vertices['A']
    b = graph.vertices['B']

    graph.connect('A', 'B')
    assert a.connected(b) and not b.connected(a)

    graph.disconnect('A', 'B')
    assert not a.connected(b) and not b.connected(a)

    graph.connect('A', 'B', bidirectional=True)
    assert a.connected(b) and b.connected(a)

    graph.connect('A', 'B', weight=1.0, bidirectional=True)
    assert a.connected(b) and b.connected(a) and \
        a.get_weight(b) == b.get_weight(a) == 1.0


def test_pathfinding() -> None:
    '''Generates large, random graphs, and runs many random trials and paths
    over those graphs. No specifics are guaranteed, but the existence of a path
    must be aggreed on by every search method. This test checks that no search
    method fails while others succeed--undefined behavior.'''

    graph = Graph()

    TRIALS = 5
    N_PATHS_CHECKED = 10
    VERTICES_PER_TRIAL = 100
    AVERAGE_CONNECTIONS = 2
    MAX_CONNECTIONS = 4
    RADIUS = MAX_CONNECTIONS - AVERAGE_CONNECTIONS
    MIN_CONNECTIONS = AVERAGE_CONNECTIONS - RADIUS
    MAX_WANDER = 1.0

    for _ in range(TRIALS):
        graph.clear()
        failed_inputs: list[dict[str, Any]] = []

        graph = generate_graph(num_vertices=VERTICES_PER_TRIAL,
                               min_connections=MIN_CONNECTIONS,
                               max_connections=MAX_CONNECTIONS,
                               wander=MAX_WANDER)

        points = list(graph.vertices.keys())

        for _ in range(N_PATHS_CHECKED):
            A = points[randint(0, len(points)-1)]
            B = points[randint(0, len(points)-1)]

            def dist_to_goal(A: Point) -> float:
                return Point.distance(A, B.key)

            paths = all_paths(graph, A, B, heuristic=dist_to_goal)

            n_paths_found = sum(1 for path in paths.values()
                                if Graph.reaches(B, path))

            all_paths_match = n_paths_found == 0 \
                or n_paths_found == len(Search)

            assert all_paths_match

            if not all_paths_match:
                failed_inputs.append({'source': A.key, 'destination': B.key})

        if len(failed_inputs) > 0:
            with open('test_pathfinding_failed_graphs.pickle', 'wb') as f:
                failed_graph: dict[str, Any] = {}

                failed_graph['graph'] = graph
                failed_graph['inputs'] = failed_inputs

                pickle.dump(failed_graph, f)
