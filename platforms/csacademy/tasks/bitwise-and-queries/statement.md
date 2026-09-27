# Bitwise And Queries

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bitwise-and-queries/](https://csacademy.com/contest/archive/task/bitwise-and-queries/)  

---

You are given $Q$ queries of the form $a\ b\ x$. Count the number of values $y$ such that $a \leq y \leq b$ and $x\ \& \ y = x$, where we denote by $\&$ the bitwise and operation.

### Standard input

The first line contains a single integer $Q$.

Each of the following $Q$ lines contains three integers $a\ b\ x$, representing a query.

### Standard output

Output $Q$ lines, each containing a single integer representing the answer to a query.

### Constraints and notes

$1 \leq Q \leq 10^5$$1 \leq a \leq b \leq 10^{18}$$0 \leq x \leq 10^{18}$

| Input | Output |
| --- | --- |
| 4<br>1 10 3<br>5 10 0<br>1 63 7<br>32 100 32 | 2<br>6<br>8<br>37 |
