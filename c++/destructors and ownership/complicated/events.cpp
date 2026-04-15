#include "events.h"
#include <print>
#include <cstring>

// -Time--------------------------------------------------------------------

Time::Time(): year(0), month(0), day(0), hour(0), minute(0)
{}

Time::Time(unsigned y, unsigned mo, unsigned d, unsigned h, unsigned mi):
	year(y), month(mo), day(d), hour(h), minute(mi)
{}

void Time::display() const
{
	std::print("{:04}-{:02}-{:02}T{:02}:{:02}", year, month, day, hour, minute);
}

// -Event-------------------------------------------------------------------
Event::Event(): event_title(nullptr), event_description(nullptr)
{}

Event::~Event()
{
	delete [] event_title;
	delete [] event_description;
}

Event::Event(const char* t, const char* d, const Time& s, const Time& e):
	start(s),
	end(e)
{
	event_title = new char[strlen(t)+1];
	strcpy(event_title, t);

	event_description = new char[strlen(d)+1];
	strcpy(event_description, d);
}

Event::Event(const char* t,
			 const char* d,
			 const Time& s,
			 const Time& e,
			 const People& a):
	start(s),
	end(e),
	attendees(a)
{
	event_title = new char[strlen(t)+1];
	strcpy(event_title, t);

	event_description = new char[strlen(d)+1];
	strcpy(event_description, d);
}

Event::Event(const Event& other):
	Event(other.event_title,
		  other.event_description,
		  other.start,
		  other.end,
		  other.attendees)
{}

void Event::operator=(const Event& other)
{
	delete [] event_title;
	delete [] event_description;

	event_title = new char[strlen(other.event_title)+1];
	strcpy(event_title, other.event_title);

	event_description = new char[strlen(other.event_description)+1];
	strcpy(event_description, other.event_description);

	start = other.start;
	end = other.end;
	attendees = other.attendees;
}

// -Events----------------------------------------------------------------------

Events::Node::Node(): next(nullptr)
{}

Events::Node::Node(const Event& other):
	data(other),
	next(nullptr)
{}


Events::Events(): head(nullptr)
{}

Events::~Events()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

// just add to front of the list
void Events::add_event(const Event& event_in)
{
	Node* new_node = new Node(event_in);

	new_node->next = head;
	head = new_node;
}

void Events::display()
{
	for (Node* curr=head; curr; curr=curr->next) {
		std::println("{}: \"{}\"",
				curr->data.event_title,
				curr->data.event_description);
		
		std::print("- date & time: from ");
		curr->data.start.display();
		std::print(" to ");
		curr->data.end.display();
		std::print("\n");

		std::print("- attendees: ");
		curr->data.attendees.display();
		std::print("\n");
	}
}

