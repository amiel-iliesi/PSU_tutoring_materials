CC=g++
MODE=-g -O0
CFLAGS=-Wall -Wextra -Werror $(MODE)
EXECUTABLES=BST

.PHONY: clean

BST: main.cpp BST.cpp 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f *.o $(EXECUTABLES)
