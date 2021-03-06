#pragma once

#include <iostream>

using std::cout;
using std::endl;


struct node {
	int data; 	// using int for now
	node * next;
};

class ll {
	private:
		node * first;
        int length;
	public:
		ll();
		void insert(node * n);
		void print();
        int size();
		
};

namespace list{
    bool is_duplicate();

    bool is_db_seq(node * list);

    void is_db_seq(node * list, int sublength);

    void solve();
}
