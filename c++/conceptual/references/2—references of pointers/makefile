CC=g++
MODE=-g -O0
CFLAGS=-Wall -Wextra -Werror $(MODE)

list: linkedlist.cpp main.cpp 
	$(CC) $(CFLAGS) $^ -o $@



.PHONY: clean

clean:
	rm -f *.out *.o list
