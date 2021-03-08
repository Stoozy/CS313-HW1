#pragma once

#include <iostream>
#include <vector>

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
        int at(int i);
        bool is_empty();
        node * head();
		
};

namespace list{
    static std::vector<std::string> subsequences;

    bool is_duplicate();
    
    bool is_db_seq();

    void update_subseq(ll seq, int size, int sublength);

    void solve();
}
