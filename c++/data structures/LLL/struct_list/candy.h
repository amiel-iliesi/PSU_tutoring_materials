#pragma once

struct Candy {
	Candy();
	Candy(const char*, const char*, int, int, float);
	~Candy();

	char* name;
	char* category;
	int sugar_grams;
	int quantity;
	float health_rating;

	void add_name(const char[]);
	void add_category(const char[]);

	void operator=(const Candy& other);
	bool operator<(const Candy& other) const;
	bool operator<=(const Candy& other) const;
};

struct Node {
	Node();
	Node(const Candy&);

	Candy data;
	Node* next;
};

void add(Node*& head, const Candy& given);

void clear(Node*& head);
