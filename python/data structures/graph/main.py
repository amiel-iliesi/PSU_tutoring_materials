'''Example usage of the graph in a practical setting.'''

from graph import Graph, Point, Search
import pickle
from pathlib import Path
from functools import partial
from typing import Callable, Any

if __name__ == '__main__':
    graph: Graph

    BASEPATH = Path(__file__).parent / 'test/test_graphs'
    GRAPH_FILE = 'large_lattice_random_weights.pickle'

    SOURCE = Point(0, 0)
    DESTINATION = Point(99, 99)

    with open(BASEPATH / GRAPH_FILE, 'rb') as f:
        graph = pickle.load(f)

    print(f'Graph of size={len(graph)}:')

    def dest_dist() -> Callable[[Any], float]:
        return partial(Point.distance, b=DESTINATION)

    path = graph.path(SOURCE,
                      DESTINATION,
                      method=Search.A_STAR,
                      heuristic=dest_dist())

    print('A* path:')
    print(','.join(str(p) for p in Graph.path_list(path)))

    for search in Search:
        path = graph.path(SOURCE,
                          DESTINATION,
                          method=search,
                          heuristic=dest_dist())

        print(f'Path found using {search.name} with '
              f'weight={Graph.path_weight(path)}')
