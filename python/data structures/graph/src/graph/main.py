'''Example usage of the graph in a practical setting.'''

from graph.graph import Graph, Search
from graph.graph_types import Point
import pickle

if __name__ == '__main__':
    graph: Graph

    with open('example_graphs/3_weighted_lattice.pickle', mode='rb') as f:
        graph = pickle.load(f)

    path = graph.path(Point(0, 0), Point(5, 5), method=Search.BFS)

    print(Graph.pretty_path(path))
