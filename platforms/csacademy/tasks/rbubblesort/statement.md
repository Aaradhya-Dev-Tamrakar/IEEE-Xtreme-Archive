# RBubbleSort

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rbubblesort/](https://csacademy.com/contest/archive/task/rbubblesort/)  

---

You are given a permutation $P$ of $\{1, 2, 3, \ldots, N\}$. You are allowed to perform at most $K$ of the following operations on $P$:

Choose two consecutive elements and swap their positionShuffle $P$ uniformly random

What is the minimum expected value of the number of inversions in $P$?

### Standard input

The first line contains $T$, the number of tests.

All tests contain $N$ and $K$ on the first line and $N$ integers on the second line, representing $P$.

### Standard output

It can be proved that the answer is a rational number $\frac{A}{B}$.

For each test print $A * B^{-1}$ modulo $10^9 + 7$ on a separate line.

### Constraints and notes

$1 \leq T \leq 300$ $1 \leq N \leq 300$ $0 \leq K \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>3 2<br>3 1 2<br>3 1<br>3 2 1 | 0<br>500000005 | In the first test we can swap $1$ with $2$ and then $2$ with $3$ to obtain the identity permutation which has no inversions. In the second test we can shuffle the permutation and the expected number of inversions will be $1.5 = \frac{3}{2}$. We will print $3 * 2^{-1}$ mod $10^9 + 7$. |
