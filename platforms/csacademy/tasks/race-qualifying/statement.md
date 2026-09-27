# Race Qualifying

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/race-qualifying/](https://csacademy.com/contest/archive/task/race-qualifying/)  

---

In Formula 1 the starting order of the drivers is determined using a qualifying session. But because some drivers don't always respect the regulations, the organisers had to come up with a penalty system.

When a driver breaks some rules, he is penalised a certain number of positions on the starting grid. For example if the fastest driver in the qualifying session gets a penalty of $2$ places he will actually start $3^{rd}$ in the race.

It's interesting that the number of penalty places can actually exceed the total number of drivers. For example, if we have $3$ drivers and the fastest one gets a penalty of $10$ places and the second fastest one gets a penalty of $5$ places, they will start on the first $3$ places of the grid, but in reverse order of their qualifying times.

Another important aspect concerns the case where two drivers should start on the same place, taking into account their penalties. For example, if we have $2$ drivers and the first one gets a penalty of $2$ places and the second one a penalty of one place. In these cases the driver with the smallest penalty will start in front of the other.

Knowing the penalty for each of the $N$ drivers, find their starting order in the race.

### Standard input

The first line contains a single integer $N$.

The second line contains an array $A$ of $N$ integers, where $A_i$ is the penalty of the $i^{th}$ fastest driver in the the qualifying session.

### Standard output

Print a permutation of size $N$ on the first line, representing the starting order of the drivers.

### Constraints and notes

$1 \leq N \leq 100$ $0 \leq A_i \leq 1000$

| Input | Output |
| --- | --- |
| 2<br>10 0 | 2 1 |
| 5<br>1 0 3 2 1 | 2 1 5 4 3 |
