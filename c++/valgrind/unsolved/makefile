CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror -fmax-errors=2
EXEC=books

$(EXEC): main.cpp reader.cpp booklist.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
