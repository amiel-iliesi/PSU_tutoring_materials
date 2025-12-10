import graph as g
from typing import TypeVar, Optional

T = TypeVar('T')


class SearchGraph(g.Graph[T]):
    '''Implements search algorithms for graphs.'''

    def __init__(self):
        super().__init__()

    def DFS(self, A: T, B: T) -> Optional[list[T]]:
        '''Depth-First Search.'''
        for key in (A, B):
            if key not in self.vertices:
                return None

        searched: set[g._Vertex[T]] = set()

        def _DFS(curr: g._Vertex[T], goal: g._Vertex[T]) -> Optional[list[T]]:
            if curr == goal:
                return [curr.key]
            elif curr in searched:
                return None

            searched.add(curr)

            for e in curr.edges.values():
                path = _DFS(e.to, goal)
                if path is not None:
                    return [curr.key] + path

            return None

        return _DFS(self.vertices[A], self.vertices[B])

    def BFS(self, A: T, B: T) -> Optional[list[T]]:
        '''Breadth-First Search.'''
        for key in (A, B):
            if key not in self.vertices:
                return None

        searched: set[g._Vertex[T]] = set()

        # format for queue is [(curr, prev), ...]
        # NOTE: prev can be None because the start has no prev
        queue: list[tuple[g._Vertex[T],
                          Optional[g._Vertex[T]]]] = [(self.vertices[A], None)]

        goal = self.vertices[B]

        # NOTE: value can be None for the same reason queue prev can be None
        _from: dict[g._Vertex[T], Optional[g._Vertex[T]]] = {}

        found = False

        while queue:
            curr, prev = queue.pop(0)

            if curr == goal:
                _from[curr] = prev
                found = True
                break
            elif curr in searched:
                continue

            searched.add(curr)
            _from[curr] = prev

            for e in curr.edges.values():
                queue.append((e.to, curr))

        path: list[T] = []

        if found:
            path_curr: Optional[g._Vertex[T]] = goal
            while path_curr is not None:
                path.insert(0, path_curr.key)
                path_curr = _from[path_curr]

        return path if path else None
