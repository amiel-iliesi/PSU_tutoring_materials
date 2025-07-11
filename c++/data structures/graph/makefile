CC=g++
CFLAGS=-g -std=c++20 -Wall -Wextra -Wpedantic

.PHONY: clean

graph: main.cpp graph.h graph.tpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f graph
