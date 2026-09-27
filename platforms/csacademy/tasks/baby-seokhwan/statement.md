# Baby Seokhwan

**Time Limit:** `8000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/baby-seokhwan/](https://csacademy.com/contest/archive/task/baby-seokhwan/)  

---

Seokhwan is a cute 4-year-old baby. His teacher, Suryal, is teaching some knowledge suited for babies. Suryal brought a big whiteboard, which is essentially $N$ empty vectors (vectors filled with zeroes) of size $M$, denoted by $V_1, V_2, \cdots, V_N$.

Yesterday, Seokhwan learned how to write numbers. To test his ability, Suryal gave $Q$ queries to Seokhwan. For each query, Seokhwan is given four number $S, E, P, X$. For all vectors $V_S, V_{S+1}, \cdots, V_E$, Seokhwan should write $X$ to $P$-th element of each vectors. It's guaranteed that Seokhwan never overwrites (he never writes in a place where he already wrote something).

Today, Seokhwan learned how to sort a sequence in $O(N\log N)$ time complexity. To test his ability, Seokhwan should sort the vectors. Formally, Seokhwan should find a size-$N$ permutation $P_1, P_2, \cdots, P_N$ where $V_{P_i} \leq V_{P_{i+1}}$ for all $1 \leq i < N$. Suryal expects Seokhwan to do stable sort, thus if there are many such $P$, then you should print the one which is lexicographically minimum.

Seokhwan did all those tasks in 8000ms, which Suryal don't know how. You should help Suryal, and do what Seokhwan did. For two sequence $L, R$ of same size, $R$ is lexicographically greater than $L$ if and only if there exists some $j \in [1, M]$ such that $L_i = R_i$ for all $1 \leq i < j$ and $L_j < R_j$.

### Standard input

The first line contains the number of vector $N$, size of each vector $M$, and number of queries $Q$.

In next $Q$ lines, four integer $S, E, P, X$ is given. This indicates that for all vectors $V_S, V_{S+1}, \cdots, V_E$, Seokhwan should write $X$ to $P$-th element of each vector.

### Standard output

In $i$-th line, print the $i$-th element of permutation, which is the lexicographically minimum permutation which $V_{P_i} \leq V_{P_{i+1}}$ holds.

### Constraints and notes

$1 \leq N, M, Q \leq 250\ 000$ 

For each query, the following constraints are satisfied:

$1 \leq S \leq E \leq N$ $1 \leq P \leq M$ $1 \leq X \leq 250\ 000$ 

| Input | Output |
| --- | --- |
| 5 5 3<br>3 5 2 1<br>2 2 2 2<br>1 4 4 3 | 1<br>5<br>3<br>4<br>2 |
