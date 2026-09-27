# Marbles Graph Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/marbles-graph-game/](https://csacademy.com/contest/archive/task/marbles-graph-game/)  

---

Alex and Ben have a DAG with $N$ nodes and $M$ edges. They also have $K$ marbles that they place on some of the graph's nodes (there can be more than one marble on the same node).

Alex and Ben want to play the game where each of them takes turns moving, Alex being the first to play. A valid move consists in taking each marble and moving it along one of the outgoing arcs of the current marble node. The player who cannot move at least one marble loses the game.

If both of them play optimally find out the outcome of the game.

### Standard input

The first line contains three integers $N$, $M$, and $K$.

The next line contains $K$ numbers representing the nodes where the marbles are placed initially.

Each of the next $M$ lines contains two integers representing two nodes that share an arc.

### Standard output

If Alex wins print $A$, otherwise print $B$.

### Constraints and notes

$1 \leq N, M, K \leq 10^5$

| Input | Output |
| --- | --- |
| 6 6 2<br>4 6<br>2 1<br>3 2<br>4 3<br>5 3<br>6 2<br>6 5 | A |
| 9 13 3<br>6 8 9<br>2 1<br>3 1<br>4 3<br>5 2<br>5 4<br>6 2<br>6 5<br>7 4<br>7 6<br>8 7<br>8 5<br>9 8<br>9 4 | A |
