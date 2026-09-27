# Long Journey

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/long_journey/](https://csacademy.com/contest/archive/task/long_journey/)  

---

The cities of a country are represented as an undirected graph with $N$ nodes and $M$ edges. Alex and Ben are located in the city corresponding to node $S$. Alex wants to travel to node $A$, while Ben wants to travel to node $B$. Each of them wants to take a shortest route to his destination, but they also want to travel together for as long as possible. You should compute two paths of minimum length starting in $S$ and ending in $A$ and $B$, respectively, such that they share the maximum number of edges.

### Standard input

The first line contains two integer values $N$ and $M$.

The second line contains three integer values $S$, $A$ and $B$, signifying the starting node and the two destination nodes respectively.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

The output should consist of a single integer representing the maximum possible number of edges that Alex and Ben can walk together, while still getting to each of their destinations with the minimum distance.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq M \leq 3*10^5$The nodes are numbered from $1$ to $N$.The nodes $S$, $A$ and $B$ are pair-wise distinct.

| Input | Output |
| --- | --- |
| 6 5<br>1 4 6<br>1 2<br>2 3<br>3 4<br>3 5<br>5 6 | 2 |
| 9 10<br>1 8 9<br>1 2<br>1 3<br>2 4<br>3 4<br>3 5<br>4 6<br>5 7<br>6 7<br>6 8<br>7 9 | 1 |
