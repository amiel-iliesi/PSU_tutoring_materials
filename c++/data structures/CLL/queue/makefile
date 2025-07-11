CC=g++
CFLAGS=-Wall -Wextra -Wpedantic -Werror -g

program: main.o queue.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $<

queue.o: queue.cpp queue.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o program
