# Max Snake

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/max-snake/](https://csacademy.com/contest/archive/task/max-snake/)  

---

Consider a matrix of size $N \times M$. We can build an associated graph where:

Each cell is a nodeTwo nodes share an edge if the two cells have a common edge

You are given a cell $(X, Y)$, find a hamiltonian path starting there or report that it's impossible.

### Standard input

The first line contains a single integer $T$, representing the number of tests.

Each of the following $T$ lines contains $4$ integers $N$, $M$, $X$ and $Y$.

### Standard output

For each test print the following:

If there is no solution output $-1$.Otherwise, print a matrix of size $N\times M$ containing distinct elements between $1$ and $N * M$. These numbers should represent the order of the cells in the hamiltonian path.

### Constraints and notes

$2 \leq N, M \leq 1000$ The sum of $N*M$ for all tests is $\leq 2 * 10^4$ $1 \leq X \leq N$ $1 \leq Y \leq M$ 

### Widget

You can use this widget to simulate the problem.

Your current position is marked in grey.Click on an empty square to move there. (must be on the same line or column as the current square, and all cells between must be empty)Click on a square with a number on it to undo all moves until that square. (must be on the same line or column as the current square, and the cells between must be consecutive numbers)Click the reset button to reset the board to square $1$.Use the fields below the matrix to set different values for $N, M, X$ or $Y$.

Reset1N:M:X:Y:

| Input | Output |
| --- | --- |
| 1<br>5 5 3 3 | 17 16 3 4 5<br>18 15 2 7 6<br>19 14 1 8 9<br>20 13 12 11 10<br>21 22 23 24 25 |
| 1<br>3 4 2 1 | 2 3 4 5<br>1 10 9 6<br>12 11 8 7 |
| 1<br>4 5 2 2 | 3 4 5 6 7<br>2 1 14 13 8<br>17 16 15 12 9<br>18 19 20 11 10 |
| 2<br>2 4 2 3<br>3 3 1 2 | 4 5 6 7<br>3 2 1 8<br>-1 |
