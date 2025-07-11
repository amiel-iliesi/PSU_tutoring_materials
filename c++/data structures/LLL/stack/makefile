CC=g++
MODES=-g
WARNINGS=-Wall -Wextra -Wpedantic -Werror
CFLAGS=$(MODES) $(WARNINGS)

.PHONY: clean

program: list.o main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^

list.o: list.cpp list.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
