#include "ll.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

ll::ll(){
	this->first = nullptr;
}

bool ll::is_empty(){
    return this->length == 0;
}
int ll::at(int i){
    if(this->is_empty()){
        cout << "Cannot get item at " << i << ": List is empty" << endl;
        return -1;
    }
    
    int counter = 0;
    node * current = first;
    while(current != nullptr ){
        if(counter == i)
            return current->data;
        current = current-> next;
        counter++;
    }

    cout << "Item " << i << " does not exist." << endl;
    return -1;
}

node * ll::head(){
    return this->first;
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
	    if(current->next == nullptr) cout << (int)current->data;
	    else cout << (int)current->data;
	    current = current->next;
	}
	cout << endl;
}

namespace list{

    bool is_duplicate(std::string s){
        int counter = 0;
        for(unsigned i=0; i<subsequences.size(); ++i){
            if (subsequences[i] == s)
                ++counter;
            // don't need to do unnecessary accesses
            // just return as soon as a duplicate is found
            if (counter==2) return true;
        }
        // there should be only one copy of the bitstring
        return false;

    }

    bool is_db_seq(){
        // if there is a repeating subsequence
        // it's not a debruijn sequence
        // otherwise, it is a debruijn sequence
        for(unsigned i=0; i<subsequences.size(); ++i){
            if(is_duplicate(subsequences[i])){
                return false;
            }
        }
        return true; 

    }

    void update_subseq(ll list, int size, int sublength){
        subsequences.clear();

        std::cout << "Subsequences: { " ;
        // there are size-sublength contiguous subarrays
        for(unsigned s=0; s<(size-(sublength-1)); ++s){
            std::string str = "";
            for(unsigned n=0; n<sublength; ++n)
                list.at(s+n) ? str.append("1") : str.append("0");
            cout << str << " ";
            subsequences.push_back(str);
        }
        cout << " }" << endl << endl;
    }

    void solve(int size, int sublength){
        
        cout << "--------------------------------" << endl;
        cout << "Random sequence length n:       " << sublength << endl;
        cout << "Sequence length (k^n):          " << size << endl;
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
        update_subseq(seq, size, sublength);

        while(!is_db_seq()){
            // randomly mutate the sequence based on a 5% probability
            node * current = seq.head();
            while(current != nullptr){
                if(rand()%100 < 5)
                    current->data = !current->data; 
                current = current->next;
            }
            // print and update subsequences list
            
            std::cout << "Checking sequence: ";

            seq.print();
            update_subseq(seq, size, sublength);
        }
    
        // found a solution
        // print sequence
        std::cout << "Found solution: ";
        seq.print();

        std::cout << "Subsequences: { ";
        for(unsigned i=0; i<subsequences.size(); ++i){
            std::cout << subsequences[i] << " " ;
        }
        std::cout << " } " << std::endl;
    }

}


