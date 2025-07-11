CC=g++
MODE=-g
VERSION=-std=c++23
ERRORS=-Wall -Wextra -Wpedantic -Werror
CFLAGS=$(MODE) $(VERSION) $(ERRORS)

.PHONY: clean

program: main.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $<

stack.o: stack.cpp stack.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o program
