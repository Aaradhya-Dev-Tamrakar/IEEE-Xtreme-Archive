# Everything is Random

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/everything-is-random/](https://csacademy.com/contest/archive/task/everything-is-random/)  

---

Alice received from Bob a tree with $N$ nodes as her birthday present, each node having a value written on it. Remember that a tree is a connected, acyclic, undirected graph.

Because Bob did not know which kind of trees Alice likes, he randomly picked one uniformly from the set of all labelled trees with $N$ nodes.

Alice rooted the tree at vertex $1$ and then made the following operations on it:

she chose a permutation of the vertices uniformly at randomfor each node $v$ in the tree (in the order given by the permutation), she added the current value of the node $v$ to all nodes in the subtree of $v$ (including $v$)

After she finished all the operations, she calculated the sum of values written on the nodes. Your task is to calculate the expected value of this sum.

### Standard input

The first line contains the number $N$ of nodes.

Each of the following $N - 1$ lines contains two integers $u$ and $v$, meaning that there is an edge between $u$ and $v$.

The last line contains $N$ integers $A_1, A_2, ..., A_n$, where $A_i$ is the value written initially on node $i$.

### Standard output

Let $E$ be the exact answer. It can be proven that $E \cdot n!$ is an integer number. Print the value of $E \cdot n!$ modulo $10^9 + 7$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq u, v \leq n$ $0 \leq A_i \leq 10^9+6, \forall i \in {1,2,...,n}$ 

It is guaranteed that the $N - 1$ edges form a tree.

It is guaranteed that the tree was chosen uniformly from the set of all labelled trees (only $N$ and the values $A_i$ were chosen in advance).

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>3 1<br>2 3<br>1 1 2 | 88 | Here is the process for the permutation $(2, 1, 3)$:add $1$ to the subtree of $2$, new values: $1, 2, 2$ add $1$ to the subtree of $1$, new values: $2, 3, 3$ add $3$ to the subtree of $3$, new values: $2, 6, 6$ |
| 5<br>3 2<br>3 4<br>1 3<br>1 5<br>2 1 3 3 2 | 5480 |  |
| 10<br>6 2<br>1 5<br>3 6<br>10 3<br>4 7<br>8 4<br>1 8<br>10 1<br>9 10<br>8 20 13 5 17 8 20 8 10 4 | 906571513 |  |

For anyone interested, the trees were generated in the following way:

$N-2$ numbers between $1$ and $N$ were randomly chosen uniformly and independently (this will represent the Prufer sequence of the generated tree) the sequence was converted to a tree according to the bijection described here
