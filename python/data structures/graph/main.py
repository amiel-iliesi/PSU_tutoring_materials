'''Example usage of the graph in a practical setting.'''

from graph import Graph
from graph_types import Point
import pickle

if __name__ == '__main__':
    graph: Graph

    with open('example_graphs/3_weighted_lattice.pickle', mode='rb') as f:
        graph = pickle.load(f)

    print(Graph.pretty_path(graph.path(Point(0, 0), Point(5, 5))))
