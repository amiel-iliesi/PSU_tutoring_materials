CC=g++
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=stack

$(EXEC): main.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
