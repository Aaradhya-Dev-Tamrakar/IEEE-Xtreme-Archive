# To Front - To Back

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/to-front-to-back/](https://csacademy.com/contest/archive/task/to-front-to-back/)  

---

You are given a permutation of size $N$. You are allowed to perform the following type of operations:

Move any element to the beginning of the permutationMove any element to the end of the permutation

Sort the permutation using a minimum number of operations.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of the permutation.

### Standard output

On the first line print the minimum number of operations.

On each of the following lines print the value of the chosen element in the current operation followed by a character:

0 if you want to move the number to the beginning of the permutation1 if you want to move the number to the end of the permutation

### Constraints and notes

$1 \leq N \leq 10^5$

| Input | Output |
| --- | --- |
| 6<br>6 1 2 3 4 5 | 1<br>6 1 |
| 6<br>6 3 2 4 5 1 | 3<br>2 0<br>6 1<br>1 0 |
| 3<br>1 2 3 | 0 |
| 5<br>4 1 2 5 3 | 2<br>4 1<br>5 1 |
