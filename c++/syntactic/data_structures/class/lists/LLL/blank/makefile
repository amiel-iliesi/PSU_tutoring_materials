CC=g++
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror

list: list.cpp main.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f list *.o
