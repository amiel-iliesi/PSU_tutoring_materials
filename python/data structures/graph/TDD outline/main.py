'''Example usage of the graph in a practical setting.'''

from graph import Graph

if __name__ == '__main__':
    graph = Graph()

    graph.create_vertex('A')
    graph.create_vertex('B')
    graph.create_vertex('C')

    graph.connect('A', 'B', weight=1.0, bidirectional=True)
    graph.connect('B', 'C', weight=None)

    graph.from_json(graph.to_json())
