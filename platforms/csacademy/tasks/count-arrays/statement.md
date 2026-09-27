# Count Arrays

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/count-arrays/](https://csacademy.com/contest/archive/task/count-arrays/)  

---

You are given $Q$ segments. For every $1 \le i \le Q$, segment number $i$ is $[l_i,r_i]$.

A binary array of length $N$ is considered good if and only if for each $1 \le i \le Q$ there is at least one position between $l_i$ and $r_i$ (inclusive) in this array that contains $0$.

Find the number of good arrays.

### Standard input

The first line contains two integers $N$ and $Q$.

The next $Q$ lines contain two integers each, $l_i$ and $r_i$, representing the segments.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \le N, Q \le 10^5$ $1 \le l_i \le r_i \le N$ for each $1 \le i \le Q$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>1 2<br>2 3 | 5 | Good arrays are $000$, $001$, $010$, $100$, $101$ |
| 5 1<br>1 5 | 31 | Out of 32 possible arrays only one ($11111$) is bad. |
