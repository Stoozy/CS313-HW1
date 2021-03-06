#include "ll.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

ll::ll(){
	this->first = nullptr;
}


void ll::insert( node * n){
	// simple no sort insert
	
	// check for empty list
	if( first == nullptr){
		first = n;
		first->next = nullptr;
        this->length++;
		return;
	}
	
	// now insert at the end of list
	node * current = first;
	while(current->next != nullptr){
		current = current->next;
    }

	current->next = n;

    this->length++;
	return;
}


int ll::size(){
    return this->length;
}

void ll::print(){
	// do a simple print
	if (first == nullptr){
	    cout << "Can't print an empty list ";
	}

	node * current = first;
	while(current != nullptr){
	    if(current->next == nullptr) cout << current->data;
	    else cout << current->data;
	    current = current->next;
	}
	cout << endl;
}

namespace list{

    bool is_duplicate(); 

    bool is_db_seq(node * list);

    void update_subseq(node* list, int sublength );

    void solve(){
        int sublength = rand() % 5 +1;
        int size = pow(2, sublength);
        
        cout << "--------------------------------" << endl;
        cout << "Random sequence length n: " << sublength << endl;
        cout << "Sequence length (k^n): " << size << endl;
        cout << "--------------------------------" << endl;
    
        // init empty list
        ll seq;

        for(unsigned i=0; i<size; ++i){
            node * n = new node;
            rand()%2 ? n->data = 1 : n->data = 0; 
            n->next = nullptr;
            seq.insert(n); 
        }
        seq.print(); 
    }
}


