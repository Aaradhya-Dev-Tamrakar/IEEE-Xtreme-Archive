# Pinball

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pinball/](https://csacademy.com/contest/archive/task/pinball/)  

---

— Calm yourselves a little...

We have a ball which lies on the $X$ axis, initially placed at the $0$ coordinate. We also have $N$ sets of walls which lie on the $X$ axis. Each set is described as a tuple $(dir, len, freq)$ where:

$dir$ indicates the direction in which the walls are placed, which can either be $L$ (left) or $R$ (right)if $dir = L$, then the walls in the set are placed at $\\-len, -2*len, -3*len, \dots, -freq*len$if $dir = R$, then the walls in the set are placed at $\\len, 2 * len, 3*len, \dots, freq * len$

Note that through the nature of these informations, there can be multiple walls placed at the same coordinate.

At time $T = 0$ the ball starts moving to the right with a constant speed of $1$ unit per second. When the ball hits a wall, the wall is automatically destroyed and the ball reverses its direction. (If there are multiple walls situated at the same coordinate, only one of the walls is destroyed).

You are given $Q$ queries. For each query you are given an integer $T$. Output the coordinate of the ball after $T$ seconds.

### Standard input

The first line of input will contain the integers $N$ and $Q$, separated by one space.

The next $N$ lines contain three space-separated integers, $dir$, $len$ and $freq$, describing how the walls are placed.

The next $Q$ lines contain an integer, $T$, describing a query.

### Standard output

Output $Q$ lines, the $i-th$ line should contain the answer for $i-th$ query.

### Constraints and notes

$1\leq N, Q \leq  250\ 000$ $1\leq T \leq 10^{12}$ $dir \in \{L, R\}$ $1\leq len, freq \leq 10^{12}$ 

#PointsRestrictions113$N, Q \leq 1000$28$Q, T \leq 1000$316$1 \leq len \leq 10$410$T \leq 10^6$511$len \cdot freq \leq 10^6$69Let $S$ be the sum of all $freq$ in the input. $S \leq 10^6$733No further restrictions.

| Input | Output |
| --- | --- |
| 3 12<br>R 3 2<br>R 6 1<br>L 3 2<br>0<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>17<br>18<br>19<br>200 | 0<br>1<br>2<br>3<br>2<br>1<br>0<br>-1<br>5<br>6<br>5<br>-152 |
