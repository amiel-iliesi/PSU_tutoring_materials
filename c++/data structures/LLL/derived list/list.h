#include "base_class.h"

class NumberNode: public Number {
	public:
		NumberNode();
		NumberNode(float x, NumberNode* next);
		
		NumberNode * next;
};

class TextNode: public Text {
	public:
		TextNode();
		TextNode(char c, TextNode* next);
	//protected:	
		TextNode * next;
};

/*
class TextLLL: public TextNode {
	public:
		TextLLL();
		~TextLLL();

		void display();
		void goNext();
		void restart();
		int get_candy_count() const;
		void add_candy();
		void reset_candy();
	
	private:
		TextNode* head;
		TextNode* currentPos;
		int candy_count;
}
*/
