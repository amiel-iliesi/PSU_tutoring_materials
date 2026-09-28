# Graph

## Summary

This is an implementation of a generic graph that supports many popular graph
functions and modes of operation, including: unidirectional, bidirectional,
weighted, and unweighted graphs. There are also various algorithm
implementations.

## Install

By using the `pip`
[VCS option](https://pip.pypa.io/en/stable/topics/vcs-support/#url-fragments),
you can directly install the graph into whatever environment you're using.

Here's the command you can just copy:

```bash
pip install "graph @ git+https://github.com/amiel-iliesi/PSU_tutoring_materials.git#subdirectory=python/data_structures/graph"
```

## Directory Structure

* `graph/src/graph/`: Implementation files.
* `graph/test/`: pytest cases.

## Overview and Outline

The graph is a basic implementation of a node graph. It accept generic type, and implements several search algorithms over the nodes. All that is required is that the type is comparable on **equality**. If you need a more complicated equality comparison, wrap your object in a class that defines it for your type. For an example of this equality overriding, look at the definition of the `Point` type in: `graph/src/graph/graph_types.py`.

The graph is represented as follows:

* `Graph`: A dictionary of keys to vertices.
* `Vertex`: A bundled key, and list of edges.
* `Edge`: A destination vertex, and an optional float weight.

The whole project is typed according to [PEP 484](https://peps.python.org/pep-0484/) and has been verified with [MyPy](https://mypy.readthedocs.io/en/stable/)--specifically the Microsoft implementation of the [MyPy VSCode Extension](https://marketplace.visualstudio.com/items?itemName=ms-python.mypy-type-checker). This should make the repository more readable through [VSCode's Intellisense](https://code.visualstudio.com/docs/editing/intellisense), in addition to being generally more type-safe in its implementation.

## Basic Usage

After installing the graph, the basic usage is just to construct a basic graph, and start adding some points, like so:

```py
graph = Graph()

graph.create_vertex('A')
graph.create_vertex('B')
graph.create_vertex('C')

graph.connect('A', 'B')
graph.connect('B', 'C')
graph.connect('C', 'A')
```

Then once the graph is constructed, you're able to run some algorithms on the graph as a whole, or query the graph for specific vertices, like so:

```py
print('D ' + ('is' if 'D' in graph.vertices else 'is not') + ' in the graph.')

print(f'Graph has {len(graph)} vertices.')

path = graph.path('A', 'C', method=Search.BFS)

print(f'A reaches C?: {Graph.reaches(path, 'C')}.')

print(Graph.path_pretty(path))
```

One point of consideration is, if you wish to use the **Dijkstra** or **A\*** searches, you will need to have weights on your edges, as a weight of `None` will be treated as un-traversable (which is different than a weight of `0.0`, which has no resistance along the path). Functionally, a weight of `None` is similar to a weight of `infinity`. Additionally, if you want to use **A\***, you will need to supply a [heuristic function](https://en.wikipedia.org/wiki/Heuristic_(computer_science)). To see an example of this, check out the example graph in `graph/main.py`.