'''Module containing various graphing classes and algorithm utilities.'''

from __future__ import annotations
from typing import TypeVar, Generic, Optional, Any
from enum import Enum
import json

T = TypeVar('T')


class Edge:
    '''Represents the edge that connects two vertices. Source vertex is left
    absent, as `Edges` are held by their source `Vertex`, so the information
    is always present to the composing `Vertex` class.'''

    def __init__(self,
                 destination: Vertex[Any],
                 weight: Optional[float] = None) -> None:
        self.destination = destination
        self.weight = weight

    def to_json(self) -> str:
        return f'{{"destination": {id(self.destination)}, ' +\
            f'"weight": {self.weight if self.weight is not None else 'null'}}}'


class Vertex(Generic[T]):
    '''Represents a point/node in the graph. Can connect to other vertices of
    varying types via edges. Ensure that equality is properly supported for
    your key type.'''

    def __init__(self, key: T) -> None:
        super().__init__()

        self.key: T = key
        self.edges: list[Edge] = []

    def __repr__(self) -> str:
        return f'Vertex(key={repr(self.key)}, ' +\
            f'edges=[{','.join(str(edge) for edge in self.edges)}])'

    def __eq__(self, value: Any) -> bool:
        try:
            # default behavior, compare on key
            if isinstance(value, Vertex):
                return self.key == value.key
            else:
                return self.key == value
        except Exception:
            return False

    def connected(self, destination: Any) -> bool:
        '''Returns whether or not the vertex is connected to the
        destination.'''
        return any(destination == edge.destination for edge in self.edges)

    def get_weight(self, destination: Any) -> Optional[float]:
        for edge in self.edges:
            if edge.destination == destination:
                return edge.weight

        raise KeyError(f'{repr(self)} has no edge to {destination}')

    def to_json(self) -> str:
        return '{' +\
            f'"id": {id(self)}, ' +\
            f'"key": "{repr(self.key)}", ' +\
            f'"edges": [{', '.join(edge.to_json() for edge in self.edges)}]' +\
            '}'


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

        self.vertices: dict[Any, Vertex[Any]] = {}

    @staticmethod
    def reaches(destination: Any, path: Path) -> bool:
        '''Checks if a destination is reachable on the given path.

        ### arguments
        * `destination`: destination to find in the path.
        * `path`: a completed path from `Graph.path(...).

        ### returns
        A boolean indicating whether or not the destination was found.'''
        return any(edge.destination == destination for _, edge in path)

    def create_vertex(self, key: Any) -> bool:
        '''Creates a `Vertex` with the given `key`. Can fail if insertion would
        result in a duplicate `Vertex` entry in the graph. Vertices can be of
        any type--including varying types within the graph. Searches and
        propagation are done with **equality** as the test. Errors thrown by
        incompatibility for equality are ignored and treated as falsy--since
        being that they are of incompatible types, they are surely unequal in
        value.

        ### arguments
        * `key`: key value to create `Vertex` with.

        ### returns
        Success status of `Vertex` creation.'''
        if self.vertices.get(key) is not None:
            return False

        self.vertices[key] = Vertex(key)
        return True

    def remove_vertex(self, key: Any) -> bool:
        '''Removes all given vertices from the graph that match the `key`.

        ### arguments
        * `key`: value to match for.

        ### returns
        If a vertex was removed.'''
        if self.vertices.get(key) is None:
            return False

        del self.vertices[key]
        return True

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
        source_vertex = self.vertices.get(source)
        destination_vertex = self.vertices.get(destination)

        if source_vertex is None:
            raise KeyError(f'{source} is not in the graph')

        if destination_vertex is None:
            raise KeyError(f'{destination} is not in the graph')

        def _connect(_source: Vertex[Any],
                     _destination: Vertex[Any],
                     weight: Optional[float]) -> None:
            '''Unidirectional connection for re-use in bidirectional
            connection.'''
            updated = False
            for edge in _source.edges:
                if edge.destination == _destination:
                    edge.weight = weight
                    updated = True
                    break

            if not updated:
                _source.edges.append(Edge(_destination, weight))

        _connect(source_vertex, destination_vertex, weight)

        if bidirectional:
            _connect(destination_vertex, source_vertex, weight)

    def disconnect(self,
                   source: Any,
                   destination: Any,
                   bidirectional: bool = False) -> None:
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
        source_vertex = self.vertices.get(source)
        destination_vertex = self.vertices.get(destination)

        if source_vertex is None:
            raise KeyError(f'{source} is not in the graph')

        if destination_vertex is None:
            raise KeyError(f'{destination} is not in the graph')

        def _disconnect(_source: Vertex[Any],
                        _destination: Vertex[Any]) -> None:
            '''Unidirectional disconnection for re-use in bidirectional
            connection.'''
            for index, edge in enumerate(_source.edges):
                if edge.destination == _destination:
                    del _source.edges[index]

        _disconnect(source_vertex, destination_vertex)

        if bidirectional:
            _disconnect(destination_vertex, source_vertex)

    def clear(self) -> None:
        '''Clears all `Vertices` and consequently `Edges` from the graph.'''
        self.vertices.clear()

    def to_json(self) -> str:
        return '{"vertices": [' +\
            ','.join(vertex.to_json() for vertex in self.vertices.values()) +\
            ']}'

    def from_json(self, json_data: str) -> None:
        data = json.loads(json_data)

        vertex_table: dict[int, Vertex[Any]] = {}

        for vertex in data['vertices']:
            vertex_table[vertex['id']] = Vertex(eval(vertex['key']))

        self.vertices = {vertex.key: vertex
                         for vertex in vertex_table.values()}

        for vertex in data['vertices']:
            key = eval(vertex['key'])
            for edge in vertex['edges']:
                destination = vertex_table[edge['destination']]
                self.connect(key, destination.key, edge['weight'])

    def path(self,
             source: Any,
             destination: Any,
             method: Search = Search.DFS) -> Path:
        raise NotImplementedError
