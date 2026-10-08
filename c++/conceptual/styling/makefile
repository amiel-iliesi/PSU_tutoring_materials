CC=g++
CFLAGS=-Wall -Wextra -g

all: easy hard

easy: easy2read.cpp prime.cpp prime.h
	$(CC) $(CFLAGS) -o $@ easy2read.cpp prime.cpp

hard: hard2read.cpp
	$(CC) $(CFLAGS) -o $@ hard2read.cpp

.PHONY: clean
clean:
	rm -f easy hard
