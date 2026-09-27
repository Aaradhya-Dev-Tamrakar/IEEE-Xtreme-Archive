# Divisor Clique

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/divisor_clique/](https://csacademy.com/contest/archive/task/divisor_clique/)  

---

You are given a set of $N$ positive integer values. Find the largest subset such that for any two values $A$ and $B$ in the subset, either $A$ divides $B$ or $B$ divides $A$.

### Standard input

The first line contains a single integer value $N$.

The second line contains $N$ integer values representing the elements of the set.

### Standard output

The output should contain a single integer representing the size of the wanted subset.

### Constraints and notes

$1 \leq N \leq 2 000$The values of the array will be between $1$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>8 32 12 16 4 | 4 | The clique that contains $4$ elements is $(8, 32, 16, 4)$. |
| 8<br>20 6 200 4 36 108 40 2 | 5 | $(20, 200, 4, 40, 2)$ |
| 8<br>108 4 360 6 756 18 2 36 | 6 | $(108, 6, 756, 18, 2, 36)$ |
