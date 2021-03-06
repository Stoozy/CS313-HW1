#include "ll.h"
#include <iostream>

using std::cout;
using std::endl;

ll_iterator::ll_iterator(){
	this->first = nullptr;
}

node * ll_iterator::operator++(){
	// implement ++
}

void ll_iterator::insert( node * n){
	// simple no sort insert
	
	// check for empty list
	if( first == nullptr){
		first = n;
		first->next = nullptr;
		return;
	}
	
	// now insert at the end of list
	node * current = first;
	while(current->next != nullptr)
		current = current->next;

	current->next = n;
	return;
}

void ll_iterator::print(){
	// do a simple print
	if (first == nullptr){
	    cout << "Can't print an empty list ";
	}

	node * current = first;
	while(current != nullptr){
	    if(current->next == nullptr) cout << current->data;
	    else cout << current->data   << " ->" ;
	    current = current->next;
	}
	cout << endl;
}
