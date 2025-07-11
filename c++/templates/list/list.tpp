#pragma once

/*--------------------------BASIC FUNCTIONS-----------------------------*/
template <typename T>
List<T>::~List()
{
	while (head) {
		Ptr to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

template <typename T>
void List<T>::insert(const T& _data)
{
	head = new Node(_data, head);
}
