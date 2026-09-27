# Tournament Swaps

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tournament-swaps/](https://csacademy.com/contest/archive/task/tournament-swaps/)  

---

There are $2^N$ players that are going to take part in a tennis tournament. Each player $i$ has a skill level equal to $i$. When two people play against each other, the one with a higher skill level will always win.

Before the tennis tournament, the players will be permuted in a certain way. In the first round, matches will be played between $P_1$ and $P_2$, $P_3$ and $P_4$, and so on, where $P_i$ is the $i^{th}$ player in the permutation.

In the second round, the winner of the first match from the previous round will face the winner of the second match. The winner of the third match will face the winner of the fourth match, and so on. In the final, the best player from the first half of the permutation will play against the best player from the second half.

You need to analyse $2^N$ independent scenarios. In the $i^{th}$ scenario the player having skill level $i$ is allowed to swap places with any other player (he can also choose to do nothing). Find the maximum number of matches he can win.

### Standard input

The first line contains a single integer $T$, representing the number of tests that follow.

Each test consists of several lines:

The first line contains a single integer $N$.The second line contains $2^N$ integers representing the initial permutation of the players.

### Standard output

For each test case, print a line with $2^N$ integers. The $i^{th}$ integer should representing the maximum number of matches the player with skill level $i$ can win.

### Constraints and notes

$1 \leq T \leq 10^5$ $1 \leq N \leq 17$ The sum of $2^N$ for all $T$ test cases is $\leq 2*10^5$ 

| Input | Output |
| --- | --- |
| 1<br>2<br>1 2 3 4 | 0 1 1 2 |
| 2<br>3<br>1 6 8 7 5 2 3 4<br>3<br>1 8 2 7 3 6 4 5 | 0 1 1 1 2 2 2 3 <br>0 1 1 1 1 2 2 3 |
