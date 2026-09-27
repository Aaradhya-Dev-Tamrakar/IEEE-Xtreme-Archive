# Binary Flips

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/binary-flips/](https://csacademy.com/contest/archive/task/binary-flips/)  

---

Consider an $N \times M$ binary matrix $A$. Intially all the cells are equal to $0$.

You perform $K$ operations of the type:

Choose a cell $(i, j)$. Flip all the cells on row $i$ and column $j$. Notice that cell $(i, j)$ is flipped twice, so it stays unchanged.

Count the number of ways of performing the operations such that in the end there are exactly $S$ cells equal to $1$.

### Standard input

The first line contains an integer $T$ denoting the number of test cases.

The next $T$ lines conatin $4$ integers. The $i^{\text{th}}$ line will contain the numbers $N_i$, $M_i$, $K_i$ and $S_i$.

### Standard output

For every test, print the answer modulo $10^9 + 7$ on a separate line.

### Constraints and notes

$1 \leq T \leq 40$ $1 \leq N_i, M_i, K_i \leq 3\,000$, for any $1 \leq i \leq T$  $0 \leq S_i \leq N_i * M_i$, for any $1 \leq i \leq T$ $\sum_{i=1}^{T} (N_i + K_i + M_i)^2 \leq 10^8$

| Input | Output |
| --- | --- |
| 3<br>1 2 3 1<br>3 2 2 2<br>1 2 4 2 | 8<br>12<br>8 |
