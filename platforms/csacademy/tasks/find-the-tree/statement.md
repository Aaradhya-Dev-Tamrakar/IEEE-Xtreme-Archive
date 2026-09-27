# Find the Tree

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/find-the-tree/](https://csacademy.com/contest/archive/task/find-the-tree/)  

---

You should find the edges of a tree with $N$ nodes. You can ask queries of the type:

For a chosen triplet of nodes $(A, B, C)$, which is the node $D$ that minimizes the sum of distances $AD + BD + CD$?

The tree is generated using the following algorithm:

Initially we consider the tree consisting of a single node labeled $1$ Then we add the nodes one by one, in increasing order of labels from $2$ to $N$ When we add the node labeled ii we connect it to one of the previously added nodes randomly (using a uniform distribution).After we finish generating the tree we relabel the nodes applying a random permutation.

### Interaction

First you should read a single integer $N$.

Then you can start asking the queries. Each query should consist of the character Q followed be three integers $A$, $B$ and $C$.

When you determine the tree, print the character A followed by $N-1$ pairs of integers representing the edges.

### Constraints and notes

This task is NOT adaptive$2 \leq N \leq 2000$ You can ask at most $25\,000$ queries

InteractionExplanation7Q 5 6 74Q 1 6 73Q 3 4 64Q 5 7 23A
3 2
4 3
1 2
3 7
6 4
5 41234567
