# Binary Differences

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/binary-differences/](https://csacademy.com/contest/archive/task/binary-differences/)  

---

You are given a binary array $A$ of size $N$. We define the cost of a subarray  to be the number of $0$s minus the number of $1$s in the subarray. Find the number of distinct values $K$ such that there is at least one subarray of cost $K$.

### Standard input

The first line contains one integer $N$.

The second line contains $N$ integers ($0$ or $1$) representing the elements of $A$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ The subarray may be empty 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>0 1 0 | 3 | We have $3$ different costs:$[1, 0]$ has cost $0$  $[1]$ has cost $-1$ $[0, 1, 0]$ has cost $1$ |
| 4<br>1 0 0 1 | 4 | $[1, 0]$ has cost $0$ $[1, 0, 0]$ has cost $1$ $[0, 0]$ has cost $2$ $[1]$ has cost $-1$ |
