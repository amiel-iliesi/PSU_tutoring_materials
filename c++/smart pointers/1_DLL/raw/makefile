CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=list

exec_full=$(EXEC).out

$(exec_full): main.cpp list.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
