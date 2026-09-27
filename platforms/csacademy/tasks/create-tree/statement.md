# Create Tree

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/create-tree/](https://csacademy.com/contest/archive/task/create-tree/)  

---

The interactor has a graph with $N$ nodes. You can ask queries of the type:

Given two nodes $v$ and $u$ is there a unique simple path between them? If the answer is no, the interactor will remove an edge that lies on a simple path between $v$ and $u$, such that the graph stays connected.

Your goal is to make the graph a tree using minimum number of queries.

### Interaction

First you should read the number $N$.

Then you can start asking your queries. Each query should consist of the character Q followed be a number two integers $v$ and $u$.

After each query read the answer given by the interactor: $1$ if the path between $v$ and $u$ was unique, $0$ otherwise.

When you are done print a single character A.

### Constraints and notes

This task is NOT adaptive$2 \leq N \leq 1000$The graph is connected and has at most $10^4$ edgesThe nodes are numbered from $1$ to $N$

InteractionExplanation5Q 3 40Q 1 50Q 4 21A123456Q 3 40Q 1 50Q 4 20Q 2 50Q 2 61Q 1 21A123456
