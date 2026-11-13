#include "tracklist.h"

#include <fstream>
#include <iostream> // cin
#include <cstring> //strcmp
#include <print>

using namespace std;

void prompt_searchkey(char name[], char artist[])
{
	std::print(">>> name: ");
	std::cin.getline(name, STRSIZE_MAX);
	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}

	std::print(">>> artist: ");
	std::cin.getline(artist, STRSIZE_MAX);
	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}
}

void display_all_tracks(const Track tracklist[], size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		println("- {} - {}", tracklist[i].artist, tracklist[i].name);
	}
}

Track* find_track(Track tracklist[], size_t size)
{
	char search_name[STRSIZE_MAX];
	char search_artist[STRSIZE_MAX];

	prompt_searchkey(search_name, search_artist);

	for (size_t i = 0; i < size; ++i) {
		if (strcmp(search_name, tracklist[i].name) == 0 and
			strcmp(search_artist, tracklist[i].artist) == 0)
		{
			return &tracklist[i];
		}
	}

	return nullptr;
}

// NOTE: contents of this find_track should be the same as above find_track,
// but cast for const usage
const Track* find_track(const Track tracklist[], size_t size)
{
	char search_name[STRSIZE_MAX];
	char search_artist[STRSIZE_MAX];

	prompt_searchkey(search_name, search_artist);

	for (size_t i = 0; i < size; ++i) {
		if (strcmp(search_name, tracklist[i].name) == 0 and
			strcmp(search_artist, tracklist[i].artist) == 0)
		{
			return &tracklist[i];
		}
	}

	return nullptr;
}

void save(const Track tracklist[], size_t size, const char* filename)
{
	println("*** writing tracklist to \"{}\"", filename);
	ofstream file(filename);

	for (size_t i = 0; i < size; ++i) {
		file << tracklist[i].name << '\n'
			 << tracklist[i].artist << '\n'
			 << tracklist[i].duration_seconds << '\n'
			 << tracklist[i].genre << '\n'
			 << tracklist[i].album << '\n';
	}

	println("*** wrote {} {}", size, (size == 1 ? "entry" : "entries"));
}

void load(Track tracklist[], size_t& size, const char* filename)
{
	println("*** reading tracklist from \"{}\"", filename);
	ifstream file(filename);

	if (not file) {
		println("*** \"{}\" does not exist, aborting loading", filename);
		return;
	}

	while (true) {
		// trigger EOF by attempting to read it
		file.peek();

		if (file.eof()) {
			break;
		}

		file.getline(tracklist[size].name, STRSIZE_MAX, '\n');
		file.getline(tracklist[size].artist, STRSIZE_MAX, '\n');
		file >> tracklist[size].duration_seconds;
		file.ignore(numeric_limits<streamsize>::max(), '\n');
		file.getline(tracklist[size].genre, STRSIZE_MAX, '\n');
		file.getline(tracklist[size].album, STRSIZE_MAX, '\n');

		++size;
	}
	
	println("*** loaded {} {}", size, (size == 1 ? "entry" : "entries"));

}
