# Meow

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/meow/](https://csacademy.com/contest/archive/task/meow/)  

---

In the CS club there's a new Pokemon, Meow2. Being passionate about trees, Meow2 has a rooted tree with $N$ nodes, labeled from $0$ to $N-1$. Node $0$ is the root of the tree, and every for every other node $i$ its father has a label smaller than $i$. Each node has an associated value, an integer between $1$ and $L$.

Meow2 also has an array $S = [1, 2, ... L]$ of length $L$. He wants to know the number of occurrences of $S$ in the tree. More exactly, he wants to count the number of sequences $A_1, A_2, ... A_{L}$ such that the value associated with node $A_i = i$, and for each $1 \leq i < L$ node $A_i$ is an ancestor of node $A_{i+1}$.

Being an ever evolving Pokemon, Meow2 keeps changing the initial tree. He has a magical array of changes, $P$, of length $Q$. At each step $i$, $0 \leq i < Q$, he changes the value of node $i \% N$ to $P_i$, $1 \leq P_i \leq L$.

Meow2 would like to know after each change the number of occurrences of $S$ in the tree, as defined above. If we denote by $ans_i$ the number of occurrences of $S$ after the $i^{th}$ change, you should find:

$O = 1 * ans_0 + 2 * ans_i +  ... + Q * ans_{Q-1}$ 

### Standard input

The first line contains $3$ integers $N$, $L$ and $Q$.

The second line contains an array $F$ of length $N-1$, where $F_i$ is the father of node $i$.

The third line contains an array of length $N$, representing the initial values of the nodes.

The next $Q$ lines contains an integer each, representing the changes made on the tree.

### Standard output

Output a single integer $O$ modulo $10^9+7$.

### Constraints and notes

$1 \leq N\leq 10^5$ $1 \leq L \leq N$ $1 \leq Q \leq 2 * 10^5$ For 20% of the testcases, $N \leq 200, L \leq 30, Q \leq 400$ For 50% of the testcases, $N \leq 5000, L \leq 300, Q \leq 5000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 6 2 6<br>0 1 0 3 0<br>1 2 1 2 1 2<br>2<br>1<br>2<br>1<br>2<br>1 | 29 | The individual answers are: $0, 0, 1, 1, 2, 2$Below you can see the tree after the first update0(2)1(2)2(1)3(2)4(1)5(2) |
