# Infinity Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/infinity-array/](https://csacademy.com/contest/archive/task/infinity-array/)  

---

You have an positive integer array $A$ of length $N$ (zero indexed). We define the infinite array $B$ in the following way: $B_i = A_{i\ mod\ N}$. You are given $M$ constraints which are one of the two types:

type $0$: given $l$, $r$ and $w$, $\sum_{i = l}^{r} B_i \leq w$ type $1$: given $l$, $r$ and $w$, $\sum_{i = l}^{r} B_i \geq w$ 

Your task is to find out how many different values of $\sum_{i = 0}^{N - 1} A_i$ can there be when all constraints are satisfied.

If there are infinity possibilities, output -1.If the answer is finite, it's guaranteed that $(\sum_{i = 0}^{N - 1} A_i) \lt 10^{9}$ 

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $M$ lines contains four integers $l$, $r$, $type$

and $w$ describing one constrain. $type$ is defining the constrain type while $l$, $r$ and $w$ have the meaning from the statement.

### Standard output

The first line should contain the number of possibilities or $-1$ if there are infinity possibilities.

### Constraints and notes

$1 \leq N \leq 1000$ $1 \leq M \leq 1000$ 

For each constraint

$0 \leq type \leq 1$ $1 \leq l \leq r \leq 10^9$ $1 \leq w \leq 10^{12}$ 

| Input | Output |
| --- | --- |
| 5 3<br>8 10 0 37<br>1 8 0 56<br>2 14 1 72 | 22 |
| 7 7<br>5 7 0 25<br>2 6 1 18<br>6 9 0 29<br>6 8 1 13<br>2 9 1 30<br>7 9 0 18<br>0 8 1 39 | -1 |
