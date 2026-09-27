# Path Travel

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/path-travel/](https://csacademy.com/contest/archive/task/path-travel/)  

---

We consider a graph with $N$ nodes such that there is an edge between every pair of nodes $(i, i+1)$. The graph is actually a simple path.

The nodes are of three types: red, blue and white. There are exactly $R$ red nodes and $B$ blue nodes. For each red node you should find the minimum distance to any blue node.

### Standard input

The first line contains three integers $N$, $R$ and $B$.

The second line contains $R$ integers representing the indices of the red nodes.

The third line contains $B$ integers representing the indices of the blue nodes.

### Standard output

Print a single number representing the sum of distances from each red node to the closest blue node.

### Constraints and notes

$1 \leq N \leq 10^8$ $1 \leq R, B \leq 10^5$ The indices of all the nodes in the input are distinct

| Input | Output |
| --- | --- |
| 10 3 2<br>1 5 10<br>2 9 | 5 |
| 20 3 1<br>3 15 20<br>10 | 22 |
| 9 1 3<br>9<br>5 7 3 | 2 |
