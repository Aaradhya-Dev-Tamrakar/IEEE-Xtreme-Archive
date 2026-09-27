# Recursive Arrays

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/recursive-arrays/](https://csacademy.com/contest/archive/task/recursive-arrays/)  

---

You have an array $A$ of size $N$, $1 \leq A[i] \leq N$ for all $i$. You repeat the following process indefinitely:

Build a new array $B$, such that $B[i]=A[A[i]]$ Make $A$ equal to $B$.

What's the number of distinct arrays $A$ you get?

### Standard input

The first line contains a single integer $N$.

The second line contains the elements of $A$.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>2 3 1 4 | 2 | The arrays are2 3 1 43 1 2 4 |
| 4<br>3 2 4 2 | 3 | The arrays are3 2 4 24 2 2 22 2 2 2 |
| 4<br>4 3 1 2 | 3 | The arrays are4 3 1 22 1 4 31 2 3 4 |
| 12<br>2 6 5 1 11 10 9 12 4 7 8 3 | 12 |  |
