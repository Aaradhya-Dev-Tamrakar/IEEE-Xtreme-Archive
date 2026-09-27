# Groups

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/groups/](https://csacademy.com/contest/archive/task/groups/)  

---

$N$ people, labeled from $1$ to $N$, form $K$ groups. One person may be a part of multiple groups, but each group has an unique representative, a person which only belongs in that specific group. A group disbands if all of its members leave.

Analyse $Q$ independent scenarios. In each of them consider that several of the $N$ people leave. How many groups disband?

### Standard input

The first line constains $N$, $K$ and $Q$.

For the following $K$ lines:

The $i^{\text{th}}$ line contains $S_i$, the number of persons in the $i^{\text{th}}$ group, followed by the representative and $S_i - 1$ other persons.

For the next $Q$ lines:

The $i^{\text{th}}$ line contains $P_i$ followed by $P_i$ persons, representing a query. 

### Standard output

Print each answer on a separate line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq K \leq 10^5$ $1 \leq S_i, P_j \leq 10^5$ for $1 \leq i \leq K$ and $1 \leq j \leq Q$ $\sum_{i=1}^{K} S_i \leq 10^5$ $\sum_{j=1}^{Q} P_j \leq 10^5$ 

| Input | Output |
| --- | --- |
| 7 4 4<br>3 5 1 2<br>3 7 1 2<br>3 6 4 1<br>3 3 1 2<br>4 5 1 2 7<br>2 1 2<br>7 5 1 2 7 6 4 3<br>4 5 1 7 6 | 2<br>0<br>4<br>0 |
