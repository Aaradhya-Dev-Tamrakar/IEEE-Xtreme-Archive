# An Unstable Graph

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/an-unstable-graph/](https://csacademy.com/contest/archive/task/an-unstable-graph/)  

---

You are given simple directed graph with $N$ vertices and $M$ edges. The graph is highly unstable! Every second, the $i^{th}$ edge  exists with probability $P_i$.

You start in vertex $1$ and want to reach vertex $N$. Every second you can move along one of the edges that exists during that second. Because the graph is unstable, you are not allowed to stand in one place. So if none of the arcs going from the vertex you are currently in exist during the current second, you die!

You absolutely don't want to die. What is the probability of you successfully reaching vertex number $N$ given that you move optimally? It is not necessary to minimize the number of vertices visited, and you are allowed to visit any vertex any number of times.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $M$ lines contains three integers $A_i$, $B_i$ and $P_i$, describing an edge going from vertex $A_i$ to vertex $B_i$ that exists every second with probability $P_i$ percent.

### Standard output

Print the probability of successfully reaching vertex number $N$.

### Constraints and notes

$2 \le N \le 50$ $0 \le M \le N (N - 1)$ Your result will be checked with an absolute error of ​​$10^{-6}$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>1 2 50<br>2 3 50 | 0.250000000000000 | You need to win the coin flip twice in order for edge 1->2 to exist during the 1st second and edge 2->3 to exist during the 2nd second. |
| 3 3<br>1 2 100<br>2 1 100<br>2 3 1 | 0.999999999999999 | Edge 2->3 only exists 1% of the times, but since you can always safely retreat back to vertex 1 if it doesn't, you never die and will eventually reach 3. |
| 4 3<br>1 2 100<br>2 3 100<br>3 1 100 | 0.000000000000000 | You never die here either, but there's still no way to reach 4. |
| 3 3<br>1 2 50<br>2 1 100<br>2 3 50 | 0.333333333333333 |  |
