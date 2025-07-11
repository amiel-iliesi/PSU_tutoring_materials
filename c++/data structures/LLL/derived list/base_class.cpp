#include "base_class.h"
#include <iostream>

// Numbers functions
Number::Number(): data(0.0) {}
Number::Number(float x): data(x) {}

void Number::square() {
	std::cout << this->data * this->data << std::endl;
}


// Text functions
Text::Text(): data('.') {}
Text::Text(char c): data(c) {}

void Text::repeat() {
	std::cout << this->data << this->data << std::endl;
}
