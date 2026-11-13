#include "type.h"

class HashTable
{
	private:
		struct Node {
			Track data;
			Node* next;

			Node(const Track& track, Node* _next=nullptr);
		};

		std::size_t hash(const Track& track) const;

		std::size_t size;
		Node** table;
	public:
		HashTable(std::size_t _size);
		~HashTable();

		void insert(const Track& track);

		unsigned collisions() const;
		void display_all() const;
};
