# Product Replace

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/product-replace/](https://csacademy.com/contest/archive/task/product-replace/)  

---

You are given an array $A$ of $N$ integers, $N$ is always even. You can take two elements $A_i$ and $A_j$ and replace them both by $A_i * A_j$.  Your goal is to make all the elements of $A$ equal.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

For each operation, print the two distinct indices $i$ and $j$ on a distinct line. You are allowed to make at most $5\,000$ replace operations.

### Constraints and notes

$2 \leq N \leq 100$, $N$ is even$1 \leq A_i \leq 10^9$

| Input | Output |
| --- | --- |
| 4<br>3 5 2 2 | 1 2<br>1 3<br>2 4 |
| 6<br>20 1 2 5 2 3 | 3 4<br>2 6<br>5 6<br>4 5<br>3 6<br>1 2 |
