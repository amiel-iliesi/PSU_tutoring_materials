from search import SearchGraph
from random import randint, uniform
from typing import Any

if __name__ == "__main__":
    graph = SearchGraph[int]()

    # NOTE: tweak these
    SIZE = 100
    CONNECTIONS_MIN = 0
    CONNECTIONS_MAX = 4
    WEIGHTED = True
    WEIGHT_MIN = 0.0
    WEIGHT_MAX = 1.0
    BIDIRECTIONAL = False
    PRINT_GRAPH = True
    ALGOS = (graph.DFS, graph.BFS)

    for i in range(SIZE):
        graph.create_vertex(i)

    for i in range(SIZE):
        n_connections = randint(CONNECTIONS_MIN, CONNECTIONS_MAX)

        # if bidirectional, might already have connections
        inserted = len(graph.vertices[i].edges)
        while inserted < n_connections:
            x = randint(0, SIZE-1)
            already_connected, _ = graph.connection(i, x)
            if already_connected:
                continue
            else:
                w = uniform(WEIGHT_MIN, WEIGHT_MAX) if WEIGHTED else None
                graph.connect(i, x, w, BIDIRECTIONAL)
                inserted += 1

    if PRINT_GRAPH:
        print(graph)

    a, b = 0, SIZE-1
    for algo in ALGOS:
        path = algo(a, b)

        weight_sum: Any = None

        if path is not None:
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
