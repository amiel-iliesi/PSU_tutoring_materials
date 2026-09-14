#include "people.h"
#include "events.h"
#include <random>
#include <algorithm>

// some helper functions for main

// create a random shuffled integer array from [0, n): of size [0, n)
std::vector<size_t> pick(size_t n,
		std::default_random_engine& gen);

// populate an events RSVP list with a random amount of people
void random_rsvp(const std::vector<Person>& people,
		Event& event,
		std::default_random_engine& gen);




int main()
{
	std::random_device rd;
	std::default_random_engine gen(rd());

	Events events;

	std::vector<Person> people;
	people.emplace_back("Jeff", 21);
	people.emplace_back("Jane", 25);
	people.emplace_back("William", 22);
	people.emplace_back("Shania", 23);
	people.emplace_back("Josia", 26);
	people.emplace_back("Chris", 24);
	people.emplace_back("Sarah", 23);

	Event halloween_party("Halloween Party",
			"Time to get spooky! Meet up at 1234 Main St. 98765 in full costume!",
			Time(2026,9,31,22,0), Time(2026,10,1,4,0));

	random_rsvp(people, halloween_party, gen);
	events.add_event(halloween_party);

	Event friendsgiving("Friendsgiving Party",
			"Let's meet up and show a bit more thanks to one another!",
			Time(2026,11,26,17,0), Time(2026,11,26,21,0));

	random_rsvp(people, friendsgiving, gen);
	events.add_event(friendsgiving);

	Event jury_duty("Jury Duty",
			"Shh, you're under NDA, no description!",
			Time(2026,12,31,8,0), Time(2027,1,15,8,0));
	jury_duty.attendees.push(people[0]);
	events.add_event(jury_duty);

	events.display();
	
	return 0;
}




// helper function implementations
std::vector<size_t> pick(size_t n,
		std::default_random_engine& gen)
{
	std::vector<size_t> range;
	range.reserve(n);

	for (size_t i = 0; i < n; ++i) {
		range.push_back(i);
	}

	std::shuffle(range.begin(), range.end(), gen);

	range.resize(gen() % n);

	return range;
}

void random_rsvp(const std::vector<Person>& people,
		Event& event,
		std::default_random_engine& gen)
{
	std::vector<size_t> rsvp = pick(people.size(), gen);
	for (size_t i: rsvp) {
		event.attendees.push(people[i]);
	}
}
