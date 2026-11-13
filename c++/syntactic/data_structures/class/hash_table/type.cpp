#include "type.h"

Track::Track(const std::string& _name,
			 const std::string _artist,
			 const float& _duration_seconds):
	name(_name), artist(_artist), duration_seconds(_duration_seconds)
{}
