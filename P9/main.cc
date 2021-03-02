#include <iostream>
#include <vector>
#include <random>

// TODO:  linked list version (and try using bitsets)
static std::vector<std::string> subsequences;

bool is_duplicate(std::string s){
    int counter =0;
    for(unsigned i=0; i<subsequences.size(); ++i){
        if (subsequences[i] == s)
            ++counter;
    }
    // there should be only one copy of the bitstring
    return counter >= 2;
}


void update_subseq(bool * arr, int k, int size){
    subsequences.clear();
    std::cout << "Subsequences: { " ;
    for(unsigned i=0; i<size-k; ++i){
        std::string bitstring = "";
        for(unsigned j=i; j<i+k; ++j){
            arr[j] ? bitstring.append("1") : bitstring.append("0");
        }
        std::cout << bitstring << " ";
        subsequences.push_back(bitstring);
    }
    std::cout <<  " } " << std::endl << std::endl;
}

void print_seq(bool * arr,  int size){
    for(unsigned i=0; i<size; ++i) 
        arr[i] ? std::cout << "1" : std::cout << "0";
    std::cout << std::endl;
}

bool is_db_seq(bool * arr, int k, int size){
    for(unsigned i=0; i<subsequences.size(); ++i){
        if(is_duplicate(subsequences[i])){
            return false;
        }
    }
    return true; 
}


int main(){
    srand(time(0));
    int size, sublength;

    std::cout << "Enter size k: " << std::endl;
    std::cin >> size;

    std::cout << "Enter order n: " << std::endl;
    std::cin >> sublength;

    bool * seq = new bool[size];
    
    // fill array with random bool values 
    for(unsigned i=0; i<size; ++i){
        seq[i] = rand()%2;
    }

    std::cout << "Initial sequence: ";
    print_seq(seq, size);
    update_subseq(seq, sublength, size);

    while(!is_db_seq(seq, sublength, size)) {
        // randomly mutate entire sequence here
        for(unsigned i=0; i<size; ++i){
            // 5% probability to toggle current val
            if(rand()%100 < 5)
                seq[i] = !seq[i];
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

    return 0;
}
