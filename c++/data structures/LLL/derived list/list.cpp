#include "list.h"

NumberNode::NumberNode(): next(nullptr) {}
NumberNode::NumberNode(float x, NumberNode* next): Number(x), next(next) {}

TextNode::TextNode(): next(nullptr) {}
TextNode::TextNode(char c, TextNode* next): Text(c), next(next) {}
