# Random Nim Generator

**Time Limit:** `3000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/random_nim_generator/](https://csacademy.com/contest/archive/task/random_nim_generator/)  

---

You want to generate an array of size $N$ where each element is a random integer between $0$ and $K$ (inclusive). Count the number of possible arrays where the xor sum of the elments is strictly greater than $0$.

### Standard input

The first line contains two integer values $N$ and $K$.

### Standard output

The output should contains a single value representing number of arrays having a positive xor sum of elements. As this number can be very large, output its value mod $30011$.

### Constraints and notes

$1 \leq N \leq 20\ 000$$1 \leq K \leq 50\ 000$

| Input | Output |
| --- | --- |
| 1 3 | 3 |
| 3 2 | 20 |
| 10 3 | 6146 |
| 10 10 | 25344 |
