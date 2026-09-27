# Vector Size

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/vector-size/](https://csacademy.com/contest/archive/task/vector-size/)  

---

In this problem we consider a vector that is initially empty. You are given $N$ operations of two types:

Push - we insert an element at the end of the arrayPop - we remove the last element of the array. If the array is empty this operation has no effect.

Given the list of operations, find the maximum size of the array at any given moment.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers corresponding to the operations. A push is represented by $1$, while a pop by $0$.

### Standard output

Print a single integer representing the maximum size of the array at any given moment.

### Constraints and notes

$1 \leq N \leq 1000$ 

| Input | Output |
| --- | --- |
| 6<br>1 1 0 1 1 0 | 3 |
| 7<br>1 1 0 0 0 0 1 | 2 |
| 5<br>1 0 0 1 1 | 2 |
