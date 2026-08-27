'''Testing suite for `graph.py`'''

from graph import Graph, Search, Path
from test_util import header, summary, skip_summary, all_paths, generate_graph
from test_util import Point
from typing import Optional
import signal
from random import randint


def test_cycles(prerequisite_tests: Optional[list[bool]] = None) -> bool:
    '''Tests if each search algorithm is able to search despite the presence
    of cycles.'''
    if prerequisite_tests is not None:
        if not all(prerequisite_tests):
            skip_summary(test_cycles.__name__, 'prerequisites unmet')
            return False

    graph = Graph()

    # make sure that Graph has all neccessary
    # functions implemented for this test
    try:
        graph.create_vertex('A')
        graph.create_vertex('B')
        graph.connect('A', 'B')
        all_paths(graph, 'A', 'B')
        graph.clear()
    except NotImplementedError:
        skip_summary(test_cycles.__name__,
                     'required graph features not implemented')
        return False  # skip test

    # test statistics variables
    cases: int = 0
    successes: int = 0
    fail_messages: list[str] = []

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
        cases += 1
        fail_message: Optional[str] = None

        path: Path = []

        try:
            signal.alarm(2)

            path = graph.path(SOURCE, DESTINATION, method=search)
        except TimeoutError:
            fail_message = f'{search.name}: timeout'
        else:
            signal.alarm(0)

            if Graph.reaches(DESTINATION, path):
                successes += 1
            else:
                fail_message = f'{search.name}: path not found'

        if fail_message is not None:
            fail_messages.append(fail_message)

    summary(test_cycles.__name__, successes, cases, fail_messages)

    return successes == cases


def test_keyerror(prerequisite_tests: Optional[list[bool]] = None) -> bool:
    '''Tests all calls that should result in a `KeyError`.'''
    if prerequisite_tests is not None:
        if not all(prerequisite_tests):
            skip_summary(test_keyerror.__name__, 'prerequisites unmet')
            return False

    cases: int = 0
    successes: int = 0
    fail_messages: list[str] = []

    graph = Graph()

    try:
        graph.create_vertex('A')
        graph.create_vertex('B')
        graph.connect('A', 'B')
        graph.clear()
    except NotImplementedError:
        skip_summary(test_keyerror.__name__,
                     'required graph features not implemented')
        return False

    # 1. DNE: A, B
    # 1.a. connect
    try:
        cases += 1
        graph.connect('A', 'B')
    except KeyError:
        successes += 1
    else:
        fail_messages.append('connect: A<DNE> -> B<DNE>')

    # 1.b. disconnect
    try:
        cases += 1
        graph.disconnect('A', 'B')
    except KeyError:
        successes += 1
    else:
        fail_messages.append('disconnect: A<DNE> -> B<DNE>')

    # 2. DNE: B
    graph.create_vertex('A')

    # 2.a. connect
    try:
        cases += 1
        graph.connect('A', 'B')
    except KeyError:
        successes += 1
    else:
        fail_messages.append('connect: A -> B<DNE>')

    # 2.b. disconnect
    try:
        cases += 1
        graph.disconnect('A', 'B')
    except KeyError:
        successes += 1
    else:
        fail_messages.append('disconnect: A -> B<DNE>')

    # 3. DNE: A
    graph.remove_vertex('A')
    graph.create_vertex('B')

    # 3.a. connect
    try:
        cases += 1
        graph.connect('A', 'B')
    except KeyError:
        successes += 1
    else:
        fail_messages.append('connect: A<DNE> -> B')

    # 3.b. disconnect
    try:
        cases += 1
        graph.disconnect('A', 'B')
    except KeyError:
        successes += 1
    else:
        fail_messages.append('disconnect: A<DNE> -> B')

    summary(test_keyerror.__name__, successes, cases, fail_messages)

    return successes == cases


def test_vertex_basics() -> bool:
    '''Ensures vertex basic functions are valid.'''
    cases: int = 0
    successes: int = 0
    fail_messages: list[str] = []

    graph = Graph()

    try:
        graph.create_vertex('A')
        graph.remove_vertex('A')
        graph.clear()
    except NotImplementedError:
        skip_summary(test_vertex_basics.__name__,
                     'required graph features not implemented')
        return False

    created = ('A', 'B', 'C')
    not_created = ('D', 'E', 'F')
    created_then_removed = ('G', 'H', 'I')

    cases = len(created + not_created + created_then_removed)

    for label in created + created_then_removed:
        graph.create_vertex(label)

    for label in created_then_removed:
        graph.remove_vertex(label)

    for label in created:
        if label in graph.vertices:
            successes += 1
        else:
            fail_messages.append(f'{label}∉Graph')

    for label in not_created + created_then_removed:
        if label in graph.vertices:
            fail_messages.append(f'{label}∈Graph')
        else:
            successes += 1

    summary(test_vertex_basics.__name__, successes, cases, fail_messages)

    return successes == cases


def test_bidirectionality(prerequisite_tests: Optional[list[bool]] = None
                          ) -> bool:
    '''Tests creation, removal, and updating of edges and their weights with
    bidirectionality.'''
    if prerequisite_tests is not None:
        if not all(prerequisite_tests):
            skip_summary(test_bidirectionality.__name__, 'prerequisites unmet')
            return False

    cases: int = 0
    successes: int = 0
    fail_messages: list[str] = []

    graph = Graph()

    try:
        graph.create_vertex('A')
        graph.create_vertex('B')
        graph.connect('A', 'B')
        graph.disconnect('A', 'B')
        graph.clear()
    except NotImplementedError:
        skip_summary(test_bidirectionality.__name__,
                     'required graph features not implemented')
        return False

    graph.create_vertex('A')
    graph.create_vertex('B')

    a = graph.vertices['A']
    b = graph.vertices['B']

    cases += 1
    graph.connect('A', 'B')
    if a.connected(b) and not b.connected(a):
        successes += 1
    else:
        fail_messages.append('A->B')

    cases += 1
    graph.disconnect('A', 'B')
    if not a.connected(b) and not b.connected(a):
        successes += 1
    else:
        fail_messages.append('A<-x->B')

    cases += 1
    graph.connect('A', 'B', bidirectional=True)
    if a.connected(b) and b.connected(a):
        successes += 1
    else:
        fail_messages.append('A<->B')

    cases += 1
    graph.connect('A', 'B', weight=1.0, bidirectional=True)
    if a.connected(b) and b.connected(a) and \
            a.get_weight(b) == b.get_weight(a) == 1.0:
        successes += 1
    else:
        fail_messages.append('A(1.0)<->B(1.0)')

    summary(test_bidirectionality.__name__, successes, cases, fail_messages)

    return successes == cases


def test_pathfinding(prerequisite_tests: Optional[list[bool]] = None) -> bool:
    '''Generates large, random graphs, and runs many random trials and paths
    over those graphs. No specifics are guaranteed, but the existence of a path
    must be aggreed on by every search method. This test checks that no search
    method fails while others succeed--undefined behavior.'''
    if prerequisite_tests is not None:
        if not all(prerequisite_tests):
            skip_summary(test_pathfinding.__name__, 'prerequisites unmet')
            return False

    cases: int = 0
    successes: int = 0
    fail_messages: list[str] = []

    graph = Graph()

    try:
        graph.create_vertex('A')
        graph.create_vertex('B')
        graph.connect('A', 'B')
        all_paths(graph, 'A', 'B')
        graph.clear()
    except NotImplementedError:
        skip_summary(test_pathfinding.__name__,
                     'required graph features not implemented')
        return False  # skip test

    TRIALS = 5
    N_PATHS_CHECKED = 10
    VERTICES_PER_TRIAL = 100
    AVERAGE_CONNECTIONS = 2
    MAX_CONNECTIONS = 4
    RADIUS = MAX_CONNECTIONS - AVERAGE_CONNECTIONS
    MIN_CONNECTIONS = AVERAGE_CONNECTIONS - RADIUS
    MAX_WANDER = 1.0

    failed_graphs: list[str] = []
    failed_inputs: list[tuple[Point, Point]] = []

    for _ in range(TRIALS):
        graph.clear()
        graph = generate_graph(num_vertices=VERTICES_PER_TRIAL,
                               min_connections=MIN_CONNECTIONS,
                               max_connections=MAX_CONNECTIONS,
                               wander=MAX_WANDER)

        for _ in range(N_PATHS_CHECKED):
            cases += 1
            A = graph.vertices[randint(0, VERTICES_PER_TRIAL-1)]
            B = graph.vertices[randint(0, VERTICES_PER_TRIAL-1)]

            paths = all_paths(graph, A, B)

            n_paths_found = sum(1 for path in paths.values()
                                if Graph.reaches(B, path))

            if n_paths_found == 0 or n_paths_found == len(Search):
                successes += 1
            else:
                fail_messages.append(f'{n_paths_found}/{len(Search)} '
                                     'paths found (should be all or none)')
                failed_graphs.append(graph.to_json())
                failed_inputs.append((A.key, B.key))

    # save failed graphs to `test_pathfinding_failed_graphs.json`
    # load them with Graph.from_json(...)
    with open('test_pathfinding_failed_graphs.json', 'w') as f:
        failed_inputs_json: list[str] = []
        for failed_input in failed_inputs:
            p1 = repr(failed_input[0])
            p2 = repr(failed_input[1])
            failed_inputs_json.append(f'{{"source": {p1}, '
                                      f'"destination": {p2}}}')

        f.write('{"graphs": ["graph": {' +
                graph.to_json() +
                '}, "path_params": [' +
                ','.join(failed_inputs_json) +
                ']]}')

    summary(test_pathfinding.__name__, successes, cases, fail_messages)

    return successes == cases


if __name__ == '__main__':
    print(header('Running tests for graph.py:'))

    result_vertex_basics = test_vertex_basics()

    print()
    result_keyerror = test_keyerror(prerequisite_tests=[result_vertex_basics])

    print()
    result_bidirectionality = test_bidirectionality(
        prerequisite_tests=[result_vertex_basics, result_keyerror]
    )

    print()
    result_cycles = test_cycles(
        prerequisite_tests=[result_vertex_basics, result_keyerror]
    )

    print()
    result_pathfinding = test_pathfinding(
        prerequisite_tests=[result_vertex_basics,
                            result_keyerror,
                            result_bidirectionality,
                            result_cycles]
    )
