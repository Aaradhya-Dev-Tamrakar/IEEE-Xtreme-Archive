# Substring Restrictions

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/substring-restrictions/](https://csacademy.com/contest/archive/task/substring-restrictions/)  

---

In this problem you are dealing with strings of length $N$ consisting of lowercase letters of the English alphabet. Each string should respect $M$ restrictions of the form:

$len\ x\ y$: the two substrings starting at $x$ and $y$, having a length of $len$, are equal.

Count the number of strings respecting all the $M$ restrictions. Print your answer modulo $10^9+7$.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the following $M$ lines contains three integers $len\ x\ y$, representing a restriction.

### Standard output

Print a single integer, representing the number valid strings modulo $10^9 + 7$.

### Constraints and notes

$1 \leq N \leq 10^6$$1 \leq M \leq 10^5$$1 \leq x, y \leq N$$1 \leq len \leq N$$max(x, y) + len - 1 \leq N$

| Input | Output |
| --- | --- |
| 1 1<br>1 1 1 | 26 |
| 10 5<br>1 4 6<br>1 3 4<br>1 10 10<br>1 9 4<br>2 8 8 | 31810120 |
