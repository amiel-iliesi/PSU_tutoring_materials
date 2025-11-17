CC=g++
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow
EXEC=forgot_to_dealloc

$(EXEC): functions.cpp main.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
