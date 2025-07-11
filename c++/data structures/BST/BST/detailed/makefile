CC=g++
CFLAGS=-Wall -Wextra -Werror -O2 -g -std=c++20
EXECUTABLES=main BST
TAR_FILE=BST.tar.gz

.PHONY: test tar clean

BST: main.cpp BST.cpp 
	$(CC) $(CFLAGS) -o $@ $^

test: BST_test.cpp BST.cpp
	@$(CC) $(CFLAGS) -DBST_TEST -o test $^
	@./test
	@rm test

tar:
	tar -cvaf $(TAR_FILE) *.cpp *.h makefile

clean:
	@rm -f *.o $(EXECUTABLES) $(TAR_FILE)
