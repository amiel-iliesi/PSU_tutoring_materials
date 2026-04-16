CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=menu

exec_full=$(EXEC).out

$(exec_full): menu.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
