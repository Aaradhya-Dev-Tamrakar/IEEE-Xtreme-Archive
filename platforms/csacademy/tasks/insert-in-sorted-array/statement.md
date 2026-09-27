# Insert in Sorted Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/insert-in-sorted-array/](https://csacademy.com/contest/archive/task/insert-in-sorted-array/)  

---

You are given a sorted array $A$ of $N$ distinct integers. You are also given an integer $X$ that does not occur in $A$.

You should insert $X$ in $A$ such that $A$ stays sorted. Find the index of $X$.

### Standard input

The first line contains two integers $N$ and $X$.

The second line contains the $N$ elements of $A$.

### Standard output

Print the index of $X$ on the first line.

### Constraints and notes

$1 \leq N \leq 1000$ $0 \leq A_i, X \leq 1000$ The elements of $A$ are sorted in increasing order

| Input | Output | Explanation |
| --- | --- | --- |
| 2 2<br>1 3 | 2 | $1\ \underline{2}\ 3$ |
| 2 0<br>1 3 | 1 | $\underline{0}\ 1\ 3$ |
| 5 6<br>1 2 3 5 8 | 5 | $1\ 2\ 3\ 5\ \underline{6}\ 8$ |
