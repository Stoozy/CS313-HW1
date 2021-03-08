#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <math.h>

typedef unsigned char u8;

namespace arr{
    static std::vector<std::string> subsequences;
    
    // helper functions for dealing with bitsets
    
    void clear_bit(u8 * arr, unsigned index);
    
    void set_bit(u8 * arr, unsigned index);
    
    void toggle_bit(u8 * arr, unsigned index);
    
    bool check_bit(u8 * arr, unsigned index);
    
    bool is_duplicate(std::string s);
    
    void update_subseq(u8 * arr, int k, int size);
    
    void print_seq(u8 * arr,  int size);
    
    bool is_db_seq(u8 * arr, int k, int size);
    
    void solve(int size, int sublength);
    
}
