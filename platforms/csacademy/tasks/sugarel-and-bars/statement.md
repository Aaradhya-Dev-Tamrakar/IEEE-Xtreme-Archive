# Sugarel and Bars

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sugarel-and-bars/](https://csacademy.com/contest/archive/task/sugarel-and-bars/)  

---

Sugarel and Sugarina live in a big city and they love going out together to various bars. The city can be represented as an directed graph.

Unfortunately, they don't live together yet, so Sugarel's house is situated at node $X$ and Sugarina's at node $Y$. They enjoy drinking a lot so if they go to a bar situated at node $i$, it's mandatory that both can go back home (nodes $X$ and $Y$ are reachable from node $i$).

Because they are a nice couple, we want to help them and extend the city so that they can go to every single bar without thinking how to return home! In order to do this, for each node $i$, we ask you to compute the minimum number of edges which should be added so that Sugarina and Sugarel can go back from it.

You need to compute the answer for every $i$ independently. Note that you need to find the answer for each node without taking care if Sugarel and Sugarina can reach that node from their homes.

### Standard input

The first line of input contains two positive integers $N$ $M$ representing the number of nodes and the number of edges.

The second line contains two integers $X$ $Y$ representing the nodes.

Each of the following $M$ lines contains two positive integers $a$ and $b$, denoting that there is a directed edge between $a$ and $b$. The graph can have loops and multiple edges.

### Standard output

The first line of the output should contain $N$ integers, $i$-th of them represent the minimum number of edges you must to add to have a path from $i$ to $X$ and from $i$ to $Y$.

### Constraints and notes

2 $\leq N \leq  10^5$  1 $\leq M \leq  2*10^5$  1 $\leq X , Y  \leq N$ $X \neq Y$ A node $P$ is reachable from a node $Q$ if there is a path from $Q$ to $P$.

| Input | Output | Explanation |
| --- | --- | --- |
| 4 2 <br>1 3<br>1 2<br>4 3 | 1 2 1 1 | 1234For nodes 1, 3 and 4, it is enough to add a single edge such that they can return to their home (nodes 1 and 3)For node 2, we need to add two edges |
