# Cut the Trees

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cut-the-trees/](https://csacademy.com/contest/archive/task/cut-the-trees/)  

---

You have $N$ trees. For each tree $i$ you know it's initial height $H_i$ and it's growth rate $G_i$. Normally, at the end of day $K$, the height of tree $i$ will be $H_i + (K-1) * G_i$.

But at the end of every day you are allowed to choose any tree and cut it completely. The tree will continue to grow at the same rate during the following days. So, if at the end of day $K$ you cut tree $i$, then at the end of day $K+1$ the tree will have height $G_i$.

Your goal is to maximize the number of trees that at the end of a day (after eventually cutting one of them) have height at most $D$.

### Standard input

The first line contains two integers $N$ and $D$.

The second line contains $N$ integers representing the values of $H$.

The third line contains $N$ integers representing the values of $G$.

### Standard output

Print the a single integer, representing the maximum number of trees that can have height at most $D$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq D \leq 10^9$ $1 \leq H_i, G_i \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 2 3<br>4 4<br>3 3 | 2 | The order in which the operations took place is the following: cut tree  - trees sizes: $[0, 4]$  check for max  - just 1 tree has a hight at most $D(3)$  trees grow   - trees sizes: $[3, 7]$  cut tree  - trees sizes: $[3, 0]$  check for max  - 2 trees has a hight at most $D(3)$ At this point, we got all trees to have a hight at most $D(3)$ |
| 5 7<br>5 8 4 8 1<br>3 2 5 8 4 | 4 | The order in which the operations took place is the following: cut tree  - trees sizes: $[5, 0, 4, 8, 1]$  check for max  - 4 tree has a hight at most $D(7)$ At this point, we have $4$ trees that have a hight at most $D(7)$  trees grow   - trees sizes: $[8, 2, 9, 16, 5]$  cut tree  - trees sizes: $[0, 2, 9, 16, 5]$  check for max  - 3 tree has a hight at most $D(7)$  trees grow  - trees sizes: $[3, 5, 14, 24, 9]$ This can go on but there's no way to achieve a solution better than $4$ |
| 6 8<br>10 10 7 2 4 1<br>2 2 2 2 2 2 | 6 | The order in which the operations took place is the following: cut tree  - trees sizes: $[0, 10, 7, 2, 4, 1]$  check for max  - 5 tree has a hight at most $D(8)$  trees grow   - trees sizes: $[2, 12, 9, 4, 6, 3]$  cut tree  - trees sizes: $[2, 0, 9, 4, 6, 3]$  check for max  - 5 tree has a hight at most $D(8)$  trees grow   - trees sizes: $[4, 2, 11, 6, 8, 5]$  cut tree  - trees sizes:$[4, 2, 0, 6, 8, 5]$ At this point, we got all trees to have a hight at most $D(8)$ |
