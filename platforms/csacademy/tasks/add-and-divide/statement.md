# Add and Divide

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/add-and-divide/](https://csacademy.com/contest/archive/task/add-and-divide/)  

---

You are given an integer $N$. If it's odd, increment it by $1$, otherwise divide it by $2$. Repeat the process until the number becomes $1$. What's the number of steps performed?

### Standard input

The first line contains a single integer $N$.

### Standard output

Print a single integer representing the number of steps.

### Constraints and notes

$1 \leq N \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 13 | 6 | We perform the following steps:$13 + 1 = 14$ $14 / 2 = 7$ $7 + 1 = 8$ $8 / 2 = 4$ $4 / 2 = 2$ $2 / 2 = 1$ |
| 8 | 3 | $8 / 2 =4$ $4 / 2 = 2$ $2 / 2 = 1$ |
