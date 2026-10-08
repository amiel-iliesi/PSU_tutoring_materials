CC=g++
WARNING=-Wall -Wextra -Wshadow -Wunreachable-code -Wredundant-decls \
		-Wmissing-declarations -Wno-return-local-addr \
		-Wunsafe-loop-optimizations -Wuninitialized -Werror \
        -Wno-unused-parameter -Wno-string-compare -Wno-stringop-overflow \
        -Wno-stringop-overread -Wno-stringop-truncation
COMPILER_ERR_LIMIT=-fmax-errors=5
COMPILE_MODE=-g
CFLAGS = $(COMPILE_MODE) $(WARNINGS) $(COMPILER_ERR_LIMIT)

EXECUTABLES=program

.PHONY: clean

program: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp list.h list.tpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXECUTABLES) 
