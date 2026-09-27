# MST and Rectangles

**Time Limit:** `10000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rectangle-mst/](https://csacademy.com/contest/archive/task/rectangle-mst/)  

---

You have a 2D array $A$ of size $N \times N$. Each cell initially contains $0$.

You are also given $M$ queries of the form $X_1$, $X_2$, $Y_1$, $Y_2$, $W$, which means you should perform the following operation on $A$:

for each pair of integers $(i, j)$ where $X_1 \le i \le X_2$ and $Y_1 \le j \le Y_2$, add $W$ to the value of cell $A_{i,j}$ and to the cell $A_{j,i}$.

Consider an undirected graph $G$ with $N$ vertices. For each $1 \le i, j \le N$, there is an edge connecting vertices $i$ and $j$ with cost $A_{i,j}$. Calculate the cost of Minimum Spanning Tree of $G$.

### Standard input

The first line contains a single integer $M$, number of queries.

The next $M$ lines each contain five integers $X_1$, $X_2$, $Y_1$, $Y_2$, $W$, describing a query.

### Standard output

Print a single integer on the first line, the cost of Minimum Spanning Tree of graph $G$.

### Constraints and notes

$1 \le N, M \le 10^5$ $1 \le X_1 \le X_2 < Y_1 \le Y_2 \le N$ $-10^6 \le W \le 10^6$ 

| Input | Output |
| --- | --- |
| 5 3<br>1 1 2 4 10<br>2 2 3 4 10<br>3 3 4 4 10 | 0 |
| 5 5<br>3 3 4 5 -10<br>1 2 3 4 20<br>4 4 5 5 -10<br>2 2 4 4 -20<br>1 1 2 4 0 | -20 |
| 6 8<br>1 3 6 6 3<br>4 4 6 6 10<br>3 3 5 6 -8<br>1 2 5 5 -7<br>1 2 6 6 -1<br>1 3 4 5 6<br>3 5 6 6 7<br>2 3 6 6 3 | -2 |
