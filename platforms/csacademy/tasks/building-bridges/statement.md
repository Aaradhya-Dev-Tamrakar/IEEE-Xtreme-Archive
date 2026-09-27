# Building Bridges

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/building-bridges/](https://csacademy.com/contest/archive/task/building-bridges/)  

---

A wide river has $n$ pillars of possibly different heights standing out of the water. They are arranged in a straight line from one bank to the other. We would like to build a bridge that uses the pillars as support. To achieve this we will select a subset of pillars and connect their tops into sections of a bridge. The subset has to include the first and the last pillar.

The cost of building a bridge section between pillars $i$ and $j$ is $(h_i - h_j)^2$ as we want to avoid uneven sections, where $h_i$ is the height of the pillar $i$. Additionally, we will also have to remove all the pillars that are not part of the bridge, because they obstruct the river traffic. The cost of removing the $i$-th pillar is equal to $w_i$. This cost can even be negative—some interested parties are willing to pay you to get rid of certain pillars. All the heights $h_i$ and costs $w_i$ are integers.

What is the minimum possible cost of building the bridge that connects the first and last pillar?

### Input

The first line contains the number of pillars, $n$. The second line contains pillar heights $h_i$ in the order, separated by a space. The third line contains $w_i$ in the same order, the costs of removing pillars.

### Output

Output the minimum cost for building the bridge. Note that it can be negative.

### Constraints

$2 \leq n \leq 10^5$ $0 \leq h_i \leq 10^6$ $0 \leq |w_i| \leq 10^6$ 

### Subtask 1 (30 points)

$n \leq 1\,000$ 

### Subtask 2 (30 points)

optimal solution includes at most $2$ additional pillars (besides the first and last)

### Subtask 3 (40 points)

no additional constraints

| Input | Output |
| --- | --- |
| 6<br>3 8 7 1 6 6<br>0 -1 9 1 2 0 | 17 |
