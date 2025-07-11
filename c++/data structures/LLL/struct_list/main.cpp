#include "candy.h"
#include <iostream>

using namespace std;

const size_t BUFSIZE = 2048;

// prototypes
void read_candy(Node*& head);
void display(const Node* head);



int main()
{
	Node* head = nullptr;

	for (int i=0; i<2; ++i) {
		read_candy(head);
		cout << endl;
	}

	display(head);

	clear(head);
	return 0;
}


// implementations
void read_candy(Node*& head) {
	// set up temporary
	Candy temp;
	char temp_str[BUFSIZE];

	// fill it with information
	cout << ">>> name: ";
	cin.getline(temp_str, BUFSIZE);
	temp.add_name(temp_str);

	cout << ">>> category: ";
	cin.getline(temp_str, BUFSIZE);
	temp.add_category(temp_str);

	cout << ">>> sugar(grams): ";
	cin >> temp.sugar_grams;
	cin.ignore(100, '\n');

	cout << ">>> quantity: ";
	cin >> temp.quantity;
	cin.ignore(100, '\n');

	cout << ">>> health rating (out of 5): ";
	cin >> temp.health_rating;
	cin.ignore(100, '\n');

	// send it into the list
	add(head, temp);
}

void display(const Node* head) {
	for (const Node* curr=head; curr; curr=curr->next) {
		cout << "name: " << curr->data.name << endl;
		cout << "category: "
			 << curr->data.category << endl;
		cout << "sugar(grams): "
			 << curr->data.sugar_grams << endl;
		cout << "quantity: "
			 << curr->data.quantity << endl;
		cout << "health rating: "
			 << curr->data.health_rating << endl;

		if (curr->next) {
			cout << "--------------------------\n";
		}
	}
}
