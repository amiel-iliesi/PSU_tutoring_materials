#pragma once

class FractionList {
	private:
		struct Fraction {
			int numerator;
			int denominator;
		};

		struct Node {
			Fraction data;
			Node *next;
		};

		Node * head;
		
		Node * make_new_fraction(int a, int b);
		void insert(Node * new_fraction);
	public:
		FractionList(): head(nullptr) {}

		void add(int new_numerator, int new_denominator);
		void display() const;
};
