#include <iostream>
#include "vigenere.h"
#include "frequency_test.h"
using namespace std;


int main(){
    std::string text, key;

    cout << "Enter text to be encrypted: ";
    cin >> text;
    cout << endl;

    cout << "Enter the key to be used for encryption: " ;
    cin >> key;
    cout <<  endl;

    vigenere v = vigenere();
    v.set_key(key);
    v.set_text(text);

    std::string encrypted = v.encrypt();

    cout << "Encrypted string is: " <<  encrypted << endl;

    // done encrypting
    cout << "Encrypted text is " << encrypted << endl;

    frequency_test ft = frequency_test();
    ft.set_text(encrypted);
    ft.set_keylength(key.size());

    int * occurences = ft.get_occurences();

    cout << "Occurences of each letter: [ ";
    for(int i=0; i<26; ++i) cout << occurences[i] << " ";
    cout << " ]" << endl;

    
    float * freq = ft.run_test();

    cout << "Frequency of each letter: [ ";
    for(int i=0; i<26; ++i){
        cout << freq[i] << " ";
    }
    cout << " ]" <<endl;

    cout << "Key: [ ";
    for(int i=0; i<key.size(); ++i){
        cout << ft.get_max_shift(i) << " ";
    }
    cout << " ]" <<endl;
     
}

