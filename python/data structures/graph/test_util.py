from __future__ import annotations
from typing import Any, Optional, Callable
from graph import Graph, Path, Search
import numpy as np
from random import uniform
from graph_types import Point


def summary(test_name: str,
            successes: int,
            cases: int,
            fail_messages: list[str]
            ) -> None:
    '''Prints a summary of the test run in a standardized format.'''
    total_success = successes == cases
    test_header = f'[{'✓' if total_success else '✗'}] ' +\
        f'{test_name}: {successes}/{cases}'
    print(test_header)

    if len(fail_messages) > 0:
        print('-'*len(test_header))

    for fail_message in fail_messages:
        print(f'\t***{fail_message}')


def skip_summary(test_name: str, reason: str):
    '''If a test is skipped under certain conditions, print a summary
    indicating that.'''
    print(f'[?] {test_name}<SKIPPED>: {reason}')


def all_paths(graph: Graph,
              source: Any,
              destination: Any,
              heuristic: Optional[Callable[[Any], float]] = None
              ) -> dict[Search, Path]:
    '''Runs path search on all search algorithms and returns a dictionary of
    the results. This skips the A* search if no heuristic function is provided,
    IE A* is non-applicable.'''

    methods: list[Search] = []

    if heuristic is not None:
        methods = [search for search in Search]
    else:
        methods = [search for search in Search if search is not Search.A_STAR]

    return {method: graph.path(source, destination, method=method)
            for method in methods}


def header(s: str) -> str:
    return f'{s}\n{'-'*len(s)}'


def generate_graph(num_vertices: int,
                   min_connections: int,
                   max_connections: int,
                   wander: float
                   ) -> Graph:
    '''Generates a random 2D Cartesian graph. The points are weighted by their
    Euclidean distance. The generation of points is serial, and are connected
    to adjacent points, serially--so connected points are more likely to be
    physically closer to one another.'''
    graph = Graph()

    # generate connections all at once for efficiency
    def generate_connections() -> list[int]:
        values = rng.uniform(high=max_connections,
                             low=min_connections,
                             size=num_vertices) + 0.5
        values.tolist()
        return [int(x) for x in values]

    def connect(index: int,
                connections: list[int],
                points: list[Point]
                ) -> None:
        left_delta = connections[index] // 2
        start = index - left_delta
        end = index + connections[index] - left_delta + 1

        if start < 0:
            end += abs(start)
            start = 0

        for i in range(start, end):
            if i == index:
                continue

            point_a = points[index]
            point_b = points[i]
            graph.connect(point_a,
                          point_b,
                          weight=Point.distance(point_a, point_b))

    rng = np.random.default_rng()
    connections = generate_connections()

    # starting point
    x = 0.0
    y = 0.0
    points: list[Point] = []
    for _ in range(num_vertices):
        # wander slightly every next point
        x = uniform(x-wander, x+wander)
        y = uniform(y-wander, y+wander)

        point = Point(x, y)
        points.append(point)
        graph.create_vertex(point)

    for i in range(num_vertices):
        connect(i, connections, points)

    return graph
