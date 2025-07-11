#pragma once


const int NODE_ARR_SIZE = 3;

class Node {
	private:
		char * stack[NODE_ARR_SIZE];
		int top; // top = where next goes
		Node * next;
	
	public:
		Node();
		~Node();
		bool push(const char * str);
		bool pop();
		bool peek(char * str) const;
		bool is_empty() const;
		bool is_full() const;
		void set_next(Node * next);
		Node * get_next();
		bool display_top() const;
};

class Stack {
	private:
		Node * top;
	
	public:
		Stack();
		~Stack();
		void push(const char * str);
		bool pop();
		bool peek(char * str) const;
		bool is_empty() const;
};
