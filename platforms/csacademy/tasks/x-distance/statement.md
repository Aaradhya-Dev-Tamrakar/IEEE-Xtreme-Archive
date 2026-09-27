# X Distance

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/x-distance/](https://csacademy.com/contest/archive/task/x-distance/)  

---

You are given a weighted undirected graph with $N$ nodes and $M$ edges. We define the cost of a path to be equal to the maximum weight of an edge on the path. Find the number of pairs of nodes for which the minimum cost of a path between them is equal to $X$.

### Standard input

The first line contains three integers $N$, $M$ and $X$.

Each of the next $M$ lines contains three integers $a\ b\ w$, representing and edge between nodes $a$ and $b$ having weight $w$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq M \leq 3 * 10^5$ $1 \leq w_i, X \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 7 6 3<br>1 2 1<br>1 3 2<br>3 4 3<br>4 5 1<br>4 6 2<br>1 7 4 | 9 | The graph looks like this:1231241234567The pairs and paths are:$[1\ 4] -> \{1,\ 3,\ 4\}$$[1\ 5] -> \{1,\ 3,\ 4,\ 5\}$$[1\ 6] -> \{1,\ 3,\ 4,\ 6\}$$[2\ 4] -> \{2,\ 1,\ 3,\ 4\}$$[2\ 5] -> \{2,\ 1,\ 3,\ 4,\ 5\}$$[2\ 6] -> \{2,\ 1,\ 3,\ 4,\ 6\}$$[3\ 4] -> \{3,\ 4\}$$[3\ 5] -> \{3,\ 4,\ 5\}$$[3\ 6] -> \{3,\ 4,\ 6\}$ |
| 8 8 4<br>1 3 2<br>2 4 1<br>1 5 1<br>6 7 3<br>5 8 4<br>8 4 4<br>6 5 5<br>7 8 6 | 11 | The graph looks like this:2113445612345678The $11$ pairs are:$[4\ 8], [4\ 5], [4\ 1], [4\ 3]$$[2\ 8], [2\ 5], [2\ 1], [2\ 3]$$[8\ 5], [8\ 1], [8\ 3]$Examples of invalid pairs:$[4\ 6]$ and $[4\ 7]$ have a cost greater than $X$ $[4\ 2]$ has a cost of 1, smaller than $X$ |
