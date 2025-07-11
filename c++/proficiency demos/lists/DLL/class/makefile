CC=g++
VERSION=-std=c++20
CFLAGS=$(VERSION) -g -Wall -Wextra -Wpedantic -Werror

proficiency: main.cpp functions.cpp DLL.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf proficiency *.o *.out
