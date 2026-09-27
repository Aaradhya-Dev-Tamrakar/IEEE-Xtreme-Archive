# Matrix Exploration

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/matrix_exploration/](https://csacademy.com/contest/archive/task/matrix_exploration/)  

---

You are given a matrix of size $N \times M$, where an empty cell is represented by a . , and a forbidden cell is represented by a #. You also know that $K$ of the empty cells are special.

For each empty cell you should compute the shortest distance to any special cell. You should consider that two cells are adjacent if they share a common side. For the special cells the computed value should be $0$.

### Standard input

First line contains three integers $N$, $M$ and $K$.

Each of the next $N$ lines contains $M$ characters, either . or #, representing the matrix.

Each of the next $K$ lines contains a pair of two integers $X$ and $Y$, representing the line and the column of a special cell.

### Standard output

Output a single number representing the sum of the computed distances for each empty cell.

### Restrictions and notes

$1 \leq N \leq 1 000$$1 \leq M \leq 1 000$$1 \leq K \leq 500$$1 \leq X \leq N$$1 \leq Y \leq M$It is guaranteed that there is a path from every empty cell to at least one special cell.

| Input | Output |
| --- | --- |
| 6 6 2<br>.....#<br>.###.#<br>...#.#<br>.#####<br>.....#<br>######<br>3 5<br>5 3 | 50 |
