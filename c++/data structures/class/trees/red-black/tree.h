#pragma once

#include <memory>
#include <string>
#include <vector>

// NOTE: Ideas for improvement, if you wanted to make this better!
// 
// * Add a compare function to the template definition (see `std::set` for an
//   example of this). This allows separation of data and their key/label.
//
// * Adjust the tree to allow duplicate entries (think "hash buckets")
// 
// * `Tree.get_all` is a lazy way to allow interfacing with the standard
//   library; I bodged it together for "Test 6". If you want this Tree to be a
//   proper container, try giving it a proper C++ STL container/iterator
//   interface, instead of this `std::vector` intermediary that `Tree.get_all`
//   uses as a hack.

template <typename T>
class Tree
{
	private:
		enum class Color { Red, Black };

		struct Node {
			T data;

			Color color;

			Node* parent;
			std::unique_ptr<Node> left;
			std::unique_ptr<Node> right;

			Node(const T& _data,
				 const Color& _color,
				 Node* _parent=nullptr);
		};

		std::unique_ptr<Node> root;
		
		// -Node modifiers---------------------------------------------
		void rotate_left(Node* curr);
		void rotate_right(Node* curr);
		void swap(Node* A, Node* B);

		// -Node interrogation-----------------------------------------
		bool is_left(const Node* curr) const;
		bool is_right(const Node* curr) const;
		Node* get_sibling(Node* curr);
		std::unique_ptr<Node>& curr_owner(const Node* curr) const;
		Node* in_order_successor(const Node* curr) const;

		// -recursive helpers------------------------------------------
		std::size_t size(const Node* curr) const;
		void display(const Node* curr,
					 std::string prefix,
					 bool is_right,
					 bool color_info) const;
		void correct_red_violation(Node* curr);
		void get_all(const Node* curr, std::vector<T>& v) const;
		Node* find(const T&);
		Node* find_index(Node* curr,
						 int& curr_index,
						 const int i) const;
		Node* find_index_reverse(Node* curr,
								 int& curr_index,
								 const int i) const;
		void remove(Node*);
		

		// -test helpers-----------------------------------------------
		bool TEST_all_inequal(const Node* curr) const;
		bool TEST_all_parent_child(const Node* curr) const;
		bool TEST_no_red_parent_child(const Node* curr) const;
		bool TEST_all_black_height_equal(const Node* curr,
										 size_t curr_black_seen,
										 const size_t expected_black_height) const;

	public:
		// -modifiers--------------------------------------------------
		bool insert(const T& _data);
		bool remove(const T& _data); // TODO

		// -traits-----------------------------------------------------
		std::size_t size() const;
		bool contains(const T& _data) const;

		// -IO---------------------------------------------------------
		void display(bool color_info=false) const;
		std::vector<T> get_all() const;
		T operator[](int i);

		// -tests------------------------------------------------------
		bool TEST_valid_inequality() const; // BST: left < self < right
		bool TEST_parent_child_verification() const; // BST: internal consistency
		bool TEST_no_red_parent_child() const; // RB: property 3
		bool TEST_all_black_height_equal() const; // RB: property 4
};

#include "tree.tpp"
