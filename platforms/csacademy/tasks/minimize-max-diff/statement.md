# Minimize Max Diff

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/minimize-max-diff/](https://csacademy.com/contest/archive/task/minimize-max-diff/)  

---

You are given an array $A$ of $N$ integers in nondecreasing order. Remove $K$ integers such that the maximum difference between two consecutive elements is minimized.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers, representing the elements of $A$.

### Standard output

Print a single integer, representing the minimum maximum difference between two consecutive elements after removing $K$ integers.

### Constraints and notes

$3 \leq N \leq 10^5$ $1 \leq K \leq N-2$ $-10^9 \leq A_i \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 1<br>1 2 4 7 8 | 3 | It's possible to obtain the difference $3$ by removing any of the following numbers: $1$, $2$ or $8$ |
| 8 2<br>1 2 3 5 8 13 17 18 | 5 | One possible way to obtain $5$ is to remove elements with value $2$ and $5$ |
| 5 1<br>1 2 4 6 9 | 2 | Removing $9$ gives the best difference. |
