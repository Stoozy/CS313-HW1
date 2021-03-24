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

    node<T> * first(){
        return this->list;
    }
    
    void rotate(){
        // put last item as first and second to last as last
        //node<T> * first = this->list;
        node<T> * last = this->list; 
        while(last->next != nullptr ){
            last = last->next;
        }
        // clear next node so that it can
        // be moved to the front 
        node<T> * second_to_last = last->prev;
        second_to_last->next = nullptr;

        // putting last element as first
        last->prev = nullptr;
        last->next = this->list;
        this->list = last;
    }

    int length(){
        return this->size;
    }

};
