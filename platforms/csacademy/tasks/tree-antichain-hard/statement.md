# Tree Antichain (Hard)

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tree-antichain-hard/](https://csacademy.com/contest/archive/task/tree-antichain-hard/)  

---

You are given a tree (an undirected connected graph without cycles) with $N$ vertices numbered from 1 to $N$. Find the lexicographically smallest permutation of its vertices $A_1, A_2, \ldots, A_N$ such that for every $i$, vertices $A_i$ and $A_{i+1}$ are not connected by an edge.

### Standard input

The first line contains a single integer $T$ representing the number of test cases. Then, $T$ test cases follow.

For each test case, the first line contains a single integer $N$ representing the number of vertices in the tree.

Each of the next $N-1$ lines contains two integers $X_i$ and $Y_i$ representing the endpoints of the $i$-th edge.

### Standard output

If there is no valid permutation, print a single integer -1. Otherwise, print $N$ integers $A_1, A_2, \ldots, A_N$.

### Constraints and notes

$1 \le T \le 10^4$ $2 \le N \le 10^5$ $1 \le X_i, Y_i \le N$ The sum of values of $N$ over all test cases doesn't exceed $10^5$.Sequence $A_1, A_2, \ldots, A_N$ is lexicographically smaller than sequence $B_1, B_2, \ldots, B_N$ if $A_1 = B_1$, $A_2 = B_2$, ..., $A_{k-1} = B_{k-1}$ and $A_k < B_k$ for some $k$ between $1$ and $N$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>4<br>1 2<br>2 3<br>3 4<br>4<br>1 2<br>1 3<br>1 4<br>7<br>1 2<br>1 3<br>2 4<br>2 5<br>3 6<br>3 7 | 2 4 1 3<br>-1<br>1 4 3 2 6 5 7 | In the first test case, there are two valid permutations, (2, 4, 1, 3) and (3, 1, 4, 2), and the former is lexicographically smaller.In the second test case, vertex 1 can't be placed next to any other vertex in the permutation.First 2 testcases1234 1234Third testcase1234567 |
