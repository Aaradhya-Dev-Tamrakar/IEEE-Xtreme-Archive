# Fast Travel

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fast-travel/](https://csacademy.com/contest/archive/task/fast-travel/)  

---

In a country there are $N$ cities represented as points on a plane. Some of these cities are special. Normally, the time needed to travel between two cities is equal to the Manhattan distance between them. In addition, if both cities are special you can teleport between them in $T$ time units.

You should answer $Q$ queries of the form:

Given to cities $A$ and $B$, what's the fastest travel time from $A$ to $B$?

### Standard input

The first line contains two integers $N$ and $T$.

Each of the following $N$ lines contains three integers $s\ x\ y$, where $s$ is $1$ if the city is special, $0$ if not, and $(x, y)$ represent the coordinates of the city.

The next line contains a single integer $Q$.

Each of the next $Q$ lines contains two integers $A$ and $B$.

### Standard output

Output $Q$ lines, each containing a single integer representing the answer for a query.

### Constraints and notes

$2 \leq N \leq 1000$ $1 \leq T \leq 2000$ $1 \leq Q \leq 1000$ $0 \leq x, y \leq 1000$There are no two points that share the same coordinates.

| Input | Output |
| --- | --- |
| 6 3<br>0 1 2<br>0 5 1<br>1 3 3<br>1 1 5<br>0 3 5<br>1 7 5<br>5<br>1 2<br>1 5<br>1 6<br>3 4<br>4 2 | 5<br>5<br>6<br>3<br>7 |
