# Least Even Digits

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/least-even-digits/](https://csacademy.com/contest/archive/task/least-even-digits/)  

---

You are given an integer $X$. Count the number of intervals $[A, B]$, such that $A \leq X \leq B$ and there is no other number $Y$ in the interval $[A, B]$ such that $Y$ has less even digits than $X$.

### Standard input

The first line contains a single integer $X$.

### Standard output

If there are an infinite number of intervals output $-1$. Otherwise, print the answer on the first line.

### Constraints and notes

$1 \leq X \leq 10^9$

| Input | Output |
| --- | --- |
| 4 | 1 |
| 25 | 36 |
| 325 | 36 |
