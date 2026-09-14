CC=g++
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=list

$(EXEC): list.cpp main.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
