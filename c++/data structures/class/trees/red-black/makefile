CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror
EXEC=tree

exec_full=$(EXEC).out

$(exec_full): main.cpp tree.tpp tree.h
	$(CC) $(CFLAGS) main.cpp -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
