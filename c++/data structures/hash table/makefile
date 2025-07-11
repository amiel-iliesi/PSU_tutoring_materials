CC=g++
COMPILE_MODE=-g
CFLAGS=$(COMPILE_MODE) -Wall -Wextra -Wpedantic

program: main.cpp hashtable.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f program *.o
