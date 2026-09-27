# Bounded Diameter Trees

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bounded-diameter-trees/](https://csacademy.com/contest/archive/task/bounded-diameter-trees/)  

---

Count the number of ordered rooted trees of size $N$ with the diameter not greater than $M$. Output the answer modulo $P$.

### Standard input

The first line contains three integers $N$, $M$ and $P$.

### Standard output

Output a single integer representing answer modulo $P$.

### Constraints and notes

$0 \leq M < N \leq 300$$2 \leq P \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 3 2 | 1 | There are $5$ ordered rooted trees: |
| 6 2 100 | 2 |  |
| 6 5 10 | 2 | There are actually $42$ trees. |
