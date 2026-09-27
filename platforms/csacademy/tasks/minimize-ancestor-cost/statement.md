# Minimize Ancestor Cost

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/minimize-ancestor-cost/](https://csacademy.com/contest/archive/task/minimize-ancestor-cost/)  

---

You are given a rooted tree with $N$ nodes, where node $1$ is the root. Each node $i$ has an associated cost $c_i$.

For each node $u \neq 1$, compute its ancestor $v$ such that $\Large{\frac{c_v-c_u}{d(u, v)}}$ is minimized. We denote by $d(u, v)$ the distance between nodes $u$ and $v$.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $c$.

The third line contains $N-1$ integers, the $i$-th integer representing the father of node $i+1$.

### Standard output

Print $N-1$ lines, on line $i$ the value of the optimal $v$ for node $i+1$. If the solution is not unique you should choose the ancestor closest to the root.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq c_i \leq 10^9$

| Input | Output |
| --- | --- |
| 4<br>7 2 5 6<br>1 2 3 | 1<br>2<br>2 |
| 7<br>51053 13120 1531 55972 13596 64822 32915<br>1 2 2 1 1 2 | 1<br>2<br>2<br>1<br>1<br>2 |
