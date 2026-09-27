# Mountain Time

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/mountain-time/](https://csacademy.com/contest/archive/task/mountain-time/)  

---

The topographic prominence of a mountain is defined as the smallest difference between its height and the elevation of the lowest point on any path connecting the mountain to any strictly higher summit.

  

A topographic map is given by an $N \times M$ rectangular matrix $h$ of cell elevations. Each cell has the usual four neighbors: up, left, down, and right. A path is the usual sequence of neighbors.

The topographic prominence of a cell is:

•        the cell’s elevation, if there is no other strictly higher cell

•        cell height minus the highest elevation of the lowest cell on a path going to a strictly higher cell.

Clarification: Consider all paths starting from the given cell and ending on some other cell with a strictly higher elevation. For each of these paths, consider the cell with the lowest elevation $h_{min}$ in this path. The topographic prominence is the maximum of such $h_{min}$.

  

For the above example (the one in the example), the cell at $(1, 8)$ has prominence of $6-4=2$, because, in order to reach a higher elevation from $(1, 8)$, one would have to descend to at least as low as $h_{2, 7} = 4$.

  

If there is a path from a cell to some other cell with a higher elevation without going through any cells with a lower elevation than the starting cell, the prominence is naturally $0$.

  

### Standard input

  

The first line contains $N$ and $M$ separated by a space.

Each of the following $N$ lines contains $M$ space-separated integers, representing the elevations $h_{i, j}$ ($1 \leq i \leq N, 1 \leq j \leq M$).

  

### Standard output

  

$N$ lines with the $M$ prominence values of each cell in the same order and format as in input.

  

### Constraints and notes

  
$1 \leq N, M \leq 10^3$ $0 \leq h_{i, j} \leq 10^6$   

| Input | Output |
| --- | --- |
| 5 8<br>4 6 7 5 5 2 5 6<br>5 8 9 7 6 3 4 5<br>4 6 7 8 7 6 5 3<br>3 4 6 8 6 4 2 1<br>2 3 5 5 4 3 2 0 | 0 0 0 0 0 0 0 2<br>0 0 9 0 0 0 0 0<br>0 0 0 1 0 0 0 0<br>0 0 0 1 0 0 0 0<br>0 0 0 0 0 0 0 0 |
