# Suspect Interval

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/suspect-interval/](https://csacademy.com/contest/archive/task/suspect-interval/)  

---

You are given $N$ distinct integers in the interval $[1, 10^5]$. You need to find two numbers $A$ and $B$ such that:

$1 \leq A \leq B \leq 10^5$ The interval $[A, B]$ contains exactly one of the $N$ given integers.$B-A+1$, the length of the interval, is maximized

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ integers.

### Standard output

Print a single line representing the length of the interval.

### Constraints and notes

$1 \leq N \leq 10^5$ The input numbers are distinct

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>10000 20000 40000 70000 80000 | 49999 | 20001 - 69999 |
| 3<br>200 10 5 | 99990 | 11 - 100000 |
