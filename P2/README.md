Question 2
2. Test whether a recursive, iterative or linked-type binary search is faster by testing it on arrays of sizes 1 million and 10 million with arrays that are filled with random numbers. You will need to either fill it in a “sorted way” or sort it before doing the binary search. 

In this program, we are asked to test if a recursive, iterative or linked list binary search is faster by testing on arrays of sizes 1 million and 10 million that are filled with random numbers. In the main function, we make an array with size 1 million and use a for loop to fill it with random numbers. We also make a random target value to see if it is in the array. First we call quicksort to sort the array because we need it sorted to do a binary search. We then call the iterativeBinarySearch. In this function, we split the array in half and check if the target is less than or more then the middle element of the array. If it is more, then the middle value is the new start. Otherwise, the middle value is the new end. Repeating this until the target is found otherwise the function ends with no target found. In the recursive function, we find the middle of the array and test if it is more or less than the target. If it is less, then we call the function again but with mid as end. Otherwise, we call the function again with mid as start. Repeating this until we find the target. In the linked list binary search, we have current node and trailCurrent node to travel through the list. The trailCurrent node goes twice while the current node. This way, we can find the middle of the list. After we find the middle of the list, we check if it is the target. If it is, then the target is found. If the middle of the list is less than the target, then we make start the new mid. Otherwise we can end the new mid. Repeating this until we find target or not find target. We then test the functions on an array of 1 million elements,time then and print results. After that, we test it on 10 million elements, time then and print results.

Since my computer takes a while to do 1 million to 10 million items, I've compared it with only 10000 items. Here are the results I've found

```
Array of size: 10000
Target Number: 6188
Number not found in array.
Number not found in array.
Target not found in the Linked List
Time to complete Iterative Binary Search:7 milliseconds
Time to complete Recursive Binary Search:1 milliseconds
Time to complete Linked List Binary Search:114 milliseconds


Array of size: 10000
Target Number: 7858
Number not found in array.
Number not found in array.
Target not found in the Linked List
Time to complete Iterative Binary Search:9 milliseconds
Time to complete Recursive Binary Search:1 milliseconds
Time to complete Linked List Binary Search:90 milliseconds
```
After a 2-3 hours, the function completed for 1 million elements
Array of size: 1000000
Target Number: 24836
Target number found Iteratively. It is: 24836
Target number found Recursively. It is: 24836
Target number found in Linked List. It is: 24836
Time to complete Iterative Binary Search:902 milliseconds
Time to complete Recursive Binary Search:336 milliseconds
Time to complete Linked List Binary Search:27114 milliseconds
