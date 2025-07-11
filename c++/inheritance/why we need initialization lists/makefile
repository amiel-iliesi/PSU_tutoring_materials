CC=g++
COMPILER_ERR_LIMIT=-fmax-errors=5
COMPILE_MODE=-g
CFLAGS = $(COMPILE_MODE) $(WARNINGS) $(COMPILER_ERR_LIMIT)

EXECUTABLES=inheritance

inheritance: main.cpp classes.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o $(EXECUTABLES) 
