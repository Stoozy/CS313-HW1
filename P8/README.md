# Problem 8

## Problem

Create a class that effectively finds all possibilities of a list of random numbersthat adds to some s.  In other words, create a class that asks the user for the size of anarray and for some number s.  Fill in the array with random numbers.  Create function(s)to solve for every possible output that sums to the number s.  For instance, if yourrandom list were {1,2,4,6,9,9,7,11,16} and s = 18, then you should output (11,7) (9,9)(11,4,2,1) (16,2) (11,6,1) (9,7,2) (9,6,2,1) (7,6,4,1).

## Solution

For every number build a sequence including that number and not including that number. When including the number we can subtract from the total sum wanted (because it is added), and sum stays the same when if it's not added. When leftover sum is 0 then we have found a solution.


Let's test this algorithm out on this list {1, 2, 4, 6} with wanted sum 6:
(1 means include and 0 means exclude) every node is a leftover sum

                             6
                      1(6) /   \ 0(6)
                 solution 0      6
                          1(4) /    \ 0 (4)
                              2       6 
                        1(2) / \ 0(2)   .
                   solution 0   .        .
                                 .


We can write a recursive method for this where the base cases are if set is empty return and if leftover sum is 0 which means we have reached a solution. There should be 2 recursive calls, one where the subset includes the current integer and one where it is excluded.

TODO:
    Ask prof what to do about duplicates.

