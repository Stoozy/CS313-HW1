# Problem

Create a random array of size k. Create a function to check if it is a deBruijn![](https://en.wikipedia.org/wiki/De_Bruijn_sequence) sequence of B(n,k).  If it is not,randomly mutate each spot in the array (from a 0 to 1 or 1 to 0) with a 5% probability,keep doing this until you have found a deBruijn sequence. Do this with an array structure and a linked structure. Do this 100 times for each, time it, and compare your results

# Solution


Array version:

    1. Get user input for order n and size k for a sequence B(n, k)
    2. Generate random values from 0 to 1 (boolean) for each item in the sequence
    3. Check if sequence is a deBruijn sequence but checking every contiguous subsequence of length n is unique.
    4. if it's not a deBruijn, mutate each value with a probability of 5%
    5. repeat steps 4 and 3 until a solution is reached.

