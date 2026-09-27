# Coprime Pairs

**Time Limit:** `1000 ms`  
**Memory Limit:** `64 MB`  
**Source:** [https://csacademy.com/contest/archive/task/coprime/](https://csacademy.com/contest/archive/task/coprime/)  

---

You are given two integers $N$ and $K$. Find $N$ distinct positive integers, such that among the total $\binom{N}{2}$ unordered pairs, exactly $K$ of them consist of  coprime numbers.

### Standard input

The first line contains two integers $N$ and $K$.

### Standard output

Print the $N$ integers on the first line.

### Constraints and notes

$1  \leq N \leq 10\,000$ $0 \leq K \leq \binom{N}{2}$ Each integer in your output should be strictly positive and less than $10^6$.

| Input | Output |
| --- | --- |
| 2 0 | 6 9 |
| 3 3 | 9 14 55 |
| 3 1 | 9 15 25 |
