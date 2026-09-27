# Many Zeros

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/many-zeros/](https://csacademy.com/contest/archive/task/many-zeros/)  

---

You are given two integers $N$ and $X$. Your task is to construct an integer $Y$ having the sum of it's digits at most $X$ such that $N + Y$ has as many zeros at the end as possible.

Find the maximum number of zeroes.

Note that the sequence of zeros must be at the end. For example:

203100 has $2$ zeros at the end9000000100000 has $5$ zeros at the end

### Standard input

The first line contains $2$ integers $N$ and $X$.

### Standard output

The first line should contain the maximum number of zeros that can be achieved.

### Constraints and notes

$1 \leq N \leq 10^9$ $1 \leq X \leq 100$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 10372 10 | 2 | $Y = 28$$N + Y = 10400$ having $2$ zeros at the end |
| 1 20 | 2 | Note that sum of the digits of $Y$ must be at most $X$ $Y = 99$$N + Y = 100$ having $2$ zeros at the end |
| 4367 6 | 2 | $Y = 33$$N + Y = 4400$ |
