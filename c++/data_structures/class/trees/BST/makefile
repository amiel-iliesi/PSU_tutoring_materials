CC=g++
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror

tree: tree.cpp main.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f tree *.o
