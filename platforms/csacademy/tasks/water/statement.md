# Water

**Time Limit:** `1000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/water/](https://csacademy.com/contest/archive/task/water/)  

---

You are given a tree $G$ with $N$ vertices, each of these having within a water container with infinite capacity.

Answer $Q$ queries of the following form: take the shortest path from vertex $u$ to vertex $v$ and pour $h$ amount of water into the first container on this path, $h-1$ into the second container, $h-2$ into the third container and so on until vertex $v$. If the path is longer than $h$ the end vertices will have $0$ amount of water poured into them. For all other vertices pour as much water into them as into the closest vertex to them on this path. For each query what is the total amount of water poured into all vertices?

### Standard input

The first line will contain two numbers $N$ and $Q$ representing the size of the tree and the number of queries.

The next $N-1$ lines will describe the tree, each line containing two space separated integers describing an edge from this tree $(u, v)$.

The following $Q$ lines will describe a query each, each containing $3$ numbers: $u$, $v$ and $h$.

### Standard output

Output should contain exactly $Q$ lines, the $i$-th of these containing the answer to the $i$-th query.

### Constraints and notes

$h \leq 1\ 000\ 000\ 000$

#PointsRestrictions18$1\leq N, Q \leq 1000$26$1\leq N, Q \leq 200000$ and all queries have the same source $u$312$1 \leq N, Q \leq 200000$ and all queries have the same destination  $v$453$1\leq N, Q \leq 50000$521$1\leq N, Q \leq 200000$

### Examples

| Input | Output |
| --- | --- |
| 10 3<br>1 2<br>2 3<br>3 4<br>3 5<br>3 6<br>4 7<br>4 8<br>6 9<br>6 10<br>7 10 5<br>7 10 3<br>1 10 8 | 30<br>11<br>59 |
