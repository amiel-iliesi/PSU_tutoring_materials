#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

class List
{
private:
	struct Node
	{
		int data;
		Node * next;
		//constructors to make my life easy, and my code pretty
		Node(): next(nullptr) {}
		Node(int _data): data(_data), next(nullptr) {}
	};

	Node * head;

	//private recursive functions
	void push_back(Node*&, int); //FYI: prototypes don't need variable names

	//NOT IMPLEMENTED YET; see README.cpp, we're doing it there!
	bool remove_first_even(Node*&);
public:
	List(): head(nullptr) {}
	~List();

	void push_back(int); //insert to end
	void display() const;

	//NOT IMPLEMENTED YET; see README.cpp, we're doing it there!
	bool remove_first_even();
};

#endif //__LINKED_LIST_H__
