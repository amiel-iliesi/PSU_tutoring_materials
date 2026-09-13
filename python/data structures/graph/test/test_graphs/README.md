# Test Graphs

These are graphs with unique setups and properties to be used in testing. They
should be larger in scale to test more edge cases.

## Descriptions

### `large_lattice_random_weights`

This graph is 100x100 evenly spaced cartesian points connected to their up and
right adjacent neighbors. Their weights are between `(0, 5] +
distance_from_diagonal`. This is to test the Dijkstra property. Because the
diagonal is weighted lower than the distant corners from the goal, A* and
Dijkstra should be very similar.
