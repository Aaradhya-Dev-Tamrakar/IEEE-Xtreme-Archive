# Prefix Suffix Counting

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/prefix-suffix-counting/](https://csacademy.com/contest/archive/task/prefix-suffix-counting/)  

---

You are given two positive large numbers $N$ and $M$. Let's denote by $K$ the number of digits in $M$. You should count how many numbers between $1$ and $N$ respect the following property: the numbers represented by their prefix and the suffix of length $K$ are equal to $M$. Note that you should only consider numbers with at least $K$ digits.

### Standard input

The first line contains a single (large) number $N$.

The second line contains a single (large) number $M$.

### Standard output

Output a single line containing the answer.

The number should be printed modulo $10^9+7$.

### Constraints and notes

The number of digits of both $N$ and $M$ is between $1$ and $10^6$.  

| Input | Output |
| --- | --- |
| 11<br>1 | 2 |
| 103<br>1 | 3 |
| 3000<br>22 | 3 |
| 2323000<br>232 | 6 |
