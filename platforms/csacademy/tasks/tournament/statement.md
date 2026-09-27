# Tournament

**Time Limit:** `1000 ms`  
**Memory Limit:** `16 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tournament/](https://csacademy.com/contest/archive/task/tournament/)  

---

This problem has an unusual memory limit!

Consider a tournament with $N = 2^K$ competitors, labeled $0, 1, \ldots 2^K - 1$. Every of them has a certain power, more specifically $i^{\text{th}}$s power is $P_i$. These powers are represented  by distinct positive integers less than $2^K$. A game between two players is won by the one with the greater power.

In the first stage of the tournament, $2^{K-1}$ games are played; the $i^{\text{th}} \ (0 \leq i < 2^{K-1})$ is between competitors $2 * i$ and $2 * i + 1$. Only the winners of this stage remain in the tournament and they are conveniently relabeled from $0$ to $2^{K-1}-1$. The process continues until there is only one competitor left, who is declared the winner of the tournament.

You are to consider $Q$ independant scenarios: what is the maximum number of games that the competitor with power $X$ can win, if we were to perform at most $Y$ swaps in $P$ beforehand? $X$ may also be moved during these swaps.

### Standard input

The first line contains two integers $N$ and $Q$.

The next line contains $N$ integers, representing $P$.

Each of the next $Q$ lines contains two integers $x_i$ and $y_i$. You should compute:

$X_i = (x_i + \text{last}) \ \text{mod} \ N$ $Y_i \ = (y_i + \text{last}) \ \text{mod} \ N$ $\text{last}$ is the answer of the previous query, initially $\text{last} = 0$

The pair $(X_i, Y_i)$ represent the values of the $i^{\text{th}}$ query.

### Standard output

Print each answer on a separate line.

### Constraints and notes

$N = 2^K$ $2 \leq K \leq 19$ $1 \leq Q \leq 250000$ $0 \leq X, Y < N$

| Input | Output |
| --- | --- |
| 4 4<br>3 2 0 1<br>1 0<br>3 1<br>3 1<br>0 0 | 1<br>0<br>2<br>1 |
| 8 5<br>2 7 3 0 1 4 6 5<br>3 1<br>1 6<br>0 4<br>3 6<br>5 5 | 2<br>1<br>1<br>2<br>3 |
