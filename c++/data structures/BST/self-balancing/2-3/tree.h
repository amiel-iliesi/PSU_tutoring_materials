#pragma once
#include <string>

#ifdef DEBUG_TEST_TREE_INTEGRITY
	#include <set>
#endif

class Tree {
	private:
		//NOTE data are only pointers to represent optional values; XXX use std::optional
		int * data[3];  // NOTE: last data and child are only for transient 4 node
		Tree * children[4];
		Tree * parent;

		void insert(int *);
		void split();
		void merge(Tree *);
	public:
		Tree(): data{nullptr, nullptr},
				children{nullptr, nullptr, nullptr, nullptr},
				parent(nullptr) {}

		Tree(Tree* p): data{nullptr, nullptr},
					   children{nullptr, nullptr, nullptr},
					   parent(p) {}
		
		~Tree();

		#ifdef DEBUG_TEST_TREE_INTEGRITY
			// run tests with `make run_tests`
			void assert_parent_child_relationship() const;
			void assert_key_hierarchy() const;
			void assert_internal_structure() const;
			void assert_size(size_t) const;
			void assert_contents(std::set<int>&) const;
		#endif
		
		size_t size() const;
		bool empty() const;
		bool contains(const int &) const;

		void build(int, int, size_t, bool);

		void insert(const int &);
		void display() const;
		void display(const std::string&, bool, bool, bool) const;
};
