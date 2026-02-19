CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=error

exec_full=$(EXEC).out

$(exec_full): error.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
