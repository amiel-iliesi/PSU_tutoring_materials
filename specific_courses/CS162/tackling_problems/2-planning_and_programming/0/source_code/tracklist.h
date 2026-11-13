#pragma once

#include "track_data.h"

// This file contains implementation details for aggregate/array track 
// functions. This includes file IO.

void display_all_tracks(const Track tracklist[], std::size_t size);

Track* find_track(Track tracklist[], std::size_t size);
const Track* find_track(const Track tracklist[], std::size_t size);

void save(const Track tracklist[], std::size_t size, const char* filename);

void load(Track tracklist[], std::size_t& size, const char* filename);
