# String Concat

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/string-concat/](https://csacademy.com/contest/archive/task/string-concat/)  

---

You are given $N$ strings. Find those strings that have the property that they can be obtained by concatenating two (distinct) of the other $N-1$ strings.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains one of the strings.

### Standard output

Print the indices (1-based) of the strings having the required property in increasing order.

### Constraints and notes

$1 \leq N \leq 50$ The strings will contains only lowercase letters of the English alphabet and their length will be between $1$ and $50$

| Input | Output |
| --- | --- |
| 6<br>c<br>def<br>abcdef<br>abc<br>ab<br>c | 3 4 |
