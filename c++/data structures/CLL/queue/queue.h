#pragma once

class Queue {
	private:
		struct Node {
			char * text; //dynamic!
			Node * next;

			Node();
			~Node();
			Node(const char *other_text);

			void copy(const Node *other_node);
		};

		Node * rear;
	public:
		Queue();
		~Queue();

		bool is_empty() const;

		void dequeue();
		void enqueue(const char text_src[]);
		void display() const;
		void peek(char text_dest[]) const;
};
