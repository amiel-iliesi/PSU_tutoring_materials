#include "person.h"
#include "queue.h"

#include <print>

int main()
{
	Queue queue;

	queue.push(Person("Abby", 31));
	queue.push(Person("John", 54));
	queue.push(Person("Dwayne", 24));

	std::println("*** added {} people into the queue.", queue.size());

	while (not queue.is_empty()) {
		Person person = queue.pop();
		std::println("* now serving: {}({}).", person.name, person.age);
	}

	return 0;
}
