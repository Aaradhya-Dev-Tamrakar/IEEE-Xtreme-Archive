# Xor Submatrix

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/xor-submatrix/](https://csacademy.com/contest/archive/task/xor-submatrix/)  

---

Given an array $V$ of size $N$ and another array $U$ of size $M$, we build a matrix $A$ of size $N \times M$, where $A_{i, j} = V_i\ \text{xor}\ U_j$.

We say the score of a submatrix of $A$ is the xor sum of all its elements. Find the submatrix with the highest score.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $N$ integers representing the elements of $V$.

The thirst line contains $M$ integers representing the elements of $U$.

### Standard output

Print the highest possible score on the first line.

### Constraints and notes

$1 \leq N, M \leq 1000$ $0 \leq V_i < 2^{29}$ $0 \leq U_i < 2^{29}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4<br>5 3 1<br>2 1 2 4 | 7 |  |
| 3 3<br>10 12 4<br>5 10 9 | 15 |  |
| 3 3<br>1 2 1<br>4 2 8 | 15 |  |
