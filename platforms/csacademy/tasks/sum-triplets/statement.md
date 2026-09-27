# Sum Triplets

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sum-triplets/](https://csacademy.com/contest/archive/task/sum-triplets/)  

---

You are given an array $A$ of $N$ integers. Find the number of triples $(i, j, k$), $1 \leq i <j < k \leq N$, such that in the set $\{A_i, A_j, A_k\}$ at least one of the numbers can be written as the sum of the other two.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

Print the answer of the first line.

### Constraints and notes

$1 \leq N \leq 5\,000$ $0 \leq A_i \leq 5\,000$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 3 4 5 | 4 | The valid triplets are:$(1, 2, 3)$ $(1, 3, 4)$ $(1, 4, 5)$ $(2, 3, 5)$ |
| 5<br>1 1 1 2 2 | 6 | $(1, 2, 4)$ $(1, 2, 5)$ $(1, 3, 4)$ $(1, 3, 5)$ $(2, 3, 4)$ $(2, 3, 5)$ |
| 5<br>0 0 0 1 1 | 4 | $(1, 2, 3)$ $(1, 4, 5)$ $(2, 4, 5)$ $(3, 4, 5)$ |
| 5<br>1 1 1 2 2 | 6 | $(1, 2, 4)$ $(1, 2, 5)$ $(1, 3, 4)$ $(1, 3, 5)$ $(2, 3, 4)$ $(2, 3, 5)$ |
