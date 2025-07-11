#include <stdexcept>
#include <iostream>

template <typename T>
Tree<T>::Tree()
{
	parent = nullptr;
}

template <typename T>
Tree<T>::Tree(std::unique_ptr<T> datum)
{
	parent = nullptr;

	data[0] = std::move(datum);
}

template <typename T>
bool Tree<T>::is_leaf() const
{
	return !children[0];
}

template <typename T>
bool Tree<T>::data_is_full() const
{
	return (bool)data[2];
}

template <typename T>
bool Tree<T>::children_are_full() const
{
	return (bool)children[3];
}

template <typename T>
void Tree<T>::explode()
{
	// 1. break off right side
	std::unique_ptr<Tree> right_sibling = std::make_unique<Tree>(std::move(data[2]));
	if (children[2])
		right_sibling->add_child(std::move(children[2]));
	if (children[3])
		right_sibling->add_child(std::move(children[3]));

	// 2. send pieces where they need to go
	if (parent) {
		parent->add_child_to_right(this, std::move(right_sibling));
		parent->push(std::move(data[1]));
	}
	else { // we are global root, push siblings down (simulated push)
		// 2a. break off left side
		std::unique_ptr<Tree> left_sibling = std::make_unique<Tree>(std::move(data[0]));
		if (children[0])
			left_sibling->add_child(std::move(children[0]));
		if (children[1])
			left_sibling->add_child(std::move(children[1]));

		std::swap(data[1], data[0]);
		
		children[0] = std::move(left_sibling);
		children[0]->parent = this;
		children[1] = std::move(right_sibling);
		children[1]->parent = this;
	}
}

template <typename T>
void Tree<T>::push(std::unique_ptr<T> datum)
{
	if (!data[0] or (*datum < *data[0])) {
		std::swap(data[1], data[2]);
		std::swap(data[0], data[1]);
		data[0] = std::move(datum);
	}
	else if (!data[1] or (*datum < *data[1])) {
		std::swap(data[1], data[2]);
		data[1] = std::move(datum);
	}
	else {
		data[2] = std::move(datum);
	}

	if (data_is_full()) {
		explode();
	}
}

template <typename T>
void Tree<T>::add_child(std::unique_ptr<Tree> child)
{
	if (children_are_full()) {
		throw std::logic_error("attempted insertion into a full node; "
							   "a persistent 4-node should not exist");
	}

	child->parent = this;

	// when a child comes into this function, it is guaranteed to only have one datum
	// --so use that as representative for the tree
	const T& datum = *child->data[0];

	if (datum < *data[0]) {
		std::swap(children[3], children[2]);
		std::swap(children[2], children[1]);
		std::swap(children[1], children[0]);
		children[0] = std::move(child);
	}
	else if ((not data[1]) or (datum < *data[1])) {
		std::swap(children[3], children[2]);
		std::swap(children[2], children[1]);
		children[1] = std::move(child);
	}
	else if ((not data[2]) or (datum < *data[2])) {
		std::swap(children[3], children[2]);
		children[2] = std::move(child);
	}
	else {
		children[3] = std::move(child);
	}
}

// this function blindly adds the child to the right of the sibling requesting it
// this is to avoid an early call to explode() separating siblings prematurely
template <typename T>
void Tree<T>::add_child_to_right(const Tree* from, std::unique_ptr<Tree> child)
{
	size_t from_index = 0;
	
	while (from_index <= 4 and (children[from_index].get() != from)) {
		++from_index;
	}

	if (from_index == 4) {
		throw std::domain_error("child and parent are not bidirectional: "
								"parent cannot find child");
	}
	else if (from_index == 3) {
		throw std::logic_error("attempted insertion into a full node; "
							   "a persistent 4-node should not exist");
	}

	size_t move_to = from_index + 1;
	if (move_to == 1) {
		std::swap(children[2], children[3]);
		std::swap(children[1], children[2]);
	}
	else if (move_to == 2) {
		std::swap(children[2], children[3]);
	}
	
	child->parent = this;
	children[move_to] = std::move(child);
}

template <typename T>
void Tree<T>::insert(T&& datum) {
	if (data_is_full()) {
		throw std::logic_error("attempted insertion into a full node; "
							   "a persistent 4-node should not exist");
	}

	if (is_leaf()) {
		push(std::make_unique<T>(std::move(datum)));
	}
	else {
		if (datum <= *data[0]) {
			children[0]->insert(std::move(datum));
		}
		else if (!data[1] or (datum <= *data[1])) {
			children[1]->insert(std::move(datum));
		}
		else if (!data[2] or (datum <= *data[2])) {
			children[2]->insert(std::move(datum));
		}
		else {
			children[3]->insert(std::move(datum));
		}
	}
}

template <typename T>
void Tree<T>::display() const {
	for (size_t i = 0; i < 3; ++i) {
		if (children[i]) {
			children[i]->display();
		}
		if (data[i]) {
			std::cout << *data[i] << ' ';
		}
	}
	if (children[3]) {
		children[3]->display();
	}

	if (!parent) {
		std::cout << std::endl;
	}
}

template <typename T>
bool Tree<T>::contains(const T& key) const
{
	for (size_t i = 0; i < 3 and data[i]; ++i) {
		if (*data[i] == key) { return true; }
	}

	if ((!data[0] or (key < *data[0])) and children[0]) {
		return children[0]->contains(key);
	}
	else if ((!data[1] or (key < *data[1])) and children[1]) {
		return children[1]->contains(key);
	}
	else if ((!data[2] or (key < *data[2])) and children[2]) {
		return children[2]->contains(key);
	}
	else if (children[3]) {
		return children[3]->contains(key);
	}

	return false; // vacuously false
}

template <typename T>
size_t Tree<T>::size() const
{
	size_t count = 0;
	for (size_t i = 0; i < 3; ++i) {
		if (data[i]) { ++count; }
	}

	for (size_t i = 0; i < 4; ++i) {
		if (children[i]) { count += children[i]->size(); }
	}

	return count;
}

#ifdef TREE_GLASSBOX_TESTING
// this tests that everything c[0] < d[0] < c[1] < d[1] < c[2] < d[2] < c[3] for all trees
template <typename T>
bool Tree<T>::proper_hierarchy() const
{
	for (size_t i = 0; i < 4; ++i) {
		if (children[i]) {
			if (not children[i]->proper_hierarchy()) {
				return false; // short-circuit, 1 false is all false
			}
		}
	}

	//pi=parent index; ci = child index
	for (size_t pi = 0; pi < 3; ++pi) {
		if (data[pi] and children[pi]) {
			for (size_t ci = 0; ci < 3 and children[pi]->data[ci]; ++ci) {
				if (not (*children[pi]->data[ci] < *data[pi])) {
					return false;
				}
			}
		}
	}

	if (data[2] and children[3]) {
		for (size_t ci = 0; ci < 3 and children[3]->data[ci]; ++ci) {
			if (not (*children[3]->data[ci] > *data[2])) {
				return false;
			}
		}
	}

	return true;
}

// this tests the tree height invariant
template <typename T>
bool Tree<T>::is_balanced() const {
	// property of 2-3 tree: all leaves should be at the same depth
	size_t leaf_depth = find_min_depth();
	size_t curr_depth = 1;

	return is_balanced(leaf_depth, curr_depth);
}

// recursive search for the above wrapper
template <typename T>
bool Tree<T>::is_balanced(const size_t leaf_depth, const size_t curr_depth) const {
	if (is_leaf()) {
		if (curr_depth != leaf_depth) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (children[0] and not children[0]->is_balanced(leaf_depth, curr_depth+1)) {
			return false;
		}
		if (children[1] and not children[1]->is_balanced(leaf_depth, curr_depth+1)) {
			return false;
		}
		if (children[2] and not children[2]->is_balanced(leaf_depth, curr_depth+1)) {
			return false;
		}
		if (children[3] and not children[3]->is_balanced(leaf_depth, curr_depth+1)) {
			return false;
		}

		return true;
	}
}

// baseline depth for balance testing
template <typename T>
size_t Tree<T>::find_min_depth() const {
	if (not is_leaf()) {
		return children[0]->find_min_depth() + 1;
	}
	else {
		return 1;
	}
}

// this ensures that every parent and child are bidirectional: p <-> c
template <typename T>
bool Tree<T>::bidirectional() const
{
	for (size_t i = 0; i < 4; ++i) {
		if (children[i] and
		   ((not (children[i]->parent == this)) or (not children[i]->bidirectional())))
		{
			return false;
		}

	}
	
	return true;
}
#endif //TREE_GLASSBOX_TESTING
