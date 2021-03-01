#include <iostream>
#include "sumrand.h"

int main() {
    srand(time(NULL));
    
    int intarr[9] = { 1, 2, 4, 6, 9, 9, 7, 11, 16};
    double doublearr[9] = { 1.25, 2, 4.75, 6, 9, 9, 7, 11, 16};
    float floatarr[9] = { 1.25, 2.25, 4.75, 3.5, 9, 9, 7, 11, 16};

    sumrand<int> sr;
    sr.get_input();

    // for testing purposes
    //sr.set_rand_list(intarr, 9);
    //sr.set_rand_list(doublearr, 9);
    //sr.set_rand_list(floatarr, 9);
    
    sr.display_rand_list();
    sr.solve();
    sr.display_output();
    
    return 0;
}
