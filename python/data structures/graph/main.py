'''Example usage of the graph in a practical setting.'''

from graph import Graph, Point
import pickle

if __name__ == '__main__':
    graph: Graph

    FOLDER = 'test/test_graphs'
    GRAPH = 'large_lattice_random_weights'

    with open(f'{FOLDER}/{GRAPH}.pickle', 'rb') as f:
        graph = pickle.load(f)

    print(graph[Point(0, 0)])
