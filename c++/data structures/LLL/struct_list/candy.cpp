#include "candy.h"
#include <cstring>

// ----------------------------------------
// - HELPER FUNCTIONS ---------------------
// ----------------------------------------
void Candy::operator=(const Candy& other) {
	add_name(other.name);
	add_category(other.category);
	sugar_grams = other.sugar_grams;
	quantity = other.quantity;
	health_rating = other.health_rating;
}

bool Candy::operator<(const Candy& other) const {
	return strcmp(this->name, other.name) < 0;
}

bool Candy::operator<=(const Candy& other) const {
	return strcmp(this->name, other.name) <= 0;
}

// ----------------------------------------
// - IMPLEMENTATIONS ----------------------
// ----------------------------------------

// constructors/destructors ------------------
Candy::Candy() {
	name = nullptr;
	category = nullptr;
}

Candy::Candy(const char* new_name,
			 const char* new_category,
			 int new_sugar_grams,
			 int new_quantity,
			 float new_health_rating)
{
	add(new_name);
	add(new_category);
	sugar_grams = new_sugar_grams;
	quantity = new_quantity;
	health_rating = new_health_rating;
}

Candy::~Candy() {
	delete [] name;
	delete [] category;
}

// Candy functions ---------------------------
void Candy::add_name(const char new_name[]) {
	delete [] name;
	name = new char[strlen(new_name)+1];
	strcpy(name, new_name);
}

void Candy::add_category(const char new_category[]) {
	delete [] category;
	category = new char[strlen(new_category)+1];
	strcpy(category, new_category);
}

// list functions ----------------------------

// insertion sort; sorted by name!
void add(Node*& head, const Candy& given) {
	if (!head) {
		head = new Node(given);

		head->next = nullptr;
		head->data = given;
	}
	else {
		if (given <= head->data) { // given @ beginning
			Node* new_node = new Node;
			new_node->next = head;
			head = new_node;
			head->data = given;
		}
		else {
			bool inserted = false;
			Node* tail = nullptr;
			// given in the middle somewhere
			for (Node* curr=head; curr; curr=curr->next)
			{
				if (!curr->next) {
					tail = curr;
				}
				else if (given <= curr->next->data) {
					Node* new_node = new Node;
					new_node->next = curr->next;
					curr->next = new_node;
					new_node->data = given;
					inserted = true;
					break;
				}
			}

			if (!inserted) // given @ the end
			{
				tail->next = new Node;
				tail->next->next = nullptr;
				tail->next->data = given;
			}
		}
	}
}

void clear(Node*& head) {
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}
