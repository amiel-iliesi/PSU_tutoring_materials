#pragma once
#include <string>

class Number {
	public:
		Number();
		Number(float x);
		void square();

	private:
		float data;
};

class Text {
	public:
		Text();
		Text(char c);
		void repeat();
	
	private:
		char data;
};
