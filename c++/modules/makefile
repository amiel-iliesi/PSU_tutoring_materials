CC=g++
CFLAGS=-std=c++20 -fmodules-ts -g -Wall -Wextra -Wpedantic -Werror

.PHONY: all clean

all: include module

include: main_include.cpp my_function_include.cpp my_function_include.h
	$(CC) $(CFLAGS) -o $@ main_include.cpp my_function_include.cpp

module: main_module.o my_function_module.o
	$(CC) $(CFLAGS) -o $@ main_module.o my_function_module.o

main_module.o: main_module.cpp my_function_module.o
	$(CC) $(CFLAGS) -c $<

my_function_module.o: my_function_module.cpp gcm.cache
	$(CC) $(CFLAGS) -c $<

gcm.cache: my_function_module.cpp
	$(CC) $(CFLAGS) -x c++-system-header iostream

clean:
	rm -Rf *.o include module gcm.cache
