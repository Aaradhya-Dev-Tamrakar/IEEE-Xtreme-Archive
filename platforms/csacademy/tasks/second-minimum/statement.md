# Second Minimum

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/second-minimum/](https://csacademy.com/contest/archive/task/second-minimum/)  

---

You should find the index of $2$ in a permutation of size $N$.

In a query you can choose two distinct indices. The interactor returns the index of the smaller value.

### Interaction

First you should read an integer $N$.

Then you can start asking the queries. Each query should consist of the character Q followed by two distinct indices between $1$ and $N$.

When you are done, print the character A followed by the index of $2$.

### Constraints and notes

This task is NOT adaptive.$2 \leq N \leq 10^4$ You are allowed to ask at most $\text{min}(2*N, N + 15)$ queriesThe answer operation does not count as a query.Don't forget to flush after each query.

InteractionExplanation4Q 2 42Q 1 44Q 3 44A 4The permutation is $[3, 1, 4, 2]$3Q 1 22Q 2 32Q 1 33A 3The permutation is $[3, 1, 2]$4Q 1 21Q 2 32Q 2 42A 2The permutation is $[1, 2, 3, 4]$
