#pragma once
#include <cstdlib>

class Tree {
	private:
		struct Node {
			int data;
			
			Node* left;
			Node* right;

			// ~given~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			Node(int data, Node* left=nullptr, Node* right=nullptr);
			~Node();
			
			const Node* get_max() const;
			void display(const Node* max) const;
			void insert(int);
			// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			// -custom node functions go here----------

			// ----------------------------------------
		};

		Node* root;

		// -custom private functions go here-------

		// ----------------------------------------

	public:
		// ~given~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Tree(int min, int max, std::size_t min_size, std::size_t size_var);
		~Tree();

		void display() const;
		void insert(int);
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		// -custom public functions go here--------

		// ----------------------------------------
};
