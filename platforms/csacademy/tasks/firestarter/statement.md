# Firestarter

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/firestarter/](https://csacademy.com/contest/archive/task/firestarter/)  

---

Consider a simple weighted graph $G$ with $N$ vertices and $M$ edges where edges represent ropes, vertices represent knots between multiple ropes and the cost of the edge represent the length of the rope. There are $Q$ updates which represent a firestarter event. Each update is represented by $4$ integers: $T$, $A$, $B$ and $X$ meaning that a fire will start on edge $A-B$ at distance $X$ from $A$ at time $T$. Each fire will extend into both directions of the rope, burning at $1$ length/second.

Note that when a fire reaches a knot it extends to all the ropes tied to that knot.

Considering a graph $G$ and $Q$ updates, what's the time when all the ropes will burn out?

### Standard input

The first line contains $N$, $M$ and $Q$.

The next $M$ lines each describe an edge in the graph represented by $3$ integers: $A$, $B$ and $L$ describing an edge between vertices $A$ and $B$ of length $L$.

The next $Q$ lines each contain the description of the updates, represented by $4$ integers: $T$, $A$, $B$ and $X$.

### Standard output

The first line should contain the time when all ropes will burn out.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq Q \leq 10^5$ $1 \leq M \leq 2\times 10^5$ $1 \leq L_i \leq 10^9, 1 \leq i \leq M$ $0 \leq T_i \leq 10^9, i \leq i \leq Q$  $0 \leq X_i \leq \text{length of edge}, 1 \leq i \leq Q$   the given graph is connectedthe graph does not contain multiple edges or self-loopseach edge describing an update represents an edge that's present in the given graph

| Input | Output | Explanation |
| --- | --- | --- |
| 2 1 3<br>1 2 10<br>1 1 2 1<br>3 1 2 1<br>2 2 1 1 | 5.5 | The small vertical lines represent fires0246810120123412 After 2 seconds the roper will look like:024681012012342 After 2.5 seconds the roper will look like:024681012012342 |
| 4 4 2<br>4 1 3<br>1 2 5<br>2 3 1<br>4 2 2<br>0 4 1 0<br>3 2 1 1 | 5.0 | 35121234 |
| 6 8 4<br>1 3 3<br>1 2 2<br>2 4 7<br>2 5 4<br>3 4 4<br>3 6 2<br>4 5 5<br>4 6 5<br>4 2 4 2<br>1 5 4 2<br>2 3 1 2<br>4 6 4 0 | 6.5 | 32744255123456 |
