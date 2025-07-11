#include <cstddef>

class ARR {
	private:
		struct Node {
			int data;
			Node* next;

			Node(int data, Node* next=nullptr);
		};

		Node** array;
		std::size_t size;

	public:
		ARR(std::size_t arr_size_min = 3,
			std::size_t arr_size_var = 2,
			std::size_t list_size_min = 5,
			std::size_t list_size_var = 10,
			int data_min = 0,
			int data_max = 9);
		~ARR();

		void display() const;
};
