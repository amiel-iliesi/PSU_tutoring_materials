# Extra Commands

Here's a table with some additional commands that might be useful:

**Note**: parts of commands in [square brackets] are optional, for the full
name of the command.

| command                       | description                                                                         |
| ----------------------------- | ----------------------------------------------------------------------------------- |
| `fin[ish]`                    | Finish current call, and print out the result.                                      |
| `*p[rint] a@n`                | Print out array `a`, with `n` elements.                                             |
| `b[ack]t[race] <full>`        | Like a regular backtrace, but with local variable info.                             |
| `b[reak] <where> {if <cond>}` | Break can have conditions to break. Conditions are written like a C/C++ expression. |
| `call <func>`                 | Call any function. Can even be an object's function, like `call list.display()`.    |
