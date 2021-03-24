#pragma once
#include "manager.h"

using std::cout;
using std::endl;

template <class T>
struct node {
    T data;
    node<T> * next;
    node<T> * prev;
};

template <class T> 
class dll {
    private:
        int size;
        node<T> * list;
    public:

    dll() {
        this->size = 0;
    }
    
    void print(){
        // cannot print empty list
        if(this->size == 0 ) return;
    
        node<T> * current_node = this->list;
    
        while(current_node->next != nullptr){
            cout << current_node->data << endl;
            current_node = current_node->next;
        }
        cout << current_node->data << endl;
    
    }
    
    void insert_tail(T i){
        node<T> * n = new node<T>;
        n->data = i;
    
        if(this->size == 0) {
            this->list = n;
            this->size++; 
            return;
        }else{
            node<T> * current_node = this->list;
    
            while(current_node->next != nullptr)
                current_node = current_node->next;
    
            // we are now at the tail
            // and may insert
            n->prev = current_node;
            current_node->next = n;
    
            // return list to it's pointer
            //this->list = list_ptr;
            this->size++; 
        }
    
    }
    
    int length(){
        return this->size;
    }

};
