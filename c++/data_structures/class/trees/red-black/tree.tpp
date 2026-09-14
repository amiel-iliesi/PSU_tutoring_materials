#include <iostream>
#include <stdexcept>
#include <algorithm> // std::swap
#include <type_traits>

// -constructors---------------------------------------------------------
template <typename T>
Tree<T>::Node::Node(const T& _data, const Color& _color, Node* _parent):
	data(_data),
	color(_color),
	parent(_parent)
{}

// -Node modifiers-------------------------------------------------------
// NOTE: rotation memory ownership ensured by use of swaps
template <typename T>
void Tree<T>::rotate_left(Node* curr)
{
	if (not curr or not curr->right) {
		return;
	}

	bool was_left = (curr->parent and is_left(curr));

	Node* parent = curr->parent;
	Node* new_pivot = curr->right.get();

	curr->right.swap(new_pivot->left);
	new_pivot->parent = parent;
	curr->parent = new_pivot;
	
	if (curr->right) {
		curr->right->parent = curr;
	}

	if (parent) {
		if (was_left) {
			parent->left.swap(new_pivot->left);
		}
		else {
			parent->right.swap(new_pivot->left);
		}
	}
	else {
		root.swap(new_pivot->left);
	}
}

template <typename T>
void Tree<T>::rotate_right(Node* curr)
{
	if (not curr or not curr->left) {
		return;
	}

	bool was_left = (curr->parent and is_left(curr));

	Node* parent = curr->parent;
	Node* new_pivot = curr->left.get();

	curr->left.swap(new_pivot->right);
	new_pivot->parent = parent;
	curr->parent = new_pivot;
	
	if (curr->left) {
		curr->left->parent = curr;
	}

	if (parent) {
		if (was_left) {
			parent->left.swap(new_pivot->right);
		}
		else {
			parent->right.swap(new_pivot->right);
		}
	}
	else {
		root.swap(new_pivot->right);
	}
}

template <typename T>
void Tree<T>::swap(Node* A, Node* B)
{
	if (not A or not B) {
		throw std::logic_error("cannot swap contents of nullptr");
	}

	// if the type T can be swapped, just swap the contents of the node since
	// that's faster
	if (std::is_move_constructible_v<T> and std::is_move_assignable_v<T>) {
		std::swap(A->data, B->data);
		return;
	}

	//...otherwise swap the pointers of the nodes around

	// tell parents to point to their new children
	std::swap(curr_owner(A), curr_owner(B));

	// swap parent pointers
	std::swap(A->parent, B->parent);

	// set children's parent pointers to their new parents
	if (A->left) {
		A->left->parent = B;
	}
	if (A->right) {
		A->right->parent = B;
	}
	if (B->left) {
		B->left->parent = A;
	}
	if (B->right) {
		B->right->parent = A;
	}

	// swap children
	A->left.swap(B->left);
	A->right.swap(B->right);
}

// -Node interrogation---------------------------------------------------
template <typename T>
bool Tree<T>::is_left(const Node* curr) const
{
	if (not (curr and curr->parent)) {
		throw std::logic_error("current and it's parent don't both exist; undefined");
	}

	return curr == curr->parent->left.get();
}

template <typename T>
bool Tree<T>::is_right(const Node* curr) const
{
	if (not (curr and curr->parent)) {
		throw std::logic_error("current and it's parent don't both exist; undefined");
	}

	return curr == curr->parent->right.get();
}

template <typename T>
Tree<T>::Node* Tree<T>::get_sibling(Node* curr)
{
	// better to throw than to return a false-positive nullptr
	if (not curr or not curr->parent) {
		throw std::logic_error("current or parent does not exist; undefined");
	}

	Node* left = curr->parent->left.get(); // avoid a 2nd access in the `else`
	if (curr == left) {
		return curr->parent->right.get();
	}
	else {
		return left;
	}
}

// owner refers to owning pointer AKA smart pointer; this function returns a
// reference to the unique pointer that holds current
template <typename T>
std::unique_ptr<typename Tree<T>::Node>& Tree<T>::curr_owner(const Node* curr) const
{
	if (not curr) {
		throw std::logic_error("cannot evaluate path from nullptr");
	}

	if (not curr->parent) {
		return root;
	}
	else if (is_left(curr)) {
		return curr->parent->left;
	}
	else {
		return curr->parent->right;
	}
}

template <typename T>
Tree<T>::Node* Tree<T>::in_order_successor(const Node* curr) const
{
	if (not curr) {
		throw std::logic_error("undefined for nullptr");
	}

	Node* ios = curr->right.get();
	
	while (ios->left) {
		ios = ios->left.get();
	}

	return ios;
}

template <typename T>
Tree<T>::Node* Tree<T>::find(const T& _data)
{
	Node* curr = root.get();

	while (curr) {
		if (_data < curr->data) {
			curr = curr->left.get();
		}
		else if (_data > curr->data) {
			curr = curr->right.get();
		}
		else {
			return curr;
		}
	}

	return nullptr;
}

template <typename T>
void Tree<T>::correct_red_violation(Node* curr)
{
	/* insertion cases (according to Wikipedia):
	 * src: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Insert_case_1
	 * 1 (no violation): parent is black
	 * 2: parent and uncle are red (fix: toggle colors for: P, U, G, and repeat
	 *    violation correction for G)
	 * 3: reached the top; no more violation can exist (fixes propagated)
	 * 4: parent is root (fix: toggle color for: P)
	 * 5: parent is red, uncle is black, child is inner
	 * 6: parent is red, uncle is black, child is outer */

	// NOTE: Node pointers are declared after conditions test/assert their existence

	// CASE 1, 3: violation no longer exists
	if (not curr or
		not curr->parent or
		curr->parent->color == Color::Black)
	{
		return;
	}

	Node* parent = curr->parent;

	// CASE 4
	if (not parent->parent) {
		parent->color = Color::Black;
		return;
	}

	Node* grandparent = parent->parent;
	Node* uncle = get_sibling(curr->parent);
	
	// CASE 2
	if (uncle and uncle->color == Color::Red) {
		parent->color = Color::Black;
		uncle->color = Color::Black;
		grandparent->color = Color::Red;

		correct_red_violation(grandparent);
		return;
	}
	
	bool parent_is_left = is_left(parent); // used a lot, so cache it

	// CASE 5
	if (parent_is_left != is_left(curr))
	{
		if (parent_is_left) {
			rotate_left(parent);
			// move curr for correct CASE 6 rotation offset
			// NOTE: (curr->left absolutely exists, because it IS what curr->parent
			// WAS)
			curr = curr->left.get(); 
		}
		else {
			rotate_right(parent);
			curr = curr->right.get();
		}
		
		parent = curr->parent;
		// uncle and grandparent are unchanged
	}

	// CASE 6 (intentional fallthrough from CASE 5)
	if (parent_is_left) {
		rotate_right(grandparent);
	}
	else {
		rotate_left(grandparent);
	}
	parent->color = Color::Black;
	grandparent->color = Color::Red;
	
}

// -modifiers------------------------------------------------------------
template <typename T>
bool Tree<T>::insert(const T& _data)
{
	if (not root) {
		root = std::make_unique<Node>(_data, Color::Black);
		return true;
	}

	// search for where to put the new value, but with lookahead so we can set the
	// parent pointer for the new node
	Node* curr = root.get();
	while (true) {
		if (_data < curr->data) {
			if (curr->left) {
				curr = curr->left.get();
			}
			else { // we found where to put the value
				break;
			}
		}
		else if (_data > curr->data) {
			if (curr->right) {
				curr = curr->right.get();
			}
			else {
				break;
			}
		}
		else {
			return false; // no duplicates
		}
	}

	// insert the node
	if (_data < curr->data) {
		curr->left = std::make_unique<Node>(_data, Color::Red, curr);
		correct_red_violation(curr->left.get()); // correct IF violated
	}
	else {
		curr->right = std::make_unique<Node>(_data, Color::Red, curr);
		correct_red_violation(curr->right.get());
	}
	return true;
}

template <typename T>
bool Tree<T>::remove(const T& _data)
{
	Node* found = root.find(_data);

	if (not found) {
		return false;
	}

	remove(found);

	return true;
}

template <typename T>
void Tree<T>::remove(Node* curr)
{
	// TODO:
	return;
}

// -traits---------------------------------------------------------------
template <typename T>
std::size_t Tree<T>::size() const
{
	return size(root.get());
}

template <typename T>
std::size_t Tree<T>::size(const Node* curr) const
{
	if (not curr) {
		return 0;
	}

	return 1 + size(curr->left.get()) + size(curr->right.get());
}

template <typename T>
bool Tree<T>::contains(const T& _data) const
{
	if (not root) {
		return false;
	}

	Node* curr = root.get();
	while (curr) {
		if (_data < curr->data) {
			curr = curr->left.get();
		}
		else if (_data > curr->data) {
			curr = curr->right.get();
		}
		else {
			return true;
		}
	}

	return false;
}

// -IO-------------------------------------------------------------------
template <typename T>
void Tree<T>::display(bool color_info) const
{
	if (not root) {
		std::cout << "<Tree @" << this << " is empty>\n";
		return;
	}

	display(root->right.get(), "", true, color_info);
	if (color_info) {
		std::cout << (root->color == Color::Red ? "R: " : "B: ");
	}
	std::cout << root->data << '\n';
	display(root->left.get(), "", false, color_info);
}

template <typename T>
void Tree<T>::display(const Node* curr,
					  std::string prefix,
					  bool is_right,
					  bool color_info) const
{
	if (not curr) {
		return;
	}

	display(curr->right.get(),
			prefix + (is_right ? "   " : "│  "),
			true,
			color_info);

	std::cout << prefix << (is_right ? "┌  " : "└  ");
	if (color_info) {
		std::cout << (curr->color == Color::Red ? "R: " : "B: ");
	}
	std::cout << curr->data << '\n';

	display(curr->left.get(),
			prefix + (is_right ? "│  " : "   "),
			false,
			color_info);
}

template <typename T>
std::vector<T> Tree<T>::get_all() const
{
	if (not root) {
		return {};
	}

	std::vector<T> v;
	v.reserve(size());

	get_all(root.get(), v);

	return v;
}

template <typename T>
void Tree<T>::get_all(const Node* curr, std::vector<T>& v) const
{
	if (not curr) {
		return;
	}

	get_all(curr->left.get(), v);
	v.push_back(curr->data);
	get_all(curr->right.get(), v);
}

template <typename T>
T Tree<T>::operator[](int i)
{
	int curr_index = 0;
	
	bool reverse = i < 0;

	if (reverse) {
		i *= -1;
		i -= 1;
	}

	Node* found = (reverse ? find_index_reverse(root.get(), curr_index, i)
					   	   : find_index(root.get(), curr_index, i));
	
	if (not found) {
		throw std::out_of_range("index is out of tree range");
	}

	return found->data;
}

template <typename T>
Tree<T>::Node* Tree<T>::find_index(Node* curr,
								   int& curr_index,
								   const int i) const
{
	if (not curr) {
		return nullptr;
	}

	Node* found = find_index(curr->left.get(), curr_index, i);
	if (found) { // short circuit the right subtree if we found already
		return found;
	}

	if (curr_index == i) {
		return curr;
	}

	++curr_index;

	return find_index(curr->right.get(), curr_index, i);
}

template <typename T>
Tree<T>::Node* Tree<T>::find_index_reverse(Node* curr,
								   		   int& curr_index,
								   		   const int i) const
{
	if (not curr) {
		return nullptr;
	}

	Node* found = find_index_reverse(curr->right.get(), curr_index, i);
	if (found) { // short circuit the right subtree if we found already
		return found;
	}

	if (curr_index == i) {
		return curr;
	}

	++curr_index;

	return find_index_reverse(curr->left.get(), curr_index, i);
}

// -tests----------------------------------------------------------------
template <typename T>
bool Tree<T>::TEST_valid_inequality() const
{
	return TEST_all_inequal(root.get());
}

template <typename T>
bool Tree<T>::TEST_all_inequal(const Node* curr) const
{
	if (not curr) {
		return true;
	}

	// written in one statement to take advantage of short-circuit evaluation
	return (not curr->left or curr->left->data < curr->data) and
		   (not curr->right or curr->data < curr->right->data) and
		   TEST_all_inequal(curr->left.get()) and
		   TEST_all_inequal(curr->right.get());
}

template <typename T>
bool Tree<T>::TEST_parent_child_verification() const
{
	return TEST_all_parent_child(root.get());
}

template <typename T>
bool Tree<T>::TEST_all_parent_child(const Node* curr) const
{
	if (not curr) {
		return true;
	}

	return (not curr->left or curr->left->parent == curr) and
		   (not curr->right or curr->right->parent == curr) and
		   TEST_all_parent_child(curr->left.get()) and
		   TEST_all_parent_child(curr->right.get());
}

template <typename T>
bool Tree<T>::TEST_no_red_parent_child() const
{
	return TEST_no_red_parent_child(root.get());
}

template <typename T>
bool Tree<T>::TEST_no_red_parent_child(const Node* curr) const
{
	if (not curr) {
		return true;
	}

	if ((curr->color == Color::Red) and
		((curr->left and curr->left->color == Color::Red) or
		(curr->right and curr->right->color == Color::Red)))
	{
		return false;
	}

	return TEST_no_red_parent_child(curr->left.get()) and
		   TEST_no_red_parent_child(curr->right.get());
}

template <typename T>
bool Tree<T>::TEST_all_black_height_equal() const
{
	size_t expected_black_height = 0;
	// just get left-most path for expected value, since they should all be the
	// same height anyhow
	{
		Node* curr = root.get();
		while (curr) {
			if (curr->color == Color::Black) {
				++expected_black_height;
			}
			curr = curr->left.get();
		}
		++expected_black_height; // null nodes count as black
	}

	return TEST_all_black_height_equal(root.get(), 0, expected_black_height);
}

template <typename T>
bool Tree<T>::TEST_all_black_height_equal(
		const Node* curr,
		size_t curr_black_seen,
		const size_t expected_black_height) const
{
	if (not curr or curr->color == Color::Black) {
		++curr_black_seen;
	}

	if (not curr) {
		return curr_black_seen == expected_black_height;
	}
	else {
		return TEST_all_black_height_equal(curr->left.get(),
										   curr_black_seen,
										   expected_black_height)
			   and
			   TEST_all_black_height_equal(curr->right.get(),
										   curr_black_seen,
										   expected_black_height);
	}
}
