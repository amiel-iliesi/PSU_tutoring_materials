# TODO
* Remove JSON implementations (they are brittle, unsafe, and unused; opted for
`pickle`). Either refactor to allow the omission of the usage of `eval`, or
just remove the functions.

* Cumulative weight is improperly stored in the Dijkstra Element dataclass in
the A* pathing function; the heuristic should not be included in the cumulative
weight.

* Seperate search, and graph model into seperate files in the `src/graph/`
directory. They are distinct in function, they should be seperated.

* The `Path` type could benefit from being made into a class, so it has named
members, and is less opaque in it's usage. This would require a refactor across
all its usages though.

* The `pyproject.toml` would be better set-up if the testing tooling was less
coupled. It should be included in a seperate dev section, as an optional
dependancy. The toolings should also have their options specified, like setting
the `mypy` and `pytest` options.

* The project should probably be less ambiguously named, to avoid potential
conflict. `graph` as a name is pretty generic, maybe something like `psu-graph`
or `node-graph` or something along those lines. This would avoid naming
conflict in PyPi, or in the user's installation space.
