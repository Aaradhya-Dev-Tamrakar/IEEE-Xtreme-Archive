# Elections

**Time Limit:** `3000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/elections/](https://csacademy.com/contest/archive/task/elections/)  

---

You are given a string $S$ of length $N$ consisting of characters C and T.

You are also given $Q$ queries restricting you to the substring $P = S[i..j] \ (1 \leq i \leq j \leq N)$ and you should print the minimum number of deletions applied on $S$ such that the number of C characters is not less than the number of T characters for all prefixes and all suffixes of $P$.

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains $S$.

The next $Q$ lines contain a query described by two integers $i$ and $j$.

### Standard output

Print the answer for each query on a separate line.

### Constraints and notes

$1 \leq N, Q \leq 5 * 10^5$

| Input | Output |
| --- | --- |
| 11<br>CCCTTTTTTCC<br>3<br>1 11<br>4 9<br>1 6 | 4<br>6<br>3 |
