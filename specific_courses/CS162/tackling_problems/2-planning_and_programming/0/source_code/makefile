CC=g++ -std=c++23
CFLAGS=-g -Wall -Wextra -Wpedantic -Wshadow -Werror -fmax-errors=5
EXEC=track_db

exec_full=$(EXEC).out

$(exec_full):main.cpp tracklist.cpp track_data.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o $(exec_full)
