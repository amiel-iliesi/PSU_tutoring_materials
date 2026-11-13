#include "hash.h"

#include <print>

HashTable::Node::Node(const Track& track, Node* _next):
	data(track), next(_next)
{}

std::size_t HashTable::hash(const Track& track) const
{
	std::size_t hash_value = 0;

	for (const char& c: track.name) {
		hash_value += (std::size_t)c;
	}

	return hash_value % size;
}

HashTable::HashTable(std::size_t _size):
	size(_size)
{
	table = new Node*[size];
}

HashTable::~HashTable()
{
	for (std::size_t i = 0; i < size; ++i) {
		Node* curr = table[i];
		while (curr) {
			Node* to_delete = curr;
			curr = curr->next;
			delete to_delete;
		}
		table[i] = nullptr;
	}
}

void HashTable::insert(const Track& track)
{
	std::size_t index = hash(track);

	Node* head = table[index];

	Node* new_node = new Node(track, head);

	table[index] = new_node;
}

unsigned HashTable::collisions() const
{
	unsigned collisions_count = 0;

	for (std::size_t i = 0; i < size; ++i) {
		if (table[i]) {
			for (Node* curr = table[i]->next; curr; curr = curr->next) {
				++collisions_count;
			}
		}
	}

	return collisions_count;
}

void HashTable::display_all() const
{
	for (std::size_t i = 0; i < size; ++i) {
		for (Node* curr = table[i]; curr; curr = curr->next) {
			std::println("* {} - {}({:.0f})",
					curr->data.artist,
					curr->data.name,
					curr->data.duration_seconds);
		}
	}
}
