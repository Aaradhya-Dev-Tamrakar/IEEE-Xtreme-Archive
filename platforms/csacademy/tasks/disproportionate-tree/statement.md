# Disproportionate Tree

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/disproportionate-tree/](https://csacademy.com/contest/archive/task/disproportionate-tree/)  

---

There is a tree with $N$ vertices. You have to assign a value to every node between 1 and $10^9$. Let $v_i$ be the value of the node $i$.  After you assigned this values, the value of an edge that connects nodes $x$ and $y$ is $2^{|v_x - v_y|}$ where $|x|$ is the absolute value of $x$. The value of the tree is the sum of all the edges that compose it.

You have to assign those values such that the value of the tree is exactly $K$.

  

### Standard input

The first line contains two integers: $N$ and $K$ (the number of nodes and the final value of the tree).

Each of the following $N-1$ lines contains two numbers $x$ and $y$ which means that there is an edge between nodes $x$ and $y$.

### Standard output

If it is impossible to put values such that the value of the tree is $K$, you have to print “NO”.

Otherwise on first line you have to print “YES” and on the second line $N$ integers. The $i$-th of them represents the value of the node $i$ which must be an integer in range $[1, 10^9]$. It can be proven that, if a solution exists, there exists a solution where all the values of the nodes are in the interval $[1, 10^9]$.

  

### Constraints and notes

$2 \leq N \leq 10^5$

$1 \leq K \leq 10^9$

$1 \leq x, y \leq N$

If there are multiple solutions, you can print any of them.

  

| Input | Output | Explanation |
| --- | --- | --- |
| 5 9<br>1 2<br>1 4<br>2 3<br>2 5 | YES<br>4 5 7 5 5 | Edge 1-2 has value $2^{5-4}=2$.Edge 1-4 has value $2^{5-4}=2$.Edge 2-3 has value $2^{7-5}=4$.Edge 2-5 has value $2^{5-5}=1$.The value of the tree is $2 + 2 + 4 + 1 = 9$ |
