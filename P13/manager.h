#pragma once
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

enum JOBTYPE {
    PILOT,
    DRIVER,
    POLICE,
    DOCTOR,
    ENGINEER,
};

struct Job{
    int id;
    JOBTYPE type;
    friend std::ostream& operator<<(std::ostream &o, Job j);
};

struct Worker{
    int id;
    JOBTYPE disliked;
    Job assigned_job;
    friend std::ostream& operator<<(std::ostream &o, Worker w);
    void print_header();
};

std::string job_from_id(int id){

    std::string job = "";
    switch(id){
        case 0 :
            job = "Pilot";
            break;
        case 1 :
            job = "Driver";
            break;
        case 2 :
            job = "Police";
            break;
        case 3 :
            job = "Doctor";
            break;
        case 4 : 
            job = "Engineer";
            break; 
    }

    return job;
}

void Worker::print_header(){
    cout << "+------------+------------+------------+------------+" << endl;
    cout << "| " << setw(10) << "Worker #" << " | " << setw(10) << "Dislikes" << " | " <<  setw(10) << "Job #" << " | " << setw(10) << "Job" << " | " <<endl;
    cout << "+------------+------------+------------+------------+" << endl;
    return;
}

std::ostream& operator<<(std::ostream &o, Worker w) {
    std::string job = job_from_id(w.assigned_job.type);
    o << "| " << setw(10) << w.id  << " | " << setw(10) << job_from_id(w.disliked) << " | " <<  setw(10) << w.assigned_job.id << " | " << setw(10) << job << " | " <<endl;
    o << "+------------+------------+------------+------------+";
    return o;
}

std::ostream& operator<<(std::ostream& o, Job j){
    o  << "Job #" << j.id << " Type:" << j.type;
    return o;
}


