# Dominant Free Sets

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dominant-free-sets/](https://csacademy.com/contest/archive/task/dominant-free-sets/)  

---

You are given a set $S$ of $N$ points. A point $A$ dominates point $B$ if $A_x \geq B_x$ and $A_y \geq B_y$. Count the number of non-empty subsets of $S$ that don't contain two points $A$ and $B$ such that $A$ dominates $B$.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers $x$ and $y$, representing a point at coordinates $(x, y)$.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq x_i, y_i \leq 10^5$ The $N$ points are distinct

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 1<br>2 2<br>3 3<br>4 4 | 4 | The only valid sets are the ones with exactly one point. |
| 3<br>2 1<br>1 1<br>1 2 | 4 | The sets are $\{(1, 1)\}$, $\{(1, 2)\}$, $\{(2, 1)\}$ and $\{(1, 2), (2, 1)\}$. |
