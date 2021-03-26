#pragma once

#include <iostream>
using namespace std;

class frequency_test{
    private:
        std::string text;
        int keylength;
        int occurences[26]{0};
        float frequency[26]{0};
        float eng_letter_frequency[26] = 
        {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024,  0.0015, 0.02, 0.00074 };
    public:
        frequency_test(){}

        void set_text(std::string encrypted){
            this->text = encrypted;
        }

        void set_keylength(int l){
            this->keylength = l;
        }

        int * get_occurences(){
            // here we have to calculate 
            // occurences of each letter
            for(int i=0; i<this->text.size(); ++i){
                // increment current 
                // letters occurences
                char c = this->text[i];
                cout << "Current char: " << c << endl;
                this->occurences[(int)(c-65)]++;
            }
            return this->occurences;
        }

        float* get_frequency(){
            for(int i=0; i<26; ++i){
                this->frequency[i] = this->occurences[i]/((float)this->keylength);
            }
            return this->frequency;
        }
        
        float * run_test(){
            this->get_occurences();
            return this->get_frequency();
        } // returns frequency of each letter


        float * shift_left(float * arr, int len){
            int first = arr[0];
            int last = len-1;
            float * ret_arr = new float[len];
            for(int i=0; i<last; ++i){
                ret_arr[i] = arr[i+1];
            }
            ret_arr[last] = first; 
            return ret_arr;
        }
       
            int get_max_shift(int start){
                int shift = 0;
                float max_mult = 0;
                
                // get every keylengths letter
                // example if keylength was 4
                // A X C D E Q N H K
                // A . . . E . . . K
                // get the frequency multiple of the
                // corresponding letters
                float * shift_freq = this->frequency;
                for(int j=0; j<26; ++j){// go over different shifts
                    shift_freq = shift_left(shift_freq, 26);
                    float mult = 0;
                    // go over each letter
                    for(int i=start;i<this->text.length()/this->keylength;i+=this->keylength){
                        char c_index = this->text[i]-65;
                        mult += shift_freq[c_index] * this->eng_letter_frequency[c_index];
                    }

                    if(mult>max_mult){
                        max_mult = mult;
                        shift = j;
                    }
                }

                return shift; 
            }

};
