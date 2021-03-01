#pragma once

#include <vector>

template <class T> 
class sumrand {

private:
    int size;
    T sum;
    T * rand_list;
    std::vector<std::vector<T>> out_list;
public:
    sumrand();

    T * get_input();
    void solve();
    std::vector<std::vector<T>> get_result();
    void display_rand_list();
    void display_output(); 
    void find_subsets(T * arr, T * subset, int size, T sum);
    void set_rand_list(T * arr, int size);
};
