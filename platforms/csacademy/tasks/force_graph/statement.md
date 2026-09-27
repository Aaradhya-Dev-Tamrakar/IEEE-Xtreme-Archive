# Force Graph

**Time Limit:** `2000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/force_graph/](https://csacademy.com/contest/archive/task/force_graph/)  

---

You are given a graph with $N$ nodes and $M$ edges. Every node has a point in the cartesian plane associated with it.

Between every pair of points, there's a repulsion force acting: if the nodes associated with the points are connected by an edge, the force has a magnitude of $F1 * dist$. Otherwise, if the nodes are not connected by an edge, the force has a magnitude of $F2 * dist$ (where $dist$ represents the Euclidian distance between the points). The direction of the force is determined by the straight line connecting the points. All of these $N*(N-1)/2$ pairs of forces act simultaneously and independent of one another.

Compute the resultant force acting on each point.

### Standard input

The first line contains four integer values $N$, $M$, $F1$ and $F2$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

Each of the next $N$ lines contains two integer values, representing the coordinates of the points.

### Standard output

The output should consist of $N$ lines. On each line you should output two integer values, the coordinates of the bound vector acting on each point. It can be proved that these values are integers given the constraints.

### Constraints and notes

$1 \leq N \leq 10^5$$0 \leq M \leq 3*10^5$The nodes are numbered from $1$ to $N$$0 \leq F1, F2 \leq 10^6$The coordinates of the points are between $-10^6$ and $10^6$.No two points share the same coordinates.

| Input | Output |
| --- | --- |
| 3 1 3 2<br>1 2<br>1 0<br>1 3<br>1 2 | 0 -13<br>0 11<br>0 2 |
| 8 6 10 5<br>4 3<br>8 6<br>1 4<br>6 4<br>8 2<br>7 6<br>0 8<br>0 0<br>3 -3<br>3 -1<br>4 -1<br>8 -2<br>8 -4<br>7 -2 | -180 390<br>-200 35<br>-45 -105<br>-55 -45<br>-5 -15<br>185 -50<br>155 -145<br>145 -65 |
