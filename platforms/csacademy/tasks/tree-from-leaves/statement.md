# Tree From Leaves

**Time Limit:** `5000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-from-leaves/](https://csacademy.com/contest/archive/task/tree-from-leaves/)  

---

In this problem you should find the structure of a tree with $N$ nodes.

The tree is generated using the following algorithm:

Intially we consider the tree consisting of a single node labeled $1$Then we add the nodes one by one, in increasing order of labels from $2$ to $N$When we add the node labeled $i$ we connect it to one of the previously added nodes randomly (using a uniform distribution).

After we finish generating the tree we relabel the nodes such that the leaves are labeled from $1$ to $K$, where $K$ is the total number of leaves.

You are allowed to choose any two leaves and ask the length of the path connecting them.

### Interaction

First you should read the number of leaves $K$.

Then you can start ask the queries: print the character Q followed by two distinct numbers between $1$ and $K$, representing the leaves.

After each query read the answer representing the distance between the leaves.

When you are done, print the character A followed by a number $N$, representing the total number of tree nodes. On each of the next $N-1$ lines print two values, representing two nodes that share an edge.

The tree you print should respect the following:

Nodes are labeled from $1$ to $N$Leaves are labeled from $1$ to $K$The distance between any two leaves is the same as in the interactor's treeIt is isomorphic with the interactor's tree

### Constraints and notes

This task is NOT adaptive$4 \leq N \leq 1000$$3 \leq K < N$You are allowed to ask at most $15\ 000$ queries

Interaction3Q 1 22Q 1 32Q 2 32A
4
1 4
2 4
3 43Q 1 23Q 1 33Q 2 32A
5
1 5
2 4
3 4
4 53Q 1 23Q 1 33Q 2 34A
6
1 4
2 5
3 6
4 5
4 63Q 1 25Q 1 33Q 2 34A
7
1 5
2 6
3 4
4 5
4 7
6 7
