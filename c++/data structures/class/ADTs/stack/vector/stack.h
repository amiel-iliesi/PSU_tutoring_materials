#pragma once

#include <string>
#include <vector>
#include <optional>

// NOTE: for simplicity, the core data type is just a string

class Stack
{
	private:
		std::vector<std::string> stack_vector;
		
	public:
		void push(std::string data);
		bool pop();
		std::optional<std::string> peek() const;

		void display() const;
};
