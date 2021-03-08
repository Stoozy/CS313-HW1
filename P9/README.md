# Problem

Create a random array of size k. Create a function to check if it is a deBruijn![](https://en.wikipedia.org/wiki/De_Bruijn_sequence) sequence of B(n,k).  If it is not,randomly mutate each spot in the array (from a 0 to 1 or 1 to 0) with a 5% probability,keep doing this until you have found a deBruijn sequence. Do this with an array structure and a linked structure. Do this 100 times for each, time it, and compare your results

# Solution

This problem requires a solution that uses an array implementation and a solution that uses linked list implementation. I have descriptions for both in this readme.


## Array:

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

So instead of using entire 8 bits to store one boolean value, I am  using each bit to store a boolean. This uses 1/8th of the space.

Let's see an example,

    (Boolean sequence)
    true        false       true        true
    00000001    00000001    00000001    00000001 ...

    (Bit sequence)
    1011 ...


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

       


With this I can get the contiguous subsequences and store them in the subsequences list ( there are (k*^n - (n-1)) contiguous subsequences. I can simply iterate over them and add the subsequence to the subsequences list.

        In this example, k = 2, n = 3, k^n (sequence length) = 8 which means there are (8-(3-1)) = 6 contiguous subsequences

        10101011
        
        Subsequence #1: 101
        Subsequence #2: 010
        Subsequence #3: 101
        Subsequence #4: 010
        Subsequence #5: 101
        Subsequence #6: 011
        
        We can see that this is definitely not a debruijn sequence by checking if any of the subsequences repeat.
        

Now I can just check if it's a debruijn sequence or not.




## Linked List: 


The linked list version follows the same algorithm as the array version. Except that it uses a linked list instead of an array as its data structure:

        1. Generate a random n (size of subsequence) (I've limited this to 1 to 6; 
        2. Generate random values from 0 to 1 (boolean) for each item in the sequence
        3. Check if sequence is a deBruijn sequence by checking every contiguous subsequence of length n is unique.
        4. if it's not a deBruijn sequence, mutate each value with a probability of 5%
        5. repeat steps 4 and 3 until a solution is reached.

Every node has a boolean and a reference to the next boolean ( The reason for booleans is because k is locked at 2 as per the instructions of the problem ).

This is the structure of the linked list

        <index> : <val> -> <next-node>

        So 1010 would look like
    
        0 : 1 -> 1 : 0 -> 2 : 1 -> 3 : 0 -> nullptr

The algorithm I am using requires that I know the value at position i of the list, therefore I made a simple `at` function that returns the value of the node at index i.
The pseudocode for this looks something like this: 
    ```cpp
        T at(int pos){
            int counter = 0;
            Node * current = this->first;
            while current == nullptr {
                if counter == pos {
                    return current->value;
                }
                current = current->next;
                counter++;
            }
            
        }
    ```

It simply iterates over the list until a counter has reached the index ( the counter increments every iteration of course).

The rest is basically the same as the array implementation: store all contiguous subsequences, check for repetition.

Let's see an example

    List: 

       1100: 0:1 -> 1:1 -> 2:0 -> 3:0 

       Subsequence #1: 11
       Subsequence #2: 10
       Subsequence #3: 00

       As you can see, every item in the subsequences list is unique and therefore the original sequence is a debruijn sequence.





