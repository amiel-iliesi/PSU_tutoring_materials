#pragma once
#include <memory>

template <typename T>
class Tree {
	private:
		Tree* parent;
		std::unique_ptr<T> data[3];
		std::unique_ptr<Tree> children[4];

		// checks
		bool is_leaf() const;
		bool data_is_full() const;
		bool children_are_full() const;

		// modifiers
		void add_child(std::unique_ptr<Tree> child);
		void add_child_to_right(const Tree* from, std::unique_ptr<Tree> child);
		void explode();
		void push(std::unique_ptr<T>);
	public:
		Tree();
		Tree(std::unique_ptr<T>);
		void insert(T&&);
		void display() const;
		bool contains(const T&) const;
		size_t size() const;
		
#ifdef TREE_GLASSBOX_TESTING
		// tests
		bool proper_hierarchy() const;
		bool is_balanced() const;
		bool is_balanced(const size_t, const size_t) const;
		size_t find_min_depth() const;
		bool bidirectional() const;
#endif
};

#include "tree.tpp"
