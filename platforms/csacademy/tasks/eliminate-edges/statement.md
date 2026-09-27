# Eliminate Edges

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/eliminate-edges/](https://csacademy.com/contest/archive/task/eliminate-edges/)  

---

You are given a simple connected graph with $N$ nodes and $M$ edges. The interactor will ask $Q$ queries of the type:

Given two nodes $v$ and $u$, is there a unique simple path between them? If the answer is no, you should remove an edge that lies on a path between $v$ and $u$, such that the graph stays connected.

### Interaction

First you should read three integers $N$, $M$ and $Q$. After that, read $M$ pairs of integers representing two ndoes that share an edge.

The $Q$ queries follow, each consisting of two nodes $v$ and $u$. After reading each query, you should print your answer:

If there is a unique simple path between $v$ and $u$ print $1$ If the path is not unique, print $0$ followed by two integers representing the edge you remove

You should answer a query before reading the next one.

### Constraints and notes

This task is NOT adaptiveBeware that interactive problems  have a big time constant.$2 \leq N \leq {10\,000}$ $1 \leq M, Q \leq {25\,000}$ The nodes are numbered from $1$ to $N$

InteractionExplanation4 5 4
1 2
1 3
2 3
2 4
3 4
2 40 3 41 40 2 33 412 3112347 10 7
1 2
2 3
2 4
3 4
3 7
4 5
4 6
5 6
5 7
6 7
1 30 4 21 313 60 6 73 60 5 63 60 3 43 614 711234576
