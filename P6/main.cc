#include <iostream>

using namespace std;




int main(){
    std::string text, key;

    
    char v[26][26] = {
        {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
        {'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A'},
        {'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B'},
        {'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'},
        {'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D'},
        {'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E'},
        {'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F'},
        {'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G'},
        {'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H'},
        {'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I'},
        {'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J'},
        {'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K'},
        {'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L'},
        {'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'},
        {'O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N'},
        {'P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'},
        {'Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'},
        {'R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q'},
        {'S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'},
        {'T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'},
        {'U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'},
        {'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'},
        {'W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'},
        {'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'},
        {'Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'},
        {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'}

    };

    //for(int i=0; i<26; ++i){
    //    for(int j=0; j<26; ++j){
    //        cout << c[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << "Enter text to be encrypted: ";
    cin >> text;
    cout << endl;

    cout << "Enter the key to be used for encryption: " ;
    cin >> key;
    cout <<  endl;

    std::string fullkey;
    for(int i=0; i<text.size()/key.size(); ++i){
        fullkey += key;
    }
    if(text.size()%key.size() != 0){
        for(int i=0; i<text.size()%key.size();++i){                
            fullkey += key[i];
        }
    }
    cout << "Full key is " << fullkey << endl;

    // here fullkey's length = text length
    std::string encrypted;
    for(int i=0; i<text.size(); ++i){        
        encrypted +=  v[text[i]-65][fullkey[i]-65];
    }

    // done encrypting
    cout << "Encrypted text is " << encrypted << endl;


    std::string ecopy;
    ecopy = encrypted;

    int arr[encrypted.size()-1];
    ecopy.pop_back();
    ecopy.insert(0, " ");
    for(int i=0; i<encrypted.size(); ++i){
        int matches = 0;
        for(int j=0; j<ecopy.size(); ++j){
            // check if encrypted 
            // and ecopy are equal (j)
            if(encrypted[j] == ecopy[j]){                    
                ++matches;
            }
        }
        arr[i] = matches;

        ecopy.pop_back();
        ecopy.insert(0, " " );
    }
    
    cout << "[ ";
    for(int i=0; i<encrypted.size()-1; ++i){
        cout << arr[i] << " ";
    }

    cout << "]" << endl;
}

