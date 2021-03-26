
Results:
```
A.
A vector with 10,000 random numbers takes 0 milliseconds
A linkedlist with 10,000 random numbers takes 1 milliseconds
Filling a vector with random numbers is faster than a linkedlist.


B.
A vector with 10,000 random strings takes 8 milliseconds
A linkedlist with 10,000 random strings takes 8 milliseconds
Filling a linkedlist with random strings is faster than a vector.


C.
A vector with 10,000 random strings using move semantics takes 8 milliseconds
A linkedlist with 10,000 random strings using move semantics takes 7 milliseconds
Filling a linkedlist with random strings while using move semantics is faster than a vector.
```

Problem 1. Create your own vector and linked list. They should each have all the necessary operations such as insertion, deletion, search, etc. You should create an iterator for them as well. Test the following to see which is faster:
 a. Filling them with random numbers 
b. Filling them with random strings (use ascii) 
c. Doing the above with move semantics when filling with random strings.
  To begin the problem, we must use the timing template that tests how long it takes for a function to be executed. After that we make one vector that is filled with random numbers and one linkedlist that is also filled with random numbers. That completes part a of the problem. Next, we create a function that gets random strings. Then we use that function on a vector and on a linkedlist to finish up part b of the problem. The last part is part c and that is the same as the part that came right before but the only difference was that the move semantics algorithm had been implemented. 
   In the main part of the program we first use a constant size of 1000 for our vectors and linkedlists. The rest of the main is split between the 3 parts of the problem. The functions are all executed and the time is calculated using the time function. Once the time is calculated it is compared and the vector or linkedlists that takes the shortest time is outputted. 
  In the random numbers example, the vector is fasted than filling a linkedlist with random integers. For part b we filled the vector and linkedlist with random strings and the vector was slower this time compared to the linkedlist. And finally in part c it showed that the vector was slower again compared to filling the linkedlists with random strings using move semantics. 
Video Link:  https://share.vidyard.com/watch/S3n7hAxJkMCAgTbKTEeFxa?
