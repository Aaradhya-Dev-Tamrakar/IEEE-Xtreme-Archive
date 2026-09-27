# Disjoint Tree Paths

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/disjoint-tree-paths/](https://csacademy.com/contest/archive/task/disjoint-tree-paths/)  

---

Alex and Ben play a game on a tree with $N$ nodes. Initially, each of them have a pawn in one of the tree's nodes. The two players take turns playing, Alex being the first to move. In a move a player is allowed to take his pawn and move it to an adjacent node, if that node was not previously visited by any of the two pawns. The player who cannot make a move loses the game.

If both of them play optimally, find the winner of the game.

### Standard input

The first line contains a single integer $T$, representing the number of tests that follow.

Each test consists of several lines:

The first line contains three integers $N$, $A$ and $B$, representing the number of nodes in the tree and the initial nodes of Alex's and Ben's pawns.Each of the next $N-1$ lines contains two integers representing two nodes that share an edge.

### Standard output

For each test, print the answer on a distinct line. If Alex wins, print a single character A, otherwise print a single character B.

### Constraints and notes

$1 \leq T \leq 10^5$ $2 \leq N \leq 10^5$ The sum of $N$ for all $T$ tests is $\leq 10^5$ $1 \leq A, B \leq N$ $A \neq B$

| Input | Output | Explanation |
| --- | --- | --- |
| 1<br>10 6 10<br>1 2<br>2 5<br>2 3<br>3 6<br>6 4<br>3 8<br>8 7<br>8 10<br>10 9 | A | Alex can make the following moves in order to win:$6->3$ $3->2$$2->5$Note that Ben can't move the pawn into node $3$ since it was visited by Alex.12345687109 |
| 2<br>5 1 5<br>1 2<br>2 3<br>3 4<br>4 5<br>5 2 3<br>1 2<br>2 3<br>3 4<br>4 5 | A<br>B | 12345 |
