#include "list.h"
#include <stdexcept>
#include <format>

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	clear();
}

List::Node* List::get_node(unsigned index)
{
	unsigned i = 0;
	Node *curr = head;
	while (i < index and curr) {
		++i;
		curr = curr->next;
	}

	if (not curr) {
		std::string msg = std::format("index={} out of range for list of size={}",
				index, size());
		throw std::out_of_range(msg);
	}

	return curr;
}


void List::insert(unsigned index, const Person& data)
{
	// case: insertion on either end of the list
	if (index == 0) {
		push_front(data);
		return;
	}
	else if (index == size()) {
		push_back(data);
		return;
	}

	// case: insertion into the middle of the list
	Node* insert_before = get_node(index);

	Node* new_node = new Node(data, insert_before->prev, insert_before);
	insert_before->prev->next = new_node;
	insert_before->prev = new_node;
}

void List::push_front(const Person& data)
{
	head = new Node(data, nullptr, head);

	// there wasn't anything in the list before, so this changes tail, too
	if (not head->next) {
		tail = head;
	}
	else {
		head->next->prev = head;
	}
}

void List::push_back(const Person& data)
{
	tail = new Node(data, tail, nullptr);

	if (not tail->prev) {
		head = tail;
	}
	else {
		tail->prev->next = tail;
	}
}

void List::clear()
{
	while (head) {
		Node *to_delete = head;
		head = head->next;
		delete to_delete;
	}

	tail = nullptr;
}


Person& List::get(unsigned index)
{
	return get_node(index)->data;
}

void List::remove(unsigned index)
{
	Node *to_remove = get_node(index);

	// 1. move list members
	if (to_remove == head) {
		head = head->next;
	}

	if (to_remove == tail) {
		tail = tail->prev;
	}

	// 2. move pointers surrounding removing node
	if (to_remove->prev) {
		to_remove->prev->next = to_remove->next;
	}

	if (to_remove->next) {
		to_remove->next->prev = to_remove->prev;
	}

	// 3. deallocate
	delete to_remove;
}

Person& List::front()
{
	if (is_empty()) {
		throw std::out_of_range("empty list has no front");
	}

	return head->data;
}

Person& List::back()
{
	if (is_empty()) {
		throw std::out_of_range("empty list has no back");
	}

	return tail->data;
}


std::size_t List::size() const
{
	std::size_t n = 0;
	Node *curr = head;
	while (curr)
	{
		++n;
		curr = curr->next;
	}
	return n;
}

bool List::is_empty() const
{
	return not (bool)head;
}

std::string List::as_string() const
{
	if (is_empty()) {
		return {};
	}

	std::string s;

	s = std::format("{}({})", head->data.name, head->data.age);

	for (Node *curr=head->next; curr; curr=curr->next) {
		s += std::format(", {}({})", curr->data.name, curr->data.age);
	}

	return s;
}
