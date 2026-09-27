# Removed Pages

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/removed-pages/](https://csacademy.com/contest/archive/task/removed-pages/)  

---

A book's pages are numbered from $1$, using consecutive numbers in increasing order. A sheet of paper has two pages, numbered $2*K+1$ and $2*K + 2$, for $K \geq 0$.

Someone has removed some sheets from the book and you know the numbers of some of the pages on those sheets. What is the minimum number of removed sheets?

### Standard input

The first line contains a single integer $N$ representing the number of pages you know are missing.

The second line contains $N$ distinct integers, representing the numbers of the pages.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^3$ The numbers of the pages are integers between $1$ and $10^5$

| Input | Output |
| --- | --- |
| 4<br>1 2 5 6 | 2 |
| 10<br>16 8 9 13 14 2 15 7 3 17 | 7 |
| 5<br>102 1004 5 74 99999 | 5 |
