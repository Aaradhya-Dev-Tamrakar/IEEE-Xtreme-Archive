# Endgame

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/endgame/](https://csacademy.com/contest/archive/task/endgame/)  

---

You are given $N$ intervals with the ends in [$-10^9$, $+10^9$].

A chain is a maximal set of intervals with the property that for any interval $I$ in the set, there is an interval $J$ in the set $(I \neq J)$ such that their intersection is non-empty or $I$ is the only interval in the set (the intersection is considered non-empty even if the intervals intersect in a single point).

Let's define the following operation: for a selected $X$ real point, any interval containing $X$ is eliminated.

Find the maximum number of chains that can be obtained from the remaining intervals by applying exactly one operation.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines describes one interval. The line contains two integers $l_i$ and $r_i$, representing the left end and the right end of the current interval.

### Standard output

Print a single integer representing the maximum number of chains that can be obtained by performing  exactly one operation.

### Constraints and notes

$1 \leq N \leq 10^5$. $-10^9 \leq l_i \leq r_i \leq +10^9$. The intervals are closed at both ends. 

| Input | Output |
| --- | --- |
| 4<br>1 3<br>4 5<br>8 9<br>1 10 | 3 |
| 2<br>1 4<br>5 7 | 2 |
| 5<br>1 4<br>2 3<br>4 8<br>5 6<br>7 8 | 3 |
