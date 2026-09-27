# Xor Cycle

**Time Limit:** `4000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/xor_cycle/](https://csacademy.com/contest/archive/task/xor_cycle/)  

---

You are given a connected undirected weighted graph. Compute the maximum xor value of any closed walk (a cycle that isn't necessarily simple).

### Standard input

The first line contains two integer values $N$ and $M$.

Each of the next $M$ lines contains three integer values $a$, $b$ and $c$, representing an edge between nodes $a$ and $b$ of weight $c$.

### Standard output

The output should contains a single value representing the largest xor value of a closed walk.

### Constraints and notes

$1 \leq N \leq 10^5$$N-1 \leq M \leq 2*10^5$The nodes are numbered from $1$ to $N$The weights are between $0$ and $2^{60}$There can be multiple edges between the same pair of nodes. There can also be edges from a node to itself.

| Input | Output |
| --- | --- |
| 2 4<br>1 1 1<br>1 2 2<br>1 2 4<br>1 2 8 | 13 |
| 4 5<br>1 2 1<br>2 3 2<br>3 4 3<br>4 1 4<br>2 4 2 | 7 |
