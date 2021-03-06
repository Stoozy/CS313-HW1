#pragma once

#include <iostream>

using std::cout;
using std::endl;


struct node {
	int data; 	// using int for now
	node * next;
};

class ll_iterator {
	private:
		node * first;
		node * current;
	public:
		ll_iterator();
		node * operator++();		
		void insert(node * n);
		void print();

		
};
