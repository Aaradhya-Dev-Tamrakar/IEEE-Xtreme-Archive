# K Inversions

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/k-inversions/](https://csacademy.com/contest/archive/task/k-inversions/)  

---

Find the smallest lexicographical permutation of size $N$ that has exactly $K$ inversions.

If we have a permutation $p$, an inversion is a pair of indices $(i, j)$, such that $i < j$ and $p_i > p_j$.

### Standard input

The first line contains two integers $N$ and $K$.

### Standard output

On the first line print $N$ integers representing the wanter permutation.

### Constraints and notes

$2 \leq N \leq 10^5$ $0 \leq K \leq \binom{N}{2}$

| Input | Output |
| --- | --- |
| 4 0 | 1 2 3 4 |
| 4 3 | 1 4 3 2 |
| 4 6 | 4 3 2 1 |
