# Dominoes

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dominoes/](https://csacademy.com/contest/archive/task/dominoes/)  

---

There are $N$ dominoes arranged in a straight line. For each domino you know its coordinate, an integer value. It is guaranteed all the coordinates are distinct. You have another set of $K$ dominoes. You should place these dominoes at integer coordinates in a way that will preserve the property that all the coordinates are distinct. You want to maximize the size of a subset of dominoes that are placed at consecutive coordinates.

### Standard input

The first line contains two integer values $N$ and $K$.

The second line contains $N$ integer values, the coordinates of the initial dominoes.

### Standard output

The output should contains a single value representing the size of the maximum subset of dominoes that can have consecutive coordinates.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq K \leq 10^5$The coordinates of the dominoes are integers between $1$ and $10^6$ and  are given in increasing order.

| Input | Output | Explanation |
| --- | --- | --- |
| 8 4<br>1 2 3 4 10 11 14 15 | 8 | It is optimal to place the dominoes at coordinates $12$, $13$, $16$ and $17$. |
