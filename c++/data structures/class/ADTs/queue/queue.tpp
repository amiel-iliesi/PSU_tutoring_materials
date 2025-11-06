template <typename T>
bool Queue<T>::empty() const
{
	return list.empty();
}

template <typename T>
void Queue<T>::enqueue(const T& data)
{
	list.push_back(data);
}

template <typename T>
void Queue<T>::dequeue()
{
	list.pop_front();
}

template <typename T>
T& Queue<T>::peek()
{
	return list.front();
}

