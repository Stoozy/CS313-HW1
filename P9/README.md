# Problem

Create a random array of size k. Create a function to check if it is a deBruijn![](https://en.wikipedia.org/wiki/De_Bruijn_sequence) sequence of B(n,k).  If it is not,randomly mutate each spot in the array (from a 0 to 1 or 1 to 0) with a 5% probability,keep doing this until you have found a deBruijn sequence. Do this with an array structure and a linked structure. Do this 100 times for each, time it, and compare your results

# Solution


Array version:

1. Generate a random n (size of subsequence) (I've limited this to 1 to 6; 
2. Generate random values from 0 to 1 (boolean) for each item in the sequence
3. Check if sequence is a deBruijn sequence by checking every contiguous subsequence of length n is unique.
4. if it's not a deBruijn sequence, mutate each value with a probability of 5%
5. repeat steps 4 and 3 until a solution is reached.

    
I've decided to keep a vector of strings called subsequences where each string is a bit string.

For example, if length n was 3 it might look something like this:

        0: "000"
        1: "010"
        2: "110"
        ...

I use this list to make sure no subsequence shows up more than once, if it does, then the entire sequence is not a debruijn sequence. In this array implementation I've kept the sequence as an actual sequence of bits. 

I can use simple bitwise operations to check if a bit is set, toggle a bit, set a bit, clear a bit, etc;

Let's see an example with a subsequence length of 3, meaning the sequence size is 8 (2^n). Imagine the random sequence is the following
    

        11010100
    
        we can check if bit 3 is set by bitwise anding it with this
        00100000

          11010100
        & 00100000
        ----------
          00000000 -> false

        Let's check if bit 2 is set
 
          11010100
        & 01000000
        ----------
          01000000 -> true

       


With this I can get the subsequences and store them in the subsequences list. Now I can just check if it's a debruijn sequence or not.

