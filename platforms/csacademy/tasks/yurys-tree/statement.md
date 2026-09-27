# Yury's Tree

**Time Limit:** `4000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/yurys-tree/](https://csacademy.com/contest/archive/task/yurys-tree/)  

---

Yury has a rooted tree with $N$ nodes where node $1$ is the root. The edges of this tree have weights and the nodes have values. You should perform a total of $Q$ operations of the form:

Query: What is the value of a certain node $v$?Update: You are given three integers $x$, $y$ and $v$. You should add $x$ to the value of all the nodes $u$ in the subtree of $v$ if all the weights of the edges on the path from $u$ to $v$ are $\geq y$.

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains $N$ values representing the inital values of the nodes.

Each of the next $N-1$ lines contains three integers $a$, $b$ and $w$, representing an edge between nodes $a$ and $b$ having weight $w$.

The next $Q$ lines describe the operations. Each line will either be of the form $1\ v$ in the case of a query or $2\ x\ y\ v$ in the case of an update.

### Standard output

The output should contain the answers for all the operations of type $1$, each on a separate line.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq Q \leq 10^5$The initial values of the nodes are integers between $0$ and $10^5$.The weights of the edges are integers between $1$ and $10^5$.For all the updates $1 \leq x \leq 10^5$ and $1 \leq y \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 10 20<br>100 0 0 0 0 0 0 0 0 0<br>1 2 8<br>2 3 3<br>2 4 5<br>2 5 2<br>5 6 3<br>5 7 5<br>1 8 2<br>1 9 4<br>9 10 1<br>2 1 3 1<br>2 2 2 2<br>1 8<br>2 4 1 8<br>1 8<br>1 1<br>2 10 5 1<br>1 4<br>2 20 2 1<br>2 40 4 5<br>1 1<br>1 2<br>1 3<br>1 4<br>1 5<br>1 6<br>1 7<br>1 8<br>1 9<br>1 10 | 0<br>4<br>101<br>13<br>131<br>33<br>23<br>33<br>62<br>22<br>62<br>24<br>21<br>0 | 82435235112345678910 |
