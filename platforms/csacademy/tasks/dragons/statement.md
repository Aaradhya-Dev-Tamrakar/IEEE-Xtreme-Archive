# Dragons

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dragons/](https://csacademy.com/contest/archive/task/dragons/)  

---

You are given a matrix with $N$ rows and $M$ columns. Some cells of the matrix are empty and others contain a dragon. You would like to choose a matrix cell such that the distance to the closest dragon is maximized.

We define the distance between a cell and a dragon as the minimum number of steps required for the dragon to reach the cell from its initial position. At each step the dragon can move in one of its (at most) eight neighbours.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ binary values: $0$ if the cell is empty or $1$ if it's occupied by a dragon. Values on a line are separated by single spaces.

### Standard output

Print the maximum distance from a cell to the closest dragon.

### Constraints and notes

$1 \leq N, M \leq 50$ There is at least one empty cell

| Input | Output |
| --- | --- |
| 5 4<br>0 0 1 0<br>0 0 0 0<br>1 0 0 0<br>0 0 0 0<br>0 0 0 1 | 2 |
| 7 4<br>0 0 0 1<br>0 1 0 0<br>0 0 0 0<br>0 0 0 1<br>0 0 0 0<br>0 1 0 0<br>0 0 0 1 | 2 |
