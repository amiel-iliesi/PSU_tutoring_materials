from __future__ import annotations
from typing import Any
from graph import Graph, Path, Search
from math import sqrt
import numpy as np
from random import uniform


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


def skip_summary(test_name: str):
    '''If a test is skipped under certain conditions, print a summary
    indicating that.'''
    print(f'[*] {test_name}<SKIPPED>')


def all_paths(graph: Graph,
              source: Any,
              destination: Any
              ) -> dict[Search, Path]:
    '''Runs path search on all search algorithms and returns a dictionary of
    the results.'''
    return {search: graph.path(source, destination, method=search)
            for search in Search}


def header(s: str) -> str:
    return f'{s}\n{'-'*len(s)}'


class Point:
    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y

    def __eq__(self, value: object) -> bool:
        if isinstance(value, Point):
            return self.x == value.x and self.y == value.y
        else:
            raise TypeError(f'Point == {type(value)}: undefined')

    def __str__(self) -> str:
        return f'({self.x}, {self.y})'

    def __repr__(self) -> str:
        return f'Point(x={self.x}, y={self.y})'

    @staticmethod
    def distance(a: Point, b: Point) -> float:
        '''Returns the Euclidean distance between the two points.'''
        return sqrt((a.x-b.x)**2 + (a.y-b.y)**2)

    @staticmethod
    def distance_manhattan(a: Point, b: Point) -> float:
        '''Faster but less accurate than Euclidean distance.'''
        return abs(a.x-b.x) + abs(a.y-b.y)


def generate_graph(num_vertices: int,
                   min_connections: int,
                   max_connections: int,
                   wander: float
                   ) -> Graph:
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
