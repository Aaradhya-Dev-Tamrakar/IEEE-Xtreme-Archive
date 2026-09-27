# Good Permutations

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/good-permurations/](https://csacademy.com/contest/archive/task/good-permurations/)  

---

There is a permutation $P$ of the first $N$ powers of $2$, i.e. numbers $1$, $2$, $4$, ..., $2^{N - 1}$.

There is an integer variable $R$, which is initially equal to $0$. You perform $Q$ queries, each in the form of a non-empty subset of indices of array $P$. When processing a query, you pick one index $i$ from this subset so that $P_i$ is maximum possible. Then you perform $R := R \bigoplus P_i$, where $\bigoplus$ is the bitwise-xor operator.

Let's call a permutation $P$ good if after applying the given queries on it, $R$ will be equal to $1$. How many good permutations are there?

### Standard input

The first line contains two integers $N$ and $Q$.

The next $Q$ lines describe queries. Each query is given as a string of length $N$, containing characters $0$ and $1$. Indices of the string which contain $1$ represent the subset of indices for the query.

### Standard output

Print a single integer, the number of good permutations.

### Constraints and notes

$1 \le N \le 17$ $1 \le Q \le 2^N$ Queries are pairwise distinctNote that answer may not fit in a 32-bit integer type!

| Input | Output |
| --- | --- |
| 2 3<br>10<br>01<br>11 | 2 |
| 2 2<br>10<br>01 | 0 |
| 3 3<br>100<br>010<br>110 | 4 |
