#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include "arr.h"
#include "ll.h"

using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

template <typename func>
long long time_func(func f, int size, int sublength){

	auto begin = steady_clock::now();
    list::solve(size, sublength);
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();

}

int main(){
    srand(time(0));
    long long arr_total, list_total;

    for(int i=0; i<100; ++i){
        int sublength = rand() % 5+1;
        int size = pow(2, sublength);

        auto listmilliseconds = time_func(list::solve, size, sublength);
        auto arrmilliseconds = time_func(arr::solve, size, sublength);

        arr_total += arrmilliseconds;
        list_total += listmilliseconds;
    }


    cout << "--------------------------------" << endl;
    cout << "Results:                        " << endl;
    cout << "   Average array time: " << arr_total/100 << "ms " << endl;
    cout << "   Average list time: " << list_total/100 << "ms " << endl;
    cout << "--------------------------------" << endl;

}


