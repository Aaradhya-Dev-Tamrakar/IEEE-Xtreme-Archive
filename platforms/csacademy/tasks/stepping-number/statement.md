# Stepping Number

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/stepping-number/](https://csacademy.com/contest/archive/task/stepping-number/)  

---

A number for which any two consecutive digits differ in absolute value by at most $1$ is called a stepping number.

Find the $K$-th stepping number greater then a given integer $N$.

### Standard input

The first line contains two integers $K$ and $N$.

### Standard output

Print a single integer representing the answer.

### Constraints and notes

$1 \leq K \leq 10^{18}$ $0 \leq N \leq 10^{18}$ The result fits on a signed $64$ bit integer.

| Input | Output | Explanation |
| --- | --- | --- |
| 6 7 | 21 | $8, 9, 10, 11, 12, 21$ |
| 3 20 | 23 | $21, 22, 23$ |
| 2 30 | 33 | $32, 33$ |
| 2 100 | 110 | $101, 110$ |
| 5 130 | 222 | $210, 211, 212, 221, 222$ |
