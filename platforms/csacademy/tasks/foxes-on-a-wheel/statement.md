# Foxes on a Wheel

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/foxes-on-a-wheel/](https://csacademy.com/contest/archive/task/foxes-on-a-wheel/)  

---

Consider a graph with $N + 1$ nodes, numbered from $0$ to $N$. Node $0$ is connected to all the other $N$ nodes. Every node $i$ ($1 \leq i < N$) is connected to node $i + 1$, and node $N$ is connected to node $1$.

Here is an example for $N = 6$:

0123456

In this graph, in $K$ of the nodes there is a fox, and other $K$ nodes have hiding places. It is guaranteed there is no fox or hiding place in node $0$, and there isn't any node that contains both a fox and a hiding place.

You should assign each fox to a distinct hiding place, such that the sum of distances the foxes need to travel to their designated hiding places is minimum.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $K$ integers representing the nodes with foxes.

The third line contains $K$ integers representing the nodes with hiding places.

### Standard output

Print the minimum sum of distances on the first line.

### Constraints and notes

$3 \leq N \leq 10^5$ $1 \leq K \leq \lfloor \frac{N}{2} \rfloor$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 2<br>1 3<br>2 4 | 2 | All possible assignments are minimal. |
| 4 1<br>1<br>3 | 2 | The minimum distance from $1$ and $3$ is $2$. |
| 4 1<br>2<br>3 | 1 | The minimum distance from $2$ and $3$ is $1$. |
| 14 4<br>5 3 1 6<br>8 7 2 13 | 6 |  |
