# Modulo Queries

**Time Limit:** `1000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/modulo-queries/](https://csacademy.com/contest/archive/task/modulo-queries/)  

---

You are given an array $A$ of size $N$ and $Q$ queries.  Each query consists of three integers $l, r$ and $k$. For each query you should compute $max_{i=l}^{r}\ A_{i}\ mod\ K$.

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains $N$ integers, the elements of array $A$.

Each of the following $Q$ lines contains three integers $l, r$ and $k$.

### Standard output

You should output $Q$ lines, each containing the answer for a query.

### Constraints and notes

$1 \leq N \leq 4 \times 10^4$ $1 \leq Q \leq 4 \times 10^4$ $1 \leq A_i \leq 4 \times 10^4$ For each query $1 \leq l \leq r \leq N$, $1\leq K \leq 4 \times 10^4$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 5<br>1 2 3 4 5 <br>1 3 2<br>1 3 3<br>1 4 4<br>5 5 5<br>3 5 3 | 1<br>2<br>3<br>0<br>2 | Explanation format:For each query, the elements in the array which are in the query range will be underlined.$\underline{1}\ \underline{0}\ \underline{1}\ 0\ 1$ $\underline{1}\ \underline{2}\ \underline{0}\ 1\ 2$ $\underline{1}\ \underline{2}\ \underline{3}\ \underline{0}\ 1$ $1\ 2\ 3\ 4\ \underline{0}$ $1\ 2\ \underline{0}\ \underline{1}\ \underline{2}$ |
