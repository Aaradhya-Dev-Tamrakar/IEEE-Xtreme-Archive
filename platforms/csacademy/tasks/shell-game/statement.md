# Shell Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/shell-game/](https://csacademy.com/contest/archive/task/shell-game/)  

---

In the shell game, three or more identical containers (which may be cups, shells, bottle caps, or anything else) are placed face-down on a surface. A small ball is placed beneath one of these containers so that it cannot be seen, and they are then shuffled by the operator in plain view

Given $N$, the number cups, $X$, the cup under which the ball is placed initially and $Q$, the number of cup swaps, determine the final position of the ball.

When swapping the cups at positions $a$ and $b$, if the ball was initially under the cup at position $a$, it'll be situated under the cup at position $b$ after the swap.

### Standard input

The first line contains $3$ integers $N$, $Q$ and $X$.

The next $Q$ lines each contain $2$ integers $a$ and $b$ describing the positions of the cups that will be swapped.

### Standard output

The first line should contain a number $Y$ representing the position of the cup under which the ball is situated.

### Constraints and notes

$1 \leq N \leq 100$ $1 \leq Q \leq 100$ $1 \leq X \leq 100$ $1 \leq a_i \leq N, 1 \leq b_i \leq N, a \neq b$ for each $1 \leq i \leq Q$ 

| Input | Output |
| --- | --- |
| 4 4 3<br>1 2<br>2 3<br>3 4<br>1 2 | 1 |
| 5 5 2<br>1 2<br>3 4<br>5 4<br>3 2<br>1 2 | 2 |
| 3 3 1<br>1 2<br>1 2<br>1 2 | 2 |
