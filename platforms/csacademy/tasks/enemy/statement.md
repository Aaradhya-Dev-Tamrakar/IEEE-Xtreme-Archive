# Line Enemies

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/enemy/](https://csacademy.com/contest/archive/task/enemy/)  

---

There is an empty set of intervals $S$. You should handle 3 types of queries:

Query $1$. Add an interval $[L, R]$ to $S$. It is guaranteed that this interval doesn't exist in S. Query $2$. Remove an interval $[L, R]$ from $S$. It is guaranteed that such interval exists in S.Query $3$. Build an undirected graph $G$. Vertices of $G$ are intervals from set $S$. Two vertices are connected with an edge if and only if their intervals do NOT have common points (including their ends). Given two intervals $[L_1, R_1], [L_2, R_2] \in S$, you should calculate the length of the shortest path from $[L_1, R_1]$ to $[L_2, R_2]$ in $G$.

### Standard input

The first line contains a single integer $Q$, number of queries.

The next $Q$ lines contain queries, one per line. The first integer on each line is the type of query. If the type is $1$ or $2$, two integers follow, denoting an interval $[L, R]$. If the type is $3$, four integers follow, denoting intervals $[L_1, R_1]$ and $[L_2, R_2]$.

### Standard output

For each query of type $3$ print the length of the shortest path on a separate line. If there is no path from $[L_1, R_1]$ to $[L_2, R_2]$ in $G$, print $-1$.

### Constraints and notes

$1 \leq Q \leq 10^5$

$1 \leq L \leq R \leq 10^9$ for each interval $[L, R]$

| Input | Output | Explanation |
| --- | --- | --- |
| 8<br>1 1 2<br>1 4 5<br>1 2 3<br>3 1 2 4 5<br>3 1 2 2 3<br>3 1 2 1 2<br>2 4 5<br>3 1 2 2 3 | 1<br>2<br>0<br>-1 | Query $1$ Interval $[1, 2]$ has a direct edge to $[4, 5]$Query $2$:Interval $[1, 2]$ has a direct edge to $[4, 5]$ Interval $[4, 5]$ has a direct edge to $[2, 3]$ Query $3$:The 2 intervals represent the same element in the set, so the distance is $0$Query $4$:After deleting interval $[4, 5]$ there's no path from $[1, 2]$ to $[2, 3]$ |
