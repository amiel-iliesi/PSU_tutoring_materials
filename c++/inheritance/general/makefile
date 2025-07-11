CC=g++
WARNINGS=-Wall -Wextra -Wshadow -Wunreachable-code -Wredundant-decls \
		 -Wmissing-declarations -Wno-return-local-addr \
		 -Wunsafe-loop-optimizations -Wuninitialized -Werror \
         -Wno-unused-parameter -Wno-string-compare -Wno-stringop-overflow \
         -Wno-stringop-overread -Wno-stringop-truncation
COMPILER_ERR_LIMIT=-fmax-errors=5
COMPILE_MODE=-g
CFLAGS = $(COMPILE_MODE) $(WARNINGS) $(COMPILER_ERR_LIMIT)

EXECUTABLES=inheritance_program

inheritance_program: main.cpp classes.cpp list.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o $(EXECUTABLES) 
