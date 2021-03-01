#include "sumrand.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

template <>
sumrand<int>::sumrand(){ }

template <>
sumrand<double>::sumrand(){ }

template <>
sumrand<float>::sumrand(){ }


template <>
int* sumrand<int>::get_input(){
    cout << "Enter the size of the array: " << endl;
    cin >> this->size;

    this->rand_list = new int[this->size];

    cout << "Enter the sum you want: " << endl;
    cin >> this->sum;


    for(unsigned i=0; i<size; ++i){
        this->rand_list[i] = rand()%100+1;
    }

    return this->rand_list;
}

template <>
double * sumrand<double>::get_input(){
    cout << "Enter the size of the array:: " << endl;
    cin >> this->size;

    this->rand_list = new double[this->size];
    cout << "Enter the sum you want: " << endl;
    cin >> this->sum;

    for(unsigned i=0; i<size; ++i){
        double d = (double) rand() / RAND_MAX;
        this->rand_list[i] = ((double)(rand()%100) + d);
    }
    return this->rand_list;
}

template <>
float *  sumrand<float>::get_input(){
    cout << "Enter the size of the array:: " << endl;
    cin >> this->size;

    this->rand_list = new float[this->size];

    cout << "Enter the sum you want: " << endl;
    cin >> this->sum;

    for(unsigned i=0; i<size; ++i){
        float f = (float) rand() / (float)RAND_MAX;
        this->rand_list[i] = (float) (rand()%100 + (1/rand()%100));
    }

    return this->rand_list;
}


template<>
void sumrand<int>::display_rand_list(){
    cout << "Generated random list:  "<< endl;

    for(unsigned i=0; i<this->size; i++){
        cout << this->rand_list[i]  << " ";
    }
    cout << endl; 
}


template<>
void sumrand<double>::display_rand_list(){
    for(unsigned i=0; i<this->size; i++){
        cout <<  this->rand_list[i]  << " ";
    }
    cout << endl; 
}


template<>
void sumrand<float>::display_rand_list(){
    for(unsigned i=0; i<this->size; i++){
        cout << this->rand_list[i]  << " ";
    }
    cout << endl; 
}

template<class T>
std::vector<std::vector<T>> sumrand<T>::get_result(){
    return this->out_list;
}

template<>
void sumrand<int>::solve(){
    std::vector<int> filtered_rand_vec, subset_vec;
    // get rid of smaller numbers than sum
    for(unsigned i=0; i<this->size; ++i){
        if(rand_list[i] < this->sum) {
            filtered_rand_vec.push_back(this->rand_list[i]);
            subset_vec.push_back(this->rand_list[i]);
        }
    }
    // new size
    this->size = filtered_rand_vec.size();

    int * filtered_list = new int[this->size];
    int * subset_list = new int[this->size];

    cout << "Filtered list: ";
    for(unsigned i=0; i<this->size; ++i){
        filtered_list[i] = filtered_rand_vec[i];
        subset_list[i] = subset_vec[i];
        cout << filtered_list[i] << " ";
    }
    cout << endl;

    // we have no need for this anymore
    delete [] this->rand_list;

    // solve
    this->find_subsets(filtered_list, subset_list, this->size, this->sum);
}


template<>
void sumrand<double>::solve(){
    std::vector<double> filtered_rand_vec, subset_vec;
    // get rid of smaller numbers than sum
    for(unsigned i=0; i<this->size; ++i){
        if(rand_list[i] < this->sum) {
            filtered_rand_vec.push_back(this->rand_list[i]);
            subset_vec.push_back(this->rand_list[i]);
        }
    }
    // new size
    this->size = filtered_rand_vec.size();
    
    double * filtered_list = new double[this->size];
    double * subset_list = new double[this->size];

    for(unsigned i=0; i<this->size; ++i){
        filtered_list[i] = filtered_rand_vec[i];
        subset_list[i] = subset_vec[i];
    }

    // we have no need for this anymore
    delete [] this->rand_list;

    // solve
    this->find_subsets(filtered_list, subset_list, this->size, this->sum);
}


template<>
void sumrand<float>::solve(){
    std::vector<float> filtered_rand_vec, subset_vec;
    // get rid of smaller numbers than sum
    for(unsigned i=0; i<this->size; ++i){
        if(rand_list[i] < this->sum) {
            filtered_rand_vec.push_back(this->rand_list[i]);
            subset_vec.push_back(this->rand_list[i]);
        }
    }
    // new size
    this->size = filtered_rand_vec.size();

    float * filtered_list = new float[this->size];
    float * subset_list = new float[this->size];

    for(unsigned i=0; i<this->size; ++i){
        filtered_list[i] = filtered_rand_vec[i];
        subset_list[i] = subset_vec[i];
    }

    // we have no need for this anymore
    delete [] this->rand_list;

    // solve
    this->find_subsets(filtered_list, subset_list, this->size, this->sum);
}


template<>
void sumrand<int>::display_output(){
    for(unsigned i=0; i<this->out_list.size(); ++i){
        cout << "Solution Subset: { ";
        for(unsigned j=0; j<this->out_list[i].size(); ++j){
            cout << this->out_list[i][j] << " ";
        }
        cout << "}" << endl;
    }
}


template<>
void sumrand<double>::display_output(){
    for(unsigned i=0; i<this->out_list.size(); ++i){
        cout << "Solution Subset: { ";
        for(unsigned j=0; j<this->out_list[i].size(); ++j){
            cout << this->out_list[i][j] << " ";
        }
        cout << "}" << endl;
    }
}


template<>
void sumrand<float>::display_output(){
    for(unsigned i=0; i<this->out_list.size(); ++i){
        cout << "Solution Subset: { ";
        for(unsigned j=0; j<this->out_list[i].size(); ++j){
            cout << this->out_list[i][j] << " ";
        }
        cout << "}" << endl;
    }
}


template<class T>
void sumrand<T>::find_subsets(T * arr, T * subset, int n, T sum){
    if (sum == 0){
        // found a solution 
        std::vector<T> solution;
        for(unsigned i=n; i<this->size; ++i)
            if (subset[i] != 0) solution.push_back(subset[i]);
        this->out_list.push_back(solution);
        return;
    }
    // empty set
    if (sum != 0 && n == 0) return;

    // copy array into subset 
    for(unsigned i=0; i<n; ++i){
        subset[i] = arr[i];
    }
    
    // include last element
    this->find_subsets(arr, subset, n-1, sum-arr[n-1]);
    // exclude last element
    subset[n-1] = 0;
    this->find_subsets(arr, subset, n-1, sum);
}

// for testing only
template<>
void sumrand<int>::set_rand_list(int * arr, int size){
    for(unsigned i=0; i<size; ++i)
        this->rand_list[i] = arr[i];
}

template<>
void sumrand<double>::set_rand_list(double * arr, int size){
    for(unsigned i=0; i<size; ++i)
        this->rand_list[i] = arr[i];
}

template<>
void sumrand<float>::set_rand_list(float * arr, int size){
    for(unsigned i=0; i<size; ++i)
        this->rand_list[i] = arr[i];
}




