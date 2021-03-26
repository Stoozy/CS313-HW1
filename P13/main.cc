#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <time.h>
#include "dll.h"
#include "manager.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ostringstream;

int main(){
    srand(time(0));

    dll<Worker> workers = dll<Worker>();
    dll<Job> jobs = dll<Job>();

    for(int i=0; i<25; ++i){
        Job cj = Job{i, JOBTYPE(rand()%5)};
        Worker cw = Worker{i, JOBTYPE(rand()%5), cj};
        if(i == 0){
            cw.print_header();
        }

        workers.insert_tail(cw);
        jobs.insert_tail(cj);
    }
    workers.print();
    // filled up lists
    // now try different configurations
    char c = ' ';
    cout << "Would you like a new configuration? (Y/N)";
    cin >> c;
    while(c == 'Y' ||  c == 'y'){
        // generate new configuration here
        
        // rotating jobs
        jobs.rotate();
        node <Worker> * worker_node = workers.first();


        // pretty printing
        worker_node->data.print_header();

        vector<std::string> issues;

        node <Job> * job_node = jobs.first();

        // go over workers and assign new jobs
        while(worker_node != nullptr && job_node != nullptr){
            if(worker_node->data.assigned_job.type == worker_node->data.disliked){
                std::string issue = "Worker #" ;
                issue+= std::to_string(worker_node->data.id);
                issues.push_back(issue);
            }

            // assign job here
            worker_node->data.assigned_job = job_node->data;
            job_node = job_node->next;
            worker_node = worker_node->next;
        }

        workers.print();

        if(issues.size() == 0){
            cout << "No issues found!" << endl;
        }else{
            cout << "Issues found with: " << endl;
            for(int i=0; i<issues.size(); ++i){
                cout << issues[i] << endl;
            }
        }

        cout << "Would you like a new configuration? (Y/N)";
        cin >> c;
    }

    return 0;
}

