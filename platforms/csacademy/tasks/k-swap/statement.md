# K Swap

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/k-swap/](https://csacademy.com/contest/archive/task/k-swap/)  

---

You are given an array $A$ of $N$ integers and a number $K$. You are allowed to swap two adjacent elements of $A$ if their absolute difference is not greater than $K$. Find the smallest lexicographical array you can get performing this kind of swaps.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains the $N$ elements of $A$.

### Standard output

Print $N$ values representing the smallest lexicographical array you can get.

### Constraints and notes

$2\leq N \leq 10^5$ $0 \leq K \leq 10^5$ $1 \leq A_i \leq 10^5$

| Input | Output |
| --- | --- |
| 4 2<br>4 3 2 1 | 2 3 4 1 |
| 7 2<br>4 3 2 1 2 3 4 | 2 2 3 3 4 1 4 |
| 10 2<br>4 3 2 1 2 3 4 3 2 1 | 2 2 2 3 3 3 4 1 4 1 |
