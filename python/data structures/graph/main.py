'''Example usage of the graph in a practical setting.'''

from graph import Graph, Point, Search
import pickle
from pathlib import Path

if __name__ == '__main__':
    graph: Graph

    BASEPATH = Path(__file__).parent / 'test/test_graphs'
    GRAPH_FILE = 'large_lattice_random_weights.pickle'

    with open(BASEPATH / GRAPH_FILE, 'rb') as f:
        graph = pickle.load(f)

    print(f'Graph of size={len(graph)}:')

    for search in (Search.DFS, Search.BFS, Search.DIJKSTRA):
        path = graph.path(Point(0, 0), Point(99, 99), method=search)

        print(f'Path found using {search.name} with '
              f'weight={Graph.path_weight(path)}')
