#include "track_data.h"

#include <iostream> //cin
#include <cstring> //strcpy
#include <print> //print, println

void copy(Track& dst, const Track& src)
{
	// if dst and src are the same thing, don't do anything
	if (&dst == &src) {
		return;
	}

	strcpy(dst.name, src.name);
	strcpy(dst.artist, src.artist);
	dst.duration_seconds = src.duration_seconds;
	strcpy(dst.genre, src.genre);
	strcpy(dst.album, src.album);
}

void prompt_entry(Track& track)
{
	std::print(">>> name: ");
	std::cin.getline(track.name, STRSIZE_MAX);
	if (std::cin.fail()) { // entered line was trunc. purge remaining stream
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}

	std::print(">>> artist: ");
	std::cin.getline(track.artist, STRSIZE_MAX);
	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}

	unsigned minutes;
	unsigned seconds;
	std::print(">>> duration (mm:ss): ");
	std::cin >> minutes;
	std::cin.ignore(1, ':');
	std::cin >> seconds;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	track.duration_seconds = minutes * 60 + seconds;
	

	std::print(">>> genre: ");
	std::cin.getline(track.genre, STRSIZE_MAX);
	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}

	std::print(">>> album: ");
	std::cin.getline(track.album, STRSIZE_MAX);
	if (std::cin.fail()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}
}

void display(const Track& track)
{
	std::println("- name: {}", track.name);
	std::println("- artist: {}", track.artist);

	unsigned minutes = track.duration_seconds / 60;
	unsigned seconds = track.duration_seconds - (minutes * 60);
	std::println("- duration: {}:{}", minutes, seconds);

	std::println("- genre: {}", track.genre);
	std::println("- album: {}", track.album);
}
