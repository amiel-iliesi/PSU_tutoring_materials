CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=scope_resolution

exec_full=$(EXEC).out

$(exec_full):main.cpp store.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
