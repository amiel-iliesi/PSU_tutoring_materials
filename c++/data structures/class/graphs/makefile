CC=g++ -std=c++20
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=graph

$(EXEC): graph.cpp main.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
