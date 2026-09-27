# Red Blue Teams

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/red-blue-teams/](https://csacademy.com/contest/archive/task/red-blue-teams/)  

---

$N$ children are playing a game. They are split in two teams, $R$ of them are in the red team and $N-R$ are in the blue team.

You also know that exactly $K$ of them will switch teams. Find the minimum and maximum possible number of children in the red team after they all switch teams.

### Standard input

The first line contains three integers $N$, $R$ and $K$.

### Standard output

Print two integers, the minimum and the maximum possible numbers of children in the read team.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq R, K \leq N$ A child cannot switch sides more than once

| Input | Output | Explanation |
| --- | --- | --- |
| 6 3 2 | 1 5 | For the minimum value, $2$ children can switch from red to blue.For the maximum value, $2$ children can switch from blue to red. |
| 4 3 2 | 1 3 | Minimum value: $2$ children switch from red to blue.Maximum value: $1$ child will switch from blue to red and $1$ from red to blue.Note that exactly $K$ children must switch teams. |
| 4 3 4 | 1 1 | Note that all the children must switch teams. Before switching, there were $3$ children in the red team and $1$ in the blue one. After all of them switch sides, there is only $1$ child in the red team. |
| 10 7 2 | 5 9 |  |
