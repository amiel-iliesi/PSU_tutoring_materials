CC=g++ -std=c++20
WARNINGS=-Wall -Wextra -Wshadow -Wunreachable-code -Wredundant-decls \
		 -Wmissing-declarations -Wno-return-local-addr \
		 -Wunsafe-loop-optimizations -Wuninitialized -Werror \
         -Wno-unused-parameter -Wno-string-compare -Wno-stringop-overflow \
         -Wno-stringop-overread -Wno-stringop-truncation
COMPILER_ERR_LIMIT=-fmax-errors=5
COMPILE_MODE=-g
CFLAGS = $(COMPILE_MODE) $(WARNINGS) $(COMPILER_ERR_LIMIT)
MEMCHECK=valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s 
RUN_MEMCHECK=$(MEMCHECK)

EXECUTABLES=program tests

.PHONY: clean run_tests build_tests

program: main.o tree.o
	@$(CC) $(CFLAGS) -o $@ $^

run_tests:
	$(MAKE) clean
	$(MAKE) build_tests
	$(RUN_MEMCHECK)./tests
	$(MAKE) clean

build_tests: tests

tests: tests.o tree.o
	@$(CC) $(CFLAGS) -o $@ $^

tests.o: tests.cpp tree.h
	@$(CC) $(CFLAGS) -DDEBUG_TEST_TREE_INTEGRITY -c $<

main.o: main.cpp tree.h
	@$(CC) $(CFLAGS) -c $<

tree.o: tree.cpp tree.h
	@$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXECUTABLES) 
