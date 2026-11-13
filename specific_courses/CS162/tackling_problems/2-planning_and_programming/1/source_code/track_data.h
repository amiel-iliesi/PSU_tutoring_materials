#pragma once

#include <cstddef> // size_t

// This file describes the foundational track type, as well as basic 
// interactions with the type via. helper functions.

inline constexpr std::size_t STRSIZE_MAX = 128;

struct Track
{
	char name[STRSIZE_MAX];
	char artist[STRSIZE_MAX];
	unsigned duration_seconds;
	char genre[STRSIZE_MAX];
	char album[STRSIZE_MAX];
};

void copy(Track& dst, const Track& src);

void prompt_entry(Track& track);

void display(const Track& track);
