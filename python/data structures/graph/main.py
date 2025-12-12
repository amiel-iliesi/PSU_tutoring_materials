from search import SearchGraph
from random import randint
from typing import Any
from coord import Coord

if __name__ == "__main__":
    graph = SearchGraph[Coord]()

    # NOTE: tweak these
    GRID_SIZE = 10  # NxN square
    CONNECTIONS_MIN = 0
    CONNECTIONS_MAX = 4
    WEIGHTED = True
    BIDIRECTIONAL = False
    PRINT_GRAPH = True
    ALGOS = (graph.DFS, graph.BFS)

    for x in range(GRID_SIZE):
        for y in range(GRID_SIZE):
            graph.create_vertex(Coord(x, y))

    for x in range(GRID_SIZE):
        for y in range(GRID_SIZE):
            n_connections = randint(CONNECTIONS_MIN, CONNECTIONS_MAX)

            # if bidirectional, might already have connections
            inserted = len(graph.vertices[Coord(x, y)].edges)
            while inserted < n_connections:
                new_x = randint(0, GRID_SIZE-1)
                new_y = randint(0, GRID_SIZE-1)
                curr = Coord(x, y)
                new = Coord(new_x, new_y)
                already_connected, _ = graph.connection(curr, new)
                if already_connected:
                    continue
                else:
                    w = curr.dist(new)
                    graph.connect(curr, new, w, BIDIRECTIONAL)
                    inserted += 1

    if PRINT_GRAPH:
        print(graph)

    a, b = Coord(0, 0), Coord(GRID_SIZE-1, GRID_SIZE-1)
    path_exists = True
    for algo in ALGOS:
        path = algo(a, b)

        if path is None:
            path_exists = False
            break  # if one algorithm doesn't yield results, none of them will

        weight_sum: Any = None

        for _, weight in path:
            if weight is not None:
                if weight_sum is None:
                    weight_sum = weight
                else:
                    weight_sum += weight

        path_result = f'{algo.__name__}'

        if weight_sum is not None:
            path_result += f'(total={weight_sum:.3f})'

        path_result += f': {a}→{b}: '

        path_result += ('→'.join(f'{p}{f"({w:.3f})" if w is not None else ''}'
                                 for p, w in path)
                        if path is not None else str(None))

        print(path_result)

    if not path_exists:
        print(f'{a}→{b}: DNE')
