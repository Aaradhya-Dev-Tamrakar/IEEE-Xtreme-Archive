# Expected Lcp

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/expected-lcp/](https://csacademy.com/contest/archive/task/expected-lcp/)  

---

You are given $N$ strings. If you pick two of them in a uniformly random way, what is their expected longest common prefix (LCP)?

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains a string.

### Standard output

Print the answer on the first line.

### Constraints and notes

$2 \leq N \leq 10^6$ The sum of lengths of all the strings is between $1$ and $10^6$ Your result should differ from the official one by less than $10^{-6}$ with absolute precision.

| Input | Output |
| --- | --- |
| 4<br>abcd<br>ab<br>a<br>zxy | 0.666667 |
| 7<br>a<br>caaaaaaa<br>baaaaa<br>baaabaaa<br>baaab<br>baaabaa<br>caaaaaa | 1.714286 |
| 10<br>a<br>baaaaaaaaa<br>baaaaabaa<br>baaaaacaaaa<br>b<br>baaaaaaaa<br>ba<br>baaaaacaaa<br>baaaaacaa<br>baaaaaca | 3.711111 |
