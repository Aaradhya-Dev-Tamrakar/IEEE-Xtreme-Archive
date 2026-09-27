# Cycle Tree

**Time Limit:** `5000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cycle_tree/](https://csacademy.com/contest/archive/task/cycle_tree/)  

---

A cycle tree is a connected undirected graph that respects one of the following:

It's an elementary cycle of length greater than or equal to 3.It's a graph resulted by attaching an elementary cycle to another cycle tree. Attaching a cycle means choosing two edges, one from the cycle and the other one from the cycle tree, and merging them and their incident nodes:

You are give a cycle tree, compute its maximum independent set.

### Standard input

The first line contains two integer values $N$ and $M$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

The output should contains a single value representing the size of the maximum independent set.

### Constraints and notes

$1 \leq N \leq 50\ 000$$1 \leq M \leq 10^5$The nodes are numbered from $1$ to $N$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4<br>1 2<br>2 3<br>3 4<br>1 4 | 2 | We can choose either the set $\{1, 3\}$ or the set $\{2, 4\}$. |
| 13 18<br>3 4<br>4 5<br>5 1<br>1 2<br>2 3<br>8 4<br>3 6<br>6 7<br>7 8<br>10 6<br>10 7<br>7 9<br>9 6<br>11 8<br>7 11<br>12 7<br>12 13<br>13 11 | 6 | We can choose more than one independent set of size $6$. One of them is $\{1, 3, 9, 10, 11, 12\}$. |
