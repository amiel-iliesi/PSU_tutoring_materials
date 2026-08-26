from __future__ import annotations
from typing import TypeVar, Generic, Optional, Any, Callable
from enum import Enum

T = TypeVar('T')


class Edge:
    '''Represents the edge that connects two vertices. Source vertex is left
    absent, as `Edges` are held by their source `Vertex`, so the information
    is always present to the composing `Vertex` class.'''

    def __init__(self,
                 destination: Vertex,
                 weight: Optional[float] = None) -> None:
        self.destination = destination
        self.weight = weight


class Vertex(Generic[T]):
    '''Represents a point/node in the graph. Can connect to other vertices of
    varying types via edges.'''

    def __init__(self) -> None:
        super().__init__()

        self.key: T
        self.edges: list[Edge] = []
        # TODO: include other attributes, like label, or aux data?

    def __eq__(self, value: Any) -> bool:
        try:
            return self.key == value  # default behavior, compare on key
        except Exception:
            return False


class Search(Enum):
    '''Enum listing graph search options for user selection.'''
    DFS = 1
    BFS = 2
    DIJKSTRA = 3
    A_STAR = 4


Path = list[tuple[Vertex[Any], Edge]]


class Graph:
    '''Represents an arbitrary network of vertices. Supports weighted edges,
    and implements various graph traversal algorithms.'''

    def __init__(self) -> None:
        super().__init__()

        self.vertices: list[Vertex] = []

    def create_vertex(self,
                      key: Any,
                      comp: Optional[Callable[[Any, Any], bool]] = None
                      ) -> bool:
        '''Creates a `Vertex` with the given `key`. Can fail if insertion would
        result in a duplicate `Vertex` entry in the graph. Vertices can be of
        any type--including varying types within the graph. Searches and
        propagation are done with **equality** as the test. Errors thrown by
        incompatibility for equality are ignored and treated as falsy--since
        being that they are of incompatible types, they are surely unequal in
        value. A comparison function can be substituted if the basic equality
        comparison is insufficient--raised errors are still ignored in this
        case.

        ### arguments
        * `key`: key value to create `Vertex` with.
        * `comp`: optional comparison function for more nuanced comparison.
        Left as `None`, equality will be used between key pairs.

        ### returns
        Success status of `Vertex` creation.'''
        raise NotImplementedError

    def remove_vertex(self,
                      key: Any,
                      comp: Optional[Callable[[Any, Any], bool]] = None
                      ) -> bool:
        '''Removes all given vertices from the graph that match the `key`.

        ### arguments
        * `key`: value to match for.
        * `comp` optional comparison function for more nuanced comparison.
        Left as `None`, quality will be used between key pairs.

        ### returns
        Number of vertices removed.'''
        raise NotImplementedError

    def connect(self,
                source: Any,
                destination: Any,
                weight: Optional[float] = None,
                bidirectional: bool = False) -> None:
        '''Establish an `Edge` via `source -> destination`. If either the
        `source` or `destination` are missing, a `KeyError` will be raised to
        prevent silent errors from propagating. If an edge already exists from
        `source -> destination`, then the edge(s) will be updated according to
        `weight` and if the connection is `bidirectional`.

        ### arguments
        * `source`: beginning `Vertex`.
        * `destination`: ending `Vertex`.
        * `weight`: an optional weight component for the resulting edge. EG:
        in traversal algorithms, a lower weight implies easier traversal
        between two vertices.
        * `bidirectional`: apply the same connection in the reverse direction,
        as well?

        ### raises
        * `KeyError`: if either `source` or `destination` are not present in
        the graph.'''
        raise NotImplementedError

    def disconnect(self,
                   source: Any,
                   destination: Any,
                   bidirectionally: bool = False) -> None:
        '''Removes the `Edge` from `source -> destination`. If either `source`
        or `destination` are missing, a `KeyError` will be thrown to prevent
        silent errors from propagating. If the edge `source -> destination` is
        already absent, then the disconnect call is a no-op.

        ### arguments
        * `source`: beginning `Vertex`.
        * `destination`: ending `Vertex`.
        * `bidirectional`: disconnect the reverse directional edge, as well?

        ### raises
        * `KeyError`: if either `source` or `destination` are not present in
        the graph.'''
        raise NotImplementedError

    def clear(self) -> None:
        '''Clears all `Vertices` and consequently `Edges` from the graph.'''
        raise NotImplementedError

    def path(self, method: Search = Search.DFS) -> Path:
        raise NotImplementedError
