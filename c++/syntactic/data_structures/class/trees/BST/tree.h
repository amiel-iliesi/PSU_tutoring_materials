#pragma once

class Tree
{
	private:
		struct Node {
			int data;
			Node *left;
			Node *right;

			Node(int x=0);
		};

		Node *root;

		// -helper functions-------------------------------------------
		void clear(Node*&);
		void push(Node*&, int);
		void display(const Node*, const Node*) const;
		const Node* get_max(const Node*) const;
		bool contains(const Node*, int) const;
		// ------------------------------------------------------------

		// -custom helper functions------------------------------------
		void copy_evens(const Node*, Tree&) const;
		// ------------------------------------------------------------
	public:
		Tree();
		~Tree();

		void push(int);
		void display() const;
		bool contains(int) const;

		// -custom functions-------------------------------------------
		Tree copy_evens() const;
		// ------------------------------------------------------------
};
