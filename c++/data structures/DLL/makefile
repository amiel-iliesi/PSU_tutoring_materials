CC=g++
MODE=-g
WARNINGS=-Wall -Wextra -Wpedantic -Werror
CFLAGS=$(MODE) $(WARNINGS)

.PHONY: clean

program: main.o list.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $<

list.o: list.cpp list.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o program
