# Revenge

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/revenge/](https://csacademy.com/contest/archive/task/revenge/)  

---

Gigel has an undirected graph $G$ with $N$ nodes and $M$ edges with positive costs. After the mess Gigel got into at the Romanian National Olympiad in Informatics, Ninel, Gigel's little brother, stole all his edges. Gigel wants to get the edges back, but Ninel is going to make him go through some challenges.

You are given an array of undirected edges $S$ of length $L$. Every edge has a regular cost, but it also has a rejection cost $r$. Gigel has to accomplish the following mission he got from Ninel: find the minimum cost of going from node $u$ to node $v$ using a subarray of edges of $S$. Gigel is given an interval $[a, b] (a \leq b)$ which determines the indices of the edges in $S$ he is allowed to use.

Gigel is initially in node $x$ and he iterates over the edges $S_a, S_{a+1}, ... S_b$. At each step:

He chooses to use the current edge $(x, y)$ if he currently is in node $x$ to move to node $y$ (or the other way around, if he's in node $y$ to move to node $x$). The travelling cost is increased by the cost of the edge $(x, y)$.He rejects the current edge and doesn't move from his current node. The travelling cost is increased by the rejection cost of the edge.

You know the number of nodes $N$, the array of edges $S$ and $Q$ missions Gigel needs to accomplish.

The array $S$ consists of tuples of the form:

$<x, y, c, r>$, representing an edge $(x, y)$ with cost $c$ and rejection cost $r$ 

The $Q$ missions are tuples of the form:

$<u, v, a, b>$: Gigel is initially in node $u$ and has to move to node $v$, using the edges with indices between $a$ and $b$.

Find the minimum cost for each mission. If Gigel cannot reach node $v$ output $-1$.

### Standard input

The first line contains three integers $N$, $L$ and $Q$.

The next $L$ lines contain four integers $x, y, c, r$ corresponding to the edges in $S$.

The next $Q$ lines contain four integers $u, v, a, b$ corresponding to Gigel's missions.

### Standard output

Print $Q$ lines, each containing the answer for one of Gigel's missions, in the given order.

### Constraints and notes

$2 \leq N \leq 30$ $1 \leq L \leq 3 * 10^4$ $1 \leq Q \leq 3 * 10^5$ $0 \leq c, r \leq 10^4$ $1 \leq x, y, u, v \leq N$For 30 points $N \leq 7, L \leq 20000, Q \leq 20000$ For another 10 points $N \leq 10, L \leq 20000, Q \leq 60000$  For another 15 points $N \leq 22, L \leq 20000, Q \leq 60000$ 

| Input | Output |
| --- | --- |
| 5 5 3<br>1 4 4 5<br>4 1 6 1<br>2 1 2 9<br>2 5 1 0<br>1 5 2 5<br>2 2 2 4<br>5 4 5 5<br>1 5 2 5 | 10<br>-1<br>9 |
| 4 8 6<br>2 4 5 8<br>2 4 4 8<br>2 3 6 4<br>1 4 5 0<br>2 4 10 10<br>1 3 5 2<br>3 2 2 9<br>3 4 1 1<br>3 2 1 5<br>3 1 2 2<br>1 1 1 7<br>2 3 2 4<br>3 3 1 7<br>1 2 2 5 | 32<br>-1<br>41<br>14<br>36<br>27 |
