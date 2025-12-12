from __future__ import annotations
from typing import TypeVar, Generic, Optional, Any
from dataclasses import dataclass

T = TypeVar('T')


@dataclass
class _Edge(Generic[T]):
    to: _Vertex
    weight: Optional[Any] = None

    def __repr__(self):
        return f'_Edge(to={repr(self.to.key)}, weight={repr(self.weight)})'


class _Vertex(Generic[T]):
    def __init__(self, key: T, data: Optional[Any] = None):
        super().__init__()

        self.key: T = key
        self.data: Optional[Any] = data
        self.edges: dict[T, _Edge] = {}

    def __str__(self) -> str:
        s = str(self.key)

        if self.data is not None:
            s += f'({self.data})'

        if self.edges:
            s += f': {','.join(
                f'{e.to.key}({e.weight})' if e.weight is not None
                else f'{e.to.key}'
                for e in self.edges.values())}'

        return s

    def __repr__(self) -> str:
        return f'_Vertex(key={repr(self.key)}, data={repr(self.data)}' +\
            f', edges=[{','.join(repr(e) for e in self.edges.values())}]'

    def __eq__(self, value) -> bool:
        return self.key == value

    def __hash__(self) -> int:
        return hash(self.key)

    def connect(self, to: '_Vertex', weight: Optional[Any]) -> None:
        self.edges[to.key] = _Edge(to, weight)

    def disconnect(self, key: T) -> None:
        del self.edges[key]

    def connected(self, key: T) -> bool:
        return key in self.edges

    def connection(self, key: T) -> tuple[bool, Optional[Any]]:
        '''Gets connection info to `key`.

        **arguments**:

        `key`: edge to search for.

        **returns**:

        `(`connection exists, associated weight or `None` if unweighted`)`'''
        c = self.connected(key)
        return (c, self.edges[key].weight if c else None)


class Graph(Generic[T]):
    '''Generalized graph data structure.'''

    def __init__(self) -> None:
        super().__init__()

        self.vertices: dict[T, _Vertex[T]] = {}

    def __str__(self) -> str:
        return 'Graph {\n' +\
            ',\n'.join(str(v) for v in self.vertices.values()) +\
            '\n}'

    def __repr__(self) -> str:
        vertices = ','.join(repr(v) for v in self.vertices.values())
        return f'Graph(vertices={vertices})'

    def create_vertex(self, key: T, data: Optional[Any] = None) -> None:
        '''Creates a vertex in the graph.

        **arguments**:

        `key`: The vertex key.

        `data`: Optional data to attach to the vertex, EG: a label.

        **raises**:

        `KeyError`: If a vertex already exists with the same key.'''

        if key in self.vertices:
            raise KeyError(f'{key} already exists in the graph')

        self.vertices[key] = _Vertex(key, data)

    def remove_vertex(self, key: T) -> None:
        '''Removes a vertex from the graph.

        **arguments**:

        `key`: Vertex to be removed from the graph.

        **raises**:

        `KeyError`: If the requested vertex does not exist in the graph.'''

        if key not in self.vertices:
            raise KeyError(f'{key} is not in the graph')

        # first remove all references to the key in edges
        for vertex in self.vertices.values():
            if vertex.connected(key):
                vertex.disconnect(key)

        del self.vertices[key]

    def connect(self,
                A: T,
                B: T,
                weight: Optional[Any] = None,
                bidirectional: bool = False) -> None:
        '''Connects `A`→`B` with the given weight.

        **arguments**:

        `A`: vertex **FROM** by key.

        `B`: vertex **TO** by key.

        `weight`: optional value to attach to the connection.

        `bidirectional`: also connects `B`→`A` with the same weight.

        **raises**:

        `KeyError`: If `A` or `B` don't exist.

        `ValueError`: Raised if `A` and `B` are already connected.'''

        for key in (A, B):
            if key not in self.vertices:
                raise KeyError(f'{key} is not in the graph')

        va = self.vertices[A]
        vb = self.vertices[B]

        if va.connected(B):
            raise ValueError(f'{A}→{B}: already connected')
        if bidirectional and vb.connected(A):
            raise ValueError(f'{B}→{A}: already connected')

        va.connect(vb, weight)

        if bidirectional:
            vb.connect(va, weight)

    def disconnect(self,
                   A: T,
                   B: T,
                   bidirectional: bool = False) -> None:
        '''Disconnects `A`→`B`.

        **arguments**:

        `A`: vertex **FROM** by key.

        `B`: vertex **TO** by key.

        `bidirectional`: also disconnects `B`→`A`.

        **raises**:

        `KeyError`: If `A` or `B` don't exist.

        `ValueError`: Raised if `A` and `B` are not connected.'''
        for key in (A, B):
            if key not in self.vertices:
                raise KeyError(f'{key} is not in the graph')

        va = self.vertices[A]
        vb = self.vertices[B]

        if not va.connected(B):
            raise ValueError(f'{A}↛{B}: not connected')
        if bidirectional and not vb.connected(A):
            raise ValueError(f'{B}↛{A}: not connected')

        va.disconnect(B)

        if bidirectional:
            vb.disconnect(A)

    def connection(self, A: T, B: T) -> tuple[bool, Optional[Any]]:
        '''Gets connection info of `A`→`B`.

        **arguments**:

        `A`: start of edge.

        `B`: end of edge.

        **returns**:

        `(`connection exists, associated weight or `None` if unweighted`)`

        **raises**:

        `KeyError`: if `A` or `B` are not in the graph.'''

        for key in (A, B):
            if key not in self.vertices:
                raise KeyError(f'{key} is not in the graph')

        return self.vertices[A].connection(B)
