#pragma once


class frequency_test{
    private:
        std::string text;
        int occurences[26];
        float frequency[26];
    public:
        frequency_test(){}

        void set_text(std::string encrypted){
            this->text = encrypted;
        }

        void get_occurences(){
            // here we have to calculate 
            // occurences of each letter
            for(int i=0; i<26; ++i){
                // increment current letters
                // occurences
                char c = this->text[i];
                this->occurences[c-65]++;
            }
        }

        void get_frequency(){
            for(int i=0; i<26; ++i){
                this->frequency[i] = this->occurences[i]/((float)this->text.size());
            }
        }
        
        float*  run_test(){
            this->get_occurences();
            this->get_frequency();
            return this->frequency;
        } // returns frequency of each letter

};
