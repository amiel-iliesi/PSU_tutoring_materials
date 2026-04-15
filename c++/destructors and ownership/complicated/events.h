#pragma once

#include "people.h"

struct Time
{
	unsigned year;
	unsigned month;
	unsigned day;
	unsigned hour;
	unsigned minute;

	Time();
	Time(unsigned y, unsigned mo, unsigned d, unsigned h, unsigned mi);
	Time(const Time&) = default;
	constexpr Time& operator=(const Time&) = default;

	void display() const;
};

struct Event
{
	char* event_title;
	char* event_description;
	
	Time start;
	Time end;

	People attendees;

	Event();
	~Event();
	Event(const char* t, const char* d, const Time& s, const Time& e);
	Event(const char* t, const char* d, const Time& s, const Time& e, const People& a);
	Event(const Event&);
	void operator=(const Event&);
};

class Events
{
	private:
		struct Node {
			Event data;
			Node* next;

			Node();
			Node(const Event&);
		};

		Node* head;
	public:

		Events();
		~Events();
		void add_event(const Event&);
		void display();
};
