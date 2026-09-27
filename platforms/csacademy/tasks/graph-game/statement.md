# Graph Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/graph-game/](https://csacademy.com/contest/archive/task/graph-game/)  

---

Alex and Bob play a game on an undirected simple graph with $N$ nodes and $M$ edges. The two players take turns playing, Alex being the first to move. A move consists of choosing a node with even degree and removing it and its incident edges from the graph. The player who cannot make a move looses.

Considering that both players play optimally, compute the outcome of the game.

### Standard input

The first line contains an integer $T$, the number of game scenarios that you are given.

The first line of each of the $T$ scenarios contains two integers $N$ and $M$.

Each of the next $M$ lines contains two integers representing two nodes that share an edge.

### Standard output

For the $i$-th scenario if Alex wins the game print $1$, otherwise print $0$, on the $i$-th line of the output.

### Constraints and notes

$1 \leq T \leq 10$$1 \leq N, M \leq 10^5$ $\sum{M} \leq 2 \cdot 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>3 3<br>1 2<br>2 3<br>3 1<br>8 7<br>1 2<br>1 3<br>2 4<br>3 4<br>5 6<br>5 7<br>7 8 | 1<br>0 | For the first scenario, Alex can choose to pick node 1 and win the game.123For the second scenario, no matter how Alex plays, he has no winning strategy against Bob.12345678 |
