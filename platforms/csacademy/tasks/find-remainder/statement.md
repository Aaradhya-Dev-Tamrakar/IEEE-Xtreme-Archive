# Find Remainder

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/find-remainder/](https://csacademy.com/contest/archive/task/find-remainder/)  

---

You are given two arrays $A$ and $B$ of length $N$. Suppose $B_i = A_i \ \text{mod} \ K$ for all $1 \leq i \leq N$. Find the smallest possible $K > 0$ or output $-1$ if there isn't any.

### Standard input

The first line contains an integer $N$.

The second line contains $N$ integers representing the elements of $A$.

The third line contains $N$ integers representing the elements of $B$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i, B_i \leq 10^9$ 

| Input | Output |
| --- | --- |
| 6<br>28 6 45 27 15 24<br>3 1 0 2 0 4 | 5 |
| 4<br>71 25 75 82<br>14 21 59 69 | -1 |
| 8<br>106 143 127 124 24 62 41 162<br>2 3 3 0 0 2 1 2 | 4 |
