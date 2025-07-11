#include <iostream>

using namespace std;

const int SIZE = 15;

class Stack {
	private:
		int array[SIZE];
		int top_index;

	public:
		Stack() {
			top_index = -1;
		}

		bool empty() const {
			return (top_index < 0);
		}

		int size() const {
			return top_index+1;
		}

		bool push(int data) {
			if (top_index == SIZE-1) { //we're out of room
				return false;
			}

			array[++top_index] = data;
			return true;
		}

		bool pop() {
			if (top_index < 0) { //nothing to pop
				return false;
			}

			--top_index;
			return true;
		}

		int top() const {
			return array[top_index];
		}
};

int main()
{
	Stack int_stack;

	for (int n: {1,2,3,4,5}) {
		int_stack.push(n);
	}

	cout << "stack contains: ";
	while (not int_stack.empty()) {
		cout << int_stack.top() << ' ';
		int_stack.pop();
	}
	cout << endl;

	return 0;
}
