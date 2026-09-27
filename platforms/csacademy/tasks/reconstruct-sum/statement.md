# Reconstruct Sum

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/reconstruct-sum/](https://csacademy.com/contest/archive/task/reconstruct-sum/)  

---

A number $S$ can be written in $S+1$ ways as a sum of two non-negative integers $A$ and $B$.

When adding two integers, a carry is a digit that is transferred from one column of digits to another column of more significant digits. It is part of the standard algorithm to add numbers together by starting with the rightmost digits and working to the left. For example, when $6$ and $7$ are added to make $13$, the $"3"$ is written to the same column and the $"1"$ is carried to the left.

You know which columns of digits generate a carry when performing the addition $A+B=S$. Find the number of solutions.

### Standard input

The first line contains a single integer $S$.

The second line contains  a binary array of length equal to the number of digits of $S$ minus $1$ (the most significant column doesn't generate a carry). These values correspond to the columns of digits, starting with the rightmost one. A column that generates a carry is represented by $1$, one that doesn't by $0$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$10 \leq S \leq 10^{18}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 15<br>0 | 12 | From the $16$ total ways of choosing $A$ and $B$, $4$ are invalid:$6 + 9$ $7 + 8$ $8 + 7$ $9 + 6$ All these generate a carry, when they shouldn't. |
| 15<br>1 | 4 | The valid pairs are the invalid ones from the previous example. |
| 140056<br>1 0 1 1 0 | 10800 |  |
| 140056<br>1 0 1 0 1 | 0 |  |
