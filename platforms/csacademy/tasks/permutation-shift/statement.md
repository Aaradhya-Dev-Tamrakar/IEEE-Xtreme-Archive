# Permutation Shift

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/permutation-shift/](https://csacademy.com/contest/archive/task/permutation-shift/)  

---

You are given a permutation $P$ of size $N$. You can apply circular shifts on this permutation as many times you want. Your goal is to find the maximum number of positions $i$ such that $P_i = i$, after applying the circular shifts.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of $P$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$2 \le N \le 100$ Each value between $1$ and $N$ will appear in $P$ exactly once

| Input | Output |
| --- | --- |
| 2<br>1 2 | 2 |
| 6<br>2 3 4 6 1 5 | 3 |
| 10<br>2 1 8 9 10 7 6 3 4 5 | 6 |
