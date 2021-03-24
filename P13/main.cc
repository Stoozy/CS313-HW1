#include <iostream>
#include "dll.h"
#include "manager.h"

using std::cout;
using std::endl;

int main(){
    srand(time(0));

    dll<Worker> workers = dll<Worker>();
    dll<Job> jobs = dll<Job>();

    for(int i=0; i<25; ++i){
        Job cj = Job{i, JOBTYPE(rand()%5)};
        Worker cw = Worker{i, JOBTYPE(rand()%5), cj};

        workers.insert_tail(cw);
        jobs.insert_tail(cj);
    }

    workers.print();

    cout << "list length: " << workers.length() << endl;
}

