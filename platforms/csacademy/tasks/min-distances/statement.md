# Min Distances

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/min-distances/](https://csacademy.com/contest/archive/task/min-distances/)  

---

You should build a  simple, connected, undirected, weighted  graph with $N$ nodes. You are given $M$ constraints of the type $a, b, c$, representing the fact that the minimum distance between nodes $a$ and $b$ should be $c$.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $M$ lines contains three integers $a$, $b$ and $c$ representing a constraint.

### Standard output

If there is no solution output $-1$.

Otherwise, print the number of edges your graph has on the first line.

Each of the next line should contain three integers $a$, $b$, $w$, representing an edge $(a, b)$ with weight $w$.

### Constraints and notes

$2 \leq N \leq 100$ $0 \leq M \leq \binom{N}{2}$ $1 \leq a, b \leq N$ and $a \neq b$ $1 \leq c \leq 10^6$ The weigths $w$ should respect $1 \leq w \leq 10^7$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>1 2 1<br>2 3 2<br>1 3 3 | 2<br>1 2 1<br>2 3 2 | Note that the graph is not unique12123 |
| 5 4<br>3 1 2<br>3 5 2<br>1 5 3<br>4 2 2 | 6<br>1 3 2<br>5 1 3<br>2 4 2<br>2 5 4<br>3 5 2<br>5 4 1 | Note that the graph is not unique23242112354 |
| 3 3<br>1 2 1<br>2 3 1<br>3 1 3 | -1 | There's no graph to satisfy all 3 restrictions. |
