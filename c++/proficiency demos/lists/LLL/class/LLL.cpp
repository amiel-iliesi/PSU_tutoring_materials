#include "LLL.h"
#include <cstdlib> // for rand
#include <ctime> // to seed rand
#include <iostream> // for std::cout in List::display

// NOTE: You will not be able to see these implementations in Karla's examples
// Just pretend that this file does not exist!

List::Node::Node(int data, Node* next): data(data), next(next) {}


List::List(int min, int max, std::size_t min_size, std::size_t size_var)
{
    srand(time(NULL));

    head = nullptr;

    std::size_t size = min_size + rand() % (size_var + 1);

    int range = max - min;

    for (size_t _ = 0; _ < size; ++_) {
        head = new Node((rand() % (range + 1)) + min, head);
    }
}

List::~List()
{
    while (head) {
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

void List::display() const
{
    for (const Node* curr=head; curr; curr=curr->next) {
        std::cout << curr->data;

        if (curr->next) {
            std::cout << " -> ";
        }
    }

    std::cout << std::endl;
}
