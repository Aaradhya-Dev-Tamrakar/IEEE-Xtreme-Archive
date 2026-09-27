# Rooks

**Time Limit:** `5000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rooks/](https://csacademy.com/contest/archive/task/rooks/)  

---

Consider a chessboard of size $N \times M$. There are $K$ rooks on the chessboard, for each of them you know its row and column.

You should answer $Q$ queries of the type:

Given a submatrix, if you consider it as a separate independent matrix, how many cells are either occupied by a rook or under attack from a rook?

### Standard input

The first line contains four integers $N$, $M$, $K$ and $Q$.

Each of the next $K$ lines contains two integers representing the row and column of a rook.

Each of the next $Q$ lines contains four integers $r_1$, $c_1$, $r_2$, $c_2$ representing the lower left and upper right corners of the submatrix.

### Standard output

For each query, print the answer on a different line.

### Constraints and notes

$1 \leq N, M \leq 3 * 10^4$ $1 \leq K, Q \leq 10^5$ The $K$ rooks are pairwise distinct 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 5 6 4<br>1 5<br>2 2<br>3 2<br>3 4<br>4 1<br>4 5<br>1 1 3 2<br>2 2 3 4<br>2 3 4 5<br>1 3 2 5 | 5<br>6<br>8<br>4 |  |
