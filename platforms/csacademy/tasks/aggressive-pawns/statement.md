# Aggressive Pawns

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/aggressive-pawns/](https://csacademy.com/contest/archive/task/aggressive-pawns/)  

---

On an infinite grid, there are two pawns. The first one is located at the cell $(X_1, Y_1)$, and the second one at the cell $(X_2, Y_2)$. Each of them wants to reach to the cell $(X_3, Y_3)$.

  

In one, move, The first pawn can go only in one of the four adjacent cells,with which his current cell shares  a common edge.  (i.e. from the cell $(X, Y)$ he can go to one of the following cells: $(X \pm 1, Y)$ or $(X, Y \pm 1)$.

  

The second  pawn can go in one move in 8 cells: In addition to the first pawns, he can go in the adjacent cells on the diagonal. (i.e. he can move from $(X, Y)$ to cells $(X+a, Y+b)$, where $-1 \leq a, b \leq 1$) and $a$ and $b$ are not simultaneously 0.

  

### Standard input

The first line contains one integer $N$, denoting the number of tests.

On each of the next $N$ lines, there are 6 integers: $X_1, Y_2, X_2 , Y_2, X_3, Y_3$ in this order.

### Standard output

The output should have $N$ lines. The i-th line should have one of the following: "Same time" - if both pawns reach the target cell at the same time, "First" - if the first pawns finishes first,  or "Second" if the second one reaches first.

  

### Constraints and notes

$1 \leq N \leq 100$ $0 \leq X_i, Y_i \leq 1000$ 

| Input | Output |
| --- | --- |
| 2<br>1 1 0 0 2 2<br>0 0 1 1 2 2 | Same time<br>Second |
