'''Example usage of the graph in a practical setting.'''

from graph import Graph, Search
import pickle

if __name__ == '__main__':
    graph: Graph

    FOLDER = 'example_graphs'
    GRAPH = '2_bidirectional_and_cycles'

    with open(f'{FOLDER}/{GRAPH}.pickle', mode='rb') as f:
        graph = pickle.load(f)

    path = graph.path('a', 'e', method=Search.BFS)

    print(Graph.pretty_path(path))
