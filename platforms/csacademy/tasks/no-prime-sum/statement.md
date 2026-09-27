# No Prime Sum

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/no-prime-sum/](https://csacademy.com/contest/archive/task/no-prime-sum/)  

---

You are given a set $S$ of $N$ distinct integers. Find the minimum number of values you need to remove from the set such that the sum of any two numbers left in $S$ is not a prime.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ integers in $S$.

### Standard output

The first line contains a single integer $M$, representing the minimum number of elements you remove.

The second line contains the $M$ integers you remove from the set.

### Constraints and notes

$2 \leq N \leq 2000$ The elements of $S$ are distinct integers between $1$ and $10^5$

| Input | Output |
| --- | --- |
| 4<br>1 2 4 23 | 1<br>1 |
| 5<br>5 4 11 7 2 | 2<br>7 2 |
| 5<br>6 9 12 21 15 | 0 |
| 3<br>2 7 11 | 1<br>11 |
