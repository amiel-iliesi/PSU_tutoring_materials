from __future__ import annotations
from math import sqrt


class Point:
    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y

    def __eq__(self, value: object) -> bool:
        if isinstance(value, Point):
            return self.x == value.x and self.y == value.y
        else:
            raise TypeError(f'Point == {type(value)}: undefined')

    def __hash__(self) -> int:
        return hash((self.x, self.y))

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
