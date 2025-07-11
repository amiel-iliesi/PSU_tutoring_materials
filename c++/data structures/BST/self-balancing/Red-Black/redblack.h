#pragma once

class Tree {
	private:
		struct Node
		{
			int data;
			bool red;
			Node * parent;
			Node * left;
			Node * right;

			Node(int d, bool r);
			Node(int d);
			Node();
			~Node();
		};

		Node * root;

		void display_tree(Node * const&, const string &, bool) const;
	
	public:
		Tree();
		~Tree();

		// input
		void insert(int data);

		// output
		void display_tree() const;
};
