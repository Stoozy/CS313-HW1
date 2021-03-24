#pragma once
#include <iostream>

using std::cout;
using std::endl;

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

std::ostream& operator<<(std::ostream &o, Worker w) {
    std::string job = job_from_id(w.id);
    o  << "Worker #" << w.id << " (Won't work as: " << job_from_id(w.disliked) << ") -> Job #" << w.assigned_job.id << ": " << job;

    return o;
}

std::ostream& operator<<(std::ostream& o, Job j){
    o  << "Job #" << j.id << " Type:" << j.type;
    return o;
}


