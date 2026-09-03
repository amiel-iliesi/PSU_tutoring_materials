'''Example usage of the graph in a practical setting.'''

from graph import Graph, Search

if __name__ == '__main__':
    graph = Graph()

    with open('example_graphs/2_bidirectional_and_cycles.json', mode='r') as f:
        graph.from_json(f.read())

    print(Graph.pretty_path(graph.path('a', 'e')))
