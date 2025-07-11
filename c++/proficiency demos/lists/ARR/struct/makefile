CC=g++
VER=-std=c++20
FLAGS=$(VER) -g -Wall -Wextra -Wpedantic -Werror

ARR: main.cpp ARR.cpp
	$(CC) $(FLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf ARR *.o
