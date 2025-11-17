# Running Valgrind

```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -s <FILE_TO_RUN>
```

Normally valgrind runs with fewer options so that its default behavior is fast
running time and covering most common bases. We enable more options above to
make finding our error easier. The options are listed above for convenience.

[Source](https://valgrind.org/docs/manual/mc-manual.html#mc-manual.options).
