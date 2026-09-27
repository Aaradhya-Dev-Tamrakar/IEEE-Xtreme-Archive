# Count Squares

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/count-squares/](https://csacademy.com/contest/archive/task/count-squares/)  

---

Consider the set $S$ of all the points having the x coordinate between $0$ and $N$ and the y coordinate between $0$ and $M$ (there are $(N+1) * (M+1)$ points in total). Count the numbers of ways of choosing exactly $4$ points from $S$ such that they are the vertices of a square.

Please note that the square shouldn't necessarily have the sides parallel to the axis.

### Standard input

The first line contains two integer $N$ and $M$.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \leq N, M \leq 10^6$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 1 4 | 4 | There are $4$ $1*1$ squares |
| 2 2 | 6 | There are  $4$ $1*1$ squares.The other $2$ squares are below:-0.500.511.522.533.54-0.500.511.522.5-0.500.511.522.533.54-0.500.511.522.5 |
| 2 3 | 10 |  |
| 3 3 | 20 | One square that is counted in the solution would be0123450123 |
