#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include "arr.h"
#include "ll.h"


int main(){
    srand(time(0));

	
    ll_iterator iter = ll_iterator();
    for(unsigned i=0; i<100; ++i){
        //arr::solve_arr();
	node * n = new node;
	n->data = i;
	n->next = nullptr;

	iter.insert(n);
    }


    iter.print();
    return 0;
}
