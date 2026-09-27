# Win Percentages

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/win-percentages/](https://csacademy.com/contest/archive/task/win-percentages/)  

---

You are playing a mobile game that consists of several independent matches. Up until last month, you played $G_1$ games and you had a win percentage of $P_1$. Right now, your stats show that you played $G_2$ games and you have a win percentage of $P_2$.

Both percentages are shown as floored integers. So for example if you played $1000$ matches and you won $505$, your real win percentage is $50.5$, but it will be shown in the stats as $50$. Considering this, your goal is to find the maximum number of matches you could've won out of the last $G_2 - G_1$ matches.

### Standard input

The first line contains four integers $G_1$, $P_1$, $G_2$, $P_2$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq G_1 < G_2 \leq 10^6$ $0 \leq P_1, P_2 \leq 100$ It is guaranteed the tests are based on a real scenario, so a valid solution always exists.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 33 5 60 | 2 | In the first part, the player wins 1 game and at the end he wins 3 games, resulting in 2 games won between the periods. |
| 10 50 30 76 | 18 | In the first part, the player wins 5 games and at the end he wins 23 games, resulting in 18 games won between the periods. |
| 1000 13 2000 48 | 849 | In the first part, the player wins 130 games and at the end he wins 979 games, resulting in 849 games won between the periods. |
