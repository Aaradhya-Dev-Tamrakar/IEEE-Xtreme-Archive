# Pair Swap

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pair-swap/](https://csacademy.com/contest/archive/task/pair-swap/)  

---

You are given an array $A$ of $N$ integers. You are allowed to choose at most one pair of elements such that distance (defined as the difference of their indices) is at most $K$ and swap them. Your goal is to obtain the smallest lexicographical array possible.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

Print $N$ integers on the first line representing the smallest lexicographical array you can obtain.

### Constraints and notes

$1 \le K \leq N \leq 10^5$ $1 \leq A_i \leq 10^5$

| Input | Output |
| --- | --- |
| 5 3<br>5 4 3 2 1 | 2 4 3 5 1 |
| 6 2<br>1 2 3 4 5 1 | 1 2 3 1 5 4 |
| 5 3<br>2 1 1 1 1 | 1 1 1 2 1 |
| 6 1<br>2 3 4 4 4 5 | 2 3 4 4 4 5 |
| 6 3<br>2 3 2 3 2 3 | 2 2 2 3 3 3 |
