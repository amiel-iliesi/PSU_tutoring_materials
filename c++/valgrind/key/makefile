CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=books

exec_full=$(EXEC).out

$(exec_full): main.cpp reader.cpp booklist.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
