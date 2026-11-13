#include "type.h"
#include "hash.h"

#include <print>
#include <vector>

int main()
{
	HashTable table(7);
	HashTable bad_table(8);

	// using std::vector to store a few tracks for demonstration purposes; you 
	// might manually fill an array by reading from a file--or something
	std::vector<Track> tracks;
	tracks.emplace_back("asdf", "ASDF artist", 5);
	tracks.emplace_back("what", "who", 8);
	tracks.emplace_back("when?", "why", 32);
	tracks.emplace_back("track name", "original artist", 184);
	tracks.emplace_back("music", "human", 100);

	std::println("inserting tracks into both tables...");
	for (const Track& track: tracks) {
		table.insert(track);
		bad_table.insert(track);
	}

	std::println("\ngood table's contents:");
	table.display_all();

	std::println("\nbad table's contents:");
	bad_table.display_all();

	std::println("\ngood table has {} collision(s).", table.collisions());
	std::println("bad table has {} collision(s).", bad_table.collisions());

	return 0;
}
