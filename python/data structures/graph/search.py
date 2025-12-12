import graph as g
from typing import TypeVar, TypeAlias, Optional, Any
from collections import deque

T = TypeVar('T')

Path: TypeAlias = list[tuple[T, Any]]


class SearchGraph(g.Graph[T]):
    '''Implements search algorithms for graphs.'''

    def __init__(self):
        super().__init__()

    def DFS(self, A: T, B: T) -> Optional[Path]:
        '''Depth-First Search.

        **returns**:

        The path, along with the weight from the previous vertex, IE

        (vertex key, weight from previous)'''
        for key in (A, B):
            if key not in self.vertices:
                raise KeyError(f'{key} is not in the graph')

        searched: set[g._Vertex[T]] = set()

        goal = self.vertices[B]

        # stack is [(curr, path), ...]
        stack: list[tuple[g._Vertex[T], Path]] = [
            (self.vertices[A], [(A, None)])
        ]

        while stack:
            curr, path = stack.pop()

            if curr == goal:
                return path
            elif curr in searched:
                continue

            searched.add(curr)

            for e in reversed(list(curr.edges.values())):
                _next = e.to
                weight = e.weight
                if _next not in searched:
                    stack.append((_next, path + [(_next.key, weight)]))

        return None

    def BFS(self, A: T, B: T) -> Optional[Path]:
        '''Breadth-First Search.

        **returns**:

        The path, along with the weight from the previous vertex, IE

        (vertex key, weight from previous)
        '''
        for key in (A, B):
            if key not in self.vertices:
                raise KeyError(f'{key} is not in the graph')

        searched: set[g._Vertex[T]] = set()

        QueueElement: TypeAlias = tuple[g._Vertex, Optional[g._Vertex], Any]

        # format for queue is [(curr, prev, edge weight), ...]
        # NOTE: prev can be None because the start has no prev
        queue: deque[QueueElement] = deque([(self.vertices[A], None, None)])

        goal = self.vertices[B]

        # NOTE: value can be None for the same reason queue prev can be None
        _from: dict[g._Vertex[T], tuple[Optional[g._Vertex[T]], Any]] = {}

        found = False

        while queue:
            curr, prev, weight = queue.popleft()

            if curr == goal:
                _from[curr] = (prev, weight)
                found = True
                break

            searched.add(curr)
            _from[curr] = (prev, weight)

            for e in curr.edges.values():
                if e.to not in searched:
                    queue.append((e.to, curr, e.weight))
                    searched.add(e.to)

        path: Path = []

        if found:
            path = [(goal.key, _from[goal][1])]
            path_curr, _ = _from[goal]
            while path_curr is not None:
                path.append((path_curr.key, _from[path_curr][1]))
                path_curr, _ = _from[path_curr]

        return path[::-1] if path else None

    def Dijkstra(self, A: T, B: T) -> Optional[list[T]]:
        # TODO
        raise NotImplementedError("Dijkstra search impossible")
