#include "queue.h"

void Queue::push(const Person& data)
{
	list.push_back(data);
}

Person Queue::peek()
{
	return list.front();
}

Person Queue::pop()
{
	Person person = list.front();
	list.remove(0);

	return person;
}

std::size_t Queue::size() const
{
	return list.size();
}

bool Queue::is_empty() const
{
	return list.is_empty();
}
