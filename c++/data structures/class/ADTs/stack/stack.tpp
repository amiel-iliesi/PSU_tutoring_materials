#include <stdexcept>

template <typename T>
Stack<T>::Node::Node(Node* _next):
	next(_next) {}

	template <typename T>
Stack<T>::Node::Node(T& _data, Node* _next):
	data(_data), next(_next) {}

	template <typename T>
Stack<T>::Stack()
{
	top = nullptr;
	_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
}


template <typename T>
bool Stack<T>::empty() const
{
	return not top;
}

template <typename T>
std::size_t Stack<T>::size() const
{
	return size;
}

template <typename T>
void Stack<T>::clear()
{
	while (top) {
		pop();
	}
	_size = 0;
}


template <typename T>
void Stack<T>::push(T& data)
{
	top = new Node(data, top);
	++_size;
}

template <typename T>
void Stack<T>::pop()
{
	if (not empty()) {
		Node* hold = top;
		top = top->next;
		delete hold;

		--_size;
	}
}

template <typename T>
T& Stack<T>::peek()
{
	if (empty()) {
		throw(std::logic_error("cannot peek empty stack"));
	}
	else {
		return top->data;
	}
}

