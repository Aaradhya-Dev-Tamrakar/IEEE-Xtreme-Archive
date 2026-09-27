# Fold Polygon

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fold-polygon/](https://csacademy.com/contest/archive/task/fold-polygon/)  

---

You are given a convex polygon of $N$ vertices. A fold consists of choosing two adjacent vertices $A$ and $B$ and moving $A$ to $B$. The cost of the fold is the Euclidean distance between the two points. $A$ is discarded afterwards and the process is repeated on the newly formed polygon.

Execute the $N-1$ folds so that you minimize the sum of costs.

### Standard input

The first line an integer $T$, the number of tests in the file.

Each of the following $T$ tests follows the following format:

The first line contains an integer $N$, the number of verticesThe next $N$ lines contain two integer coordinates $X_i, Y_i$ denoting a vertexThe vertices are given in counter-clockwise order

### Standard output

For each test print a sequence of $N - 1$ moves, each move being encoded by two integers, the index of the assimilated point and the index where it has been moved. These indices should be $1$-based.

### Constraints and notes

$1 \leq T \leq 5$ $2 \leq N \leq 2\ 000$ $-10^6 \leq X_i, Y_i \leq 10^6$ for $1 \leq i \leq N$ The polygon is not strictly convex, meaning that collinear vertices may existAll vertices are distinctAfter a vertex is discarded, you may no longer refer to it again (but you can refer to the vertex where it was moved)

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>4<br>0 0<br>1 0<br>1 1<br>0 1<br>5<br>0 0<br>8 0<br>8 10<br>4 20<br>0 10 | 3 2<br>4 1<br>2 1<br>4 3<br>5 3<br>3 2<br>2 1 | The second test case:-101234567890510152025And after moving $4$ to $3$:-101234567890510152025 |
