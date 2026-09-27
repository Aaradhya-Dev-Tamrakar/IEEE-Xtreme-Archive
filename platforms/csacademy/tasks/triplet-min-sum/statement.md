# Triplet Min Sum

**Time Limit:** `2500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/triplet-min-sum/](https://csacademy.com/contest/archive/task/triplet-min-sum/)  

---

You are given a tree with $N$ nodes. Answer $Q$ queries of the type:

Given three distinct nodes $A$, $B$, and $C$, find the node $D$ such that the sum of distances from $D$ to $A$, $B$ and $C$ is minimum.

### Standard input

The first line contains two integers $N$ and $Q$.

Each of the following $N-1$ lines contain two integers, representing two nodes that share an edge.

Each of the following $Q$ lines contains three integers $A$, $B$ and $C$.

### Standard output

For each query print two numbers on a distinct line: the node $D$ and the sum of distances from $D$ to $A$, $B$ and $C$.

### Constraints and notes

$3 \leq N \leq 10^5$ $1 \leq Q \leq 10^5$ Node $D$ can be equal to one of $A$, $B$ or $C$ It can be proved the answer is unique

| Input | Output |
| --- | --- |
| 10 3<br>1 7<br>4 7<br>6 2<br>8 3<br>9 8<br>5 8<br>2 4<br>3 4<br>10 7<br>1 7 8<br>8 3 10<br>6 10 3 | 7 4<br>3 4<br>4 5 |
