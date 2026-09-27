# Direct the Graph

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/direct-the-graph/](https://csacademy.com/contest/archive/task/direct-the-graph/)  

---

You have a complete graph of size $N$. You should find a direction for all the edges such that the resulting directed graph has a maximum number of cycles of length $3$.

### Standard input

The first line contains a single integer $N$.

### Standard output

Print on the first line the maximum number of cycles of length $3$.

Consider the edges of the initial graph as ordered pairs $(a, b), a < b$. We can sort these edges increasingly by $a$, and in case of equality increasingly by $b$. For each edge print $1$ if you build the arc $(a \rightarrow b)$, or $0$ if you build the arc $(b \rightarrow a)$. These binary values should all be on the second line, as a string.

### Constraints and notes

$3 \leq N \leq 2000$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 | 1<br>101 | 123 |
| 4 | 2<br>101100 | 1234 |
| 5 | 5<br>0101100110 | 21345 |
| 6 | 8<br>001101100011011 |  |
