#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include "arr.h"

namespace arr{
    // helper functions for dealing with bitsets
    void clear_bit(u8 * arr, unsigned index){
        arr[index/8] &= ~(1 << (index%8));
        return;
    }
    
    void set_bit(u8 * arr, unsigned index){
        arr[index/8] |= (1 << (index%8));
        return;
    }
    
    void toggle_bit(u8 * arr, unsigned index){
        arr[index/8] ^= (1 << (index%8));
    }
    
    bool check_bit(u8 * arr, unsigned index){
        return arr[index/8] & (1<< (index%8));
    }
    
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
    
    void update_subseq(u8 * arr, int k, int size){
        subsequences.clear();

        std::cout << "Subsequences: { " ;
        for(unsigned i=0; i<size-(k-1); ++i){
            std::string bitstring = "";
            for(unsigned j=i; j<i+k; ++j)
                check_bit(arr, j) ? bitstring.append("1") : bitstring.append("0");

            std::cout << bitstring << " ";
            subsequences.push_back(bitstring);
        }
        std::cout <<  " } " << std::endl << std::endl;
    }
    
    void print_seq(u8 * arr,  int size){
        for(unsigned i=0; i<size; ++i) 
            check_bit(arr, i) ? std::cout << "1" : std::cout << "0";
            //arr[i] ? std::cout << "1" : std::cout << "0";
        std::cout << std::endl;
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
    
    void solve(int size, int sublength){
            
    
        std::cout << "----------------------------" << std::endl;
        std:: cout << "Random subquence length n: " << sublength << std::endl;
        std::cout << "Sequence length (k^n): " << size << std::endl;
    
        std::cout << "----------------------------" << std::endl;
    
        u8 * seq = new u8[size/8];
    
        //bool * seq = new bool[size];
        
        // fill sequence with random boolean values 
        for(unsigned i=0; i<size; ++i){
            rand()%2 ? set_bit(seq, i) : clear_bit(seq, i);
        }
    
        std::cout << "Initial sequence: ";
        print_seq(seq, size);
        update_subseq(seq, sublength, size);
    
        while(!is_db_seq()) {
            // randomly mutate entire sequence here
            for(unsigned i=0; i<size; ++i){
                // 5% probability to toggle current val
                if(rand()%100 < 5)
                    toggle_bit(seq, i);
            }
            
            std::cout << "Checking sequence: ";
            print_seq(seq, size);
            update_subseq(seq, sublength, size);
        }
    
        std::cout << "Found solution: ";
        print_seq(seq, size);
    
        std::cout << "Subsequences: { ";
        for(unsigned i=0; i<subsequences.size(); ++i){
            std::cout << subsequences[i] << " " ;
        }
        std::cout << " } " << std::endl;
    
        delete [] seq;
    }
    
}
