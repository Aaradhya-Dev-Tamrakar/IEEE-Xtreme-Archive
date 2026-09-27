# Rhombus

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rhombus/](https://csacademy.com/contest/archive/task/rhombus/)  

---

Consider a rhombus with diagonals equal to $D_1$ and $D_2$. You should perform $K$ steps, each step consisting of choosing one of the two diagonals and increasing it by $1$.

Find the largest possible area of the rhombus after performing the $K$ steps.

### Standard input

The first line contains three integers $D_1$, $D_2$ and $K$.

### Standard output

Print the largest possible area of the rhombus after performing the $K$ steps.

### Constraints and notes

$1 \leq D_1, D_2 \leq 10^4$ $1 \leq K \leq 10^6$ Your result should differ from the official one by less than $10^{-6}$ with absolute precision.

| Input | Output |
| --- | --- |
| 3 3 1 | 6.000000 |
| 3 4 3 | 12.500000 |
| 5 1 3 | 10.000000 |
