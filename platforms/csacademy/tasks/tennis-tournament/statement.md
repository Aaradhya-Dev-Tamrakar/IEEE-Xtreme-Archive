# Tennis Tournament

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tennis-tournament/](https://csacademy.com/contest/archive/task/tennis-tournament/)  

---

There are $2^N$ players that are going to take part in a tennis tournament. Each player $i$ has a skill level equal to $i$. When two people play against each other, the one with a higher skill level will always win.

Before the tennis tournament, the players will be permuted in a certain way. In the first round, matches will be played between $P_1$ and $P_2$, $P_3$ and $P_4$, and so on, where $P_i$ is the $i^{th}$ player in the permutation.

In the second round, the winner of the first match from the previous round will face the winner of the second match. The winner of the third match will face the winner of the fourth match, and so on. In the final, the best player from the first half of the permutation will play against the best player from the second half.

Given two integers $K$ and $M$, find a permutation such that the player with skill $K$ will win $M$ matches before he is eliminated (or wins the tournament if $M = N$).

### Standard input

The first line contains three integers $N$, $K$ and $M$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the permutation on the first line.

### Constraints and notes

$1 \leq N \leq 15$ $1 \leq K \leq 2^N$ $0 \leq M \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2 2 0 | 2 4 1 3 | 24413   34 |
| 2 2 1 | 4 3 2 1 | 4432214 |
| 2 4 2 | 2 3 1 4 | 2331444 |
| 3 6 2 | 5 4 1 6 7 8 3 2 | 5416783256 83688 |
| 3 6 1 | 8 5 2 6 3 7 1 4 | 8526371486 73878 |
| 2 1 1 | -1 | There is no way that player 1 can win a game, since he loses against all other players. |
