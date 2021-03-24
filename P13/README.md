# Problem

Bob has a doubly Linked List, where each spot corresponds to a job that must get done,
aptly named job_1 through job_25. Bob has 25 workers on his team (worker_1 through
worker_25), he has another doubly Linked List that has the name of each worker. He
uses these two lists to assign workers to jobs.
    a. Show how Bob can do this, by creating and running a function that outputs every
worker and their assigned job.
    b. If there is a problem with the assignment, Bob “turns” the list against each other,
such that each worker will be assigned to a previous job. For instance, if
worker_4 were assigned job_4, now worker_4 is assigned job_3, and worker_5 is
assigned job_4. Show how Bob manages his workers to adjust for problems

# Solution

There are two parts to this problem (a and b) and I will discuss them separately below.

## A

For the assignment of jobs to workers, I needed a way to represent workers and jobs in my code. So I created the following structures.

```cpp
    struct Job{
        int id;
        JOBTYPE type;
    };

    struct Worker{
        int id;
        JOBTYPE disliked;
        Job assigned_job;
    };
```

This lets a worker have an assigned job and every job have an id (job # explained in the problem) and a type which I will define below.

```cpp
    enum JOBTYPE {
        PILOT,
        DRIVER,
        POLICE,
        DOCTOR,
        ENGINEER,
    };
```

With this representation of types I can have matching types for workers and jobs. For example a person may not like working as a driver and might be fine with anything else, then Bob can try assigning something else to that worker by turning the lists.



## B

The way I've decided to turn the lists against each other is to rotate one list. The following is what I mean by rotating.

Suppose we have a doubly linked list that looks like the following:
```
    +----+------+ ----> +----+------+ ----> +----+------+
    |  0 |  0x1 |       |  1 |  0x2 |       | 2  |  0x3 | ---> nullptr
    +----+------+ <---- +----+------+ <---- +----+------+
```

I simply put the last element as first and the second to last becomes last.
```
    +----+------+ ----> +----+------+ ----> +----+------+
    |  2 |  0x3 |       |  1 |  0x2 |       | 0  |  0x1 | ---> nullptr
    +----+------+ <---- +----+------+ <---- +----+------+
```

Now I have a different order of assignment of job -> worker.

The output of this program looks something like this
``` 
+------------+------------+------------+------------+
|   Worker # |   Dislikes |      Job # |        Job | 
+------------+------------+------------+------------+
|          0 |     Driver |         24 |     Driver | 
+------------+------------+------------+------------+
|          1 |      Pilot |          0 |     Doctor | 
+------------+------------+------------+------------+
|          2 |     Driver |          1 |     Police | 
+------------+------------+------------+------------+
|          3 |      Pilot |          2 |     Driver | 
+------------+------------+------------+------------+
|          4 |     Doctor |          3 |     Doctor | 
+------------+------------+------------+------------+
|          5 |      Pilot |          4 |     Police | 
+------------+------------+------------+------------+
|          6 |     Doctor |          5 |     Driver | 
+------------+------------+------------+------------+
|          7 |     Driver |          6 |   Engineer | 
+------------+------------+------------+------------+
|          8 |     Police |          7 |      Pilot | 
+------------+------------+------------+------------+
|          9 |   Engineer |          8 |   Engineer | 
+------------+------------+------------+------------+
|         10 |      Pilot |          9 |   Engineer | 
+------------+------------+------------+------------+
|         11 |      Pilot |         10 |   Engineer | 
+------------+------------+------------+------------+
|         12 |   Engineer |         11 |     Doctor | 
+------------+------------+------------+------------+
|         13 |     Police |         12 |   Engineer | 
+------------+------------+------------+------------+
|         14 |     Police |         13 |     Doctor | 
+------------+------------+------------+------------+
|         15 |     Police |         14 |     Police | 
+------------+------------+------------+------------+
|         16 |     Doctor |         15 |   Engineer | 
+------------+------------+------------+------------+
|         17 |     Driver |         16 |     Doctor | 
+------------+------------+------------+------------+
|         18 |     Police |         17 |     Police | 
+------------+------------+------------+------------+
|         19 |     Driver |         18 |   Engineer | 
+------------+------------+------------+------------+
|         20 |     Police |         19 |     Driver | 
+------------+------------+------------+------------+
|         21 |     Police |         20 |     Driver | 
+------------+------------+------------+------------+
|         22 |   Engineer |         21 |     Doctor | 
+------------+------------+------------+------------+
|         23 |     Driver |         22 |     Police | 
+------------+------------+------------+------------+
|         24 |   Engineer |         23 |      Pilot | 
+------------+------------+------------+------------+

Issues found with: 
Worker #2
Worker #9
Worker #12
Worker #14
Worker #16
Worker #19
```
My program checks for which worker doesn't like their jobs and lists them at the end of a new configuration. Bob may not have a perfect list but he can always minimize the number of workers wihtout jobs by turning the list.


After a few configurations the list is minimized:
```
+------------+------------+------------+------------+
|   Worker # |   Dislikes |      Job # |        Job | 
+------------+------------+------------+------------+
|          0 |     Driver |         22 |     Police | 
+------------+------------+------------+------------+
|          1 |      Pilot |         23 |      Pilot | 
+------------+------------+------------+------------+
|          2 |     Driver |         24 |     Driver | 
+------------+------------+------------+------------+
|          3 |      Pilot |          0 |     Doctor | 
+------------+------------+------------+------------+
|          4 |     Doctor |          1 |     Police | 
+------------+------------+------------+------------+
|          5 |      Pilot |          2 |     Driver | 
+------------+------------+------------+------------+
|          6 |     Doctor |          3 |     Doctor | 
+------------+------------+------------+------------+
|          7 |     Driver |          4 |     Police | 
+------------+------------+------------+------------+
|          8 |     Police |          5 |     Driver | 
+------------+------------+------------+------------+
|          9 |   Engineer |          6 |   Engineer | 
+------------+------------+------------+------------+
|         10 |      Pilot |          7 |      Pilot | 
+------------+------------+------------+------------+
|         11 |      Pilot |          8 |   Engineer | 
+------------+------------+------------+------------+
|         12 |   Engineer |          9 |   Engineer | 
+------------+------------+------------+------------+
|         13 |     Police |         10 |   Engineer | 
+------------+------------+------------+------------+
|         14 |     Police |         11 |     Doctor | 
+------------+------------+------------+------------+
|         15 |     Police |         12 |   Engineer | 
+------------+------------+------------+------------+
|         16 |     Doctor |         13 |     Doctor | 
+------------+------------+------------+------------+
|         17 |     Driver |         14 |     Police | 
+------------+------------+------------+------------+
|         18 |     Police |         15 |   Engineer | 
+------------+------------+------------+------------+
|         19 |     Driver |         16 |     Doctor | 
+------------+------------+------------+------------+
|         20 |     Police |         17 |     Police | 
+------------+------------+------------+------------+
|         21 |     Police |         18 |   Engineer | 
+------------+------------+------------+------------+
|         22 |   Engineer |         19 |     Driver | 
+------------+------------+------------+------------+
|         23 |     Driver |         20 |     Driver | 
+------------+------------+------------+------------+
|         24 |   Engineer |         21 |     Doctor | 
+------------+------------+------------+------------+

Issues found with: 
Worker #7
Worker #12
```