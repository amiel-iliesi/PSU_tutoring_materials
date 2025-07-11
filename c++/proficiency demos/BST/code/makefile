CC=g++
CVER=-std=c++20
CFLAGS=$(CVER) -g -Wall -Wextra -Wpedantic -Werror

BST: main.cpp BST.cpp functions.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf BST *.o
