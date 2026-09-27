# Football Tournament

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/football-tournament/](https://csacademy.com/contest/archive/task/football-tournament/)  

---

In a football tournament there were $N$ teams. Each pair of teams played two matches, one at the home stadium of the first team and another at the home stadium of the second team.

The tournament has already taken place and you are given the results of each match. None of them ended in a draw. Find out who won the tournament.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains $N$ integers representing the results of the matches. The $i$-th element of the $j$-th line contains the result of the match the $i$-th team played at home with the $j$-th team.

A match won by the home team is represeneted by an element equal to $1$, while a match won by the visiting team is represented by $2$. The $i$-th element of the $i$-th line is always equal to $0$, because a team can't play against itself.

### Standard output

Print a single integer representing the index of the team that won the most matches. In case the answer is not unique, the team with the smallest index is declared the winner.

### Constraints and notes

$2 \leq N \leq 100$ 

| Input | Output |
| --- | --- |
| 3<br>0 2 2<br>1 0 1<br>1 2 0 | 2 |
| 4<br>0 1 1 2<br>2 0 1 2<br>1 1 0 1<br>2 1 1 0 | 1 |
