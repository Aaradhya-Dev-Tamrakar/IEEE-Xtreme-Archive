# Xor Closure

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/xor-closure/](https://csacademy.com/contest/archive/task/xor-closure/)  

---

You are given a set of $N$ integer values. You should find the minimum number of values that you need to add to the set such that the following will hold true:

For every two integers $A$ and $B$ in the set, their bitwise xor $A \oplus B$ is also in the set.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the set.

### Standard output

Output a single number representing the minimum number of integers you need to add to the set.

### Constraints and notes

$1 \leq N \leq 10^5$The elements of the set are integers between $0$ and $10^{18}$.All $N$ elements from the set are pairwise distinct.

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>0 1 2 3 | 0 |  |
| 3<br>1 2 3 | 1 | The only value which needs to be added is $\{0\}$, since $1 \oplus 1 = 0$ |
| 2<br>8 6 | 2 | The values $\{0, 14\}$ need to be added. $6 \oplus 6 = 0$; $8 \oplus 6 = 14$; |
