# Closest Numbers

**Time Limit:** `4000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/closest-numbers/](https://csacademy.com/contest/archive/task/closest-numbers/)  

---

You are given an array $A$ of $N$ integers, we consider the array to be 1-indexed. Answer $Q$ queries of the form:

For a given subarray, find the pair of elements for which the absolute difference between them is minimum.

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains $N$ integers representing the elements of $A$.

Each of the next $Q$ lines contains two integers $x_i$ and $y_i$. You should compute:

$l_i = 1 + (x_i + last) \% N$ $r_i = 1 + (y_i + last) \% N$. If $l_i > r_i$ you should swap them,$last$ is the answer of the previous query, initially $last = 0$

The pair $(l_i, r_i)$ represent the indices of the subarray in the $i^{th}$ query.

### Standard output

For each query print a single integer on a separate line, the minimum absolute difference between two elements in the given subarray.

### Constraints and notes

$2 \leq N \leq 5*10^4$ $1 \leq Q \leq 5*10^4$ $1 \leq A_i \leq 10^9$ $0 \leq x_i, y_i < N, x_i \neq y_i$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 3<br>1 4 8 2<br>0 3<br>0 2<br>3 0 | 1<br>2<br>4 | The first query is $[1, 4]$, with the closest pair $\{1, 2\}$, giving the answer $1$.The second query is $[1 + (0 + 1) \% N, 1 + (2 + 1) \% N] = [2, 4]$, with the closest pair $\{4, 2\}$, giving the answer $2$.The third query is $[1 + (3 + 2) \% N, 1 + (0 + 2) \% N] = [2, 3]$, with the closest pair $\{4, 8\}$, giving the answer $4$. |
