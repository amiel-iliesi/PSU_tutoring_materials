from __future__ import annotations
from math import sqrt


class Coord:
    '''2D coordinate pair of floats'''

    def __init__(self, x: float, y: float):
        self.x: float = x
        self.y: float = y

    def __str__(self):
        return f'({self.x}, {self.y})'

    def __repr__(self):
        return f'Coord(x={self.y}, y={self.y})'

    def __eq__(self, value):
        if isinstance(value, Coord):
            return self.x == value.x and self.y == value.y
        else:
            raise ValueError(f'{value} is not a Coord')

    def __hash__(self):
        return hash(self.x) + hash(self.y)

    def dist(self, other: Coord) -> float:
        '''Returns the euclidean distance between coordinates.'''
        dx = self.x - other.x
        dy = self.y - other.y
        return sqrt(dx*dx + dy*dy)
