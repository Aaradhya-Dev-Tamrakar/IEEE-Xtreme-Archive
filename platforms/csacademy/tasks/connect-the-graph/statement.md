# Connect the Graph

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/connect-the-graph/](https://csacademy.com/contest/archive/task/connect-the-graph/)  

---

You are given a graph with $N$ nodes and $M$ edges. On this graph you can perform the following type of operations:

Delete an edge and add another one (this counts as a single operation).

You should perform the minimum number of operations in order to make the graph connected.

### Standard input

The first line contains two integer values $N$ and $M$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

If there is no solution output $-1$.

Otherwise, on the first line output a single integer representing the minum number of operations needed.

On the following lines output four integers $u_1\  v_1\ u_2\ v_2$ describing the operations, where $(u_1,v_1)$ is a deleted edge and $(u_2,v_2)$ is an added edge.

### Constraints and notes

$1 \leq N \leq 10^5$$0 \leq M \leq 10^5$The nodes are numbered from $1$ to $N$.There are no multiple edges or self loops in the input graph.If the solution is not unique you can output any of them.

| Input | Output | Explanation |
| --- | --- | --- |
| 4 3<br>1 2<br>1 3<br>3 2 | 1<br>3 1 1 4 | The red edge was deleted and the green one was added.This is only one of the possible solutions.1234 |
| 4 2<br>1 2<br>3 4 | -1 | There's no way to make this graph connected.1234 |
| 6 6<br>1 3<br>3 5<br>1 5<br>2 4<br>2 6<br>4 6 | 1<br>6 2 1 2 | The red edge was deleted and the green one was added.This is only one of the possible solutions.123456 |
