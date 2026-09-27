# Black White Tree

**Time Limit:** `3000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/black-white-tree/](https://csacademy.com/contest/archive/task/black-white-tree/)  

---

Consider a tree with $N$ nodes. Each node has an intial color, either white or black. You should perform $M$ operations of two types:

Toggle the color of a certain node $v$.For a given node $v$, find the sum of distances to all the nodes $u$, where $v$ and $u$ have the same color.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $N$ integers. The $i^{th}$ integer is $0$ if node $i$ is white, $1$ if the node is black.

Each of the next $N-1$ lines contains two integers representing two nodes that share an edge.

Each of the next $M$ lines contains two integers describing a query. The first value is $1$ if you're dealing with a query of type $1$, and $2$ if it's a type $2$ query. The second value is node $v$.

### Standard output

For each query of type $2$, print the answer on a distinct line.

### Constraints and notes

$1 \leq N, M \leq 5*10^4$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 5<br>0 0 1 1<br>1 2<br>2 3<br>3 4<br>2 1<br>2 4<br>1 2<br>1 3<br>2 1 | 1<br>1<br>2 | 1234$1^{st}$ query: node $1$ is white and the other white node is $2$, so the answer is $1$, since they are adjacent. $2^{nd}$ query: node $4$ is blank and the other black node is $3$, so the answer is $1$. $3^{rd}$ query: toggle the color of node $2$$4^{th}$ query: toggle the color of node $3$The graph looks like:1234$5^{th}$ query:  node $1$ is white and the other white node is $3$, so the answer is $2$. |
| 5 5<br>0 1 0 1 1<br>1 2<br>1 3<br>5 3<br>4 3<br>2 3<br>1 3<br>2 1<br>1 2<br>2 4 | 1<br>0<br>3 | 12345 |
