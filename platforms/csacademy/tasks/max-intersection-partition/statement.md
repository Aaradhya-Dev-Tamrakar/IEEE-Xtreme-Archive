# Max Intersection Partition

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/max-intersection-partition/](https://csacademy.com/contest/archive/task/max-intersection-partition/)  

---

You are given $N$ segments on the x-axis. You should partition them in at most $K$ sets. For each set we define its cost as the length of the intersection of the segments in the set. Find the partition that maximizes the sum of the costs of all the sets.

### Standard input

The first line contains the two integers $N$ and $K$.

Each of the following $N$ lines contains two integers $x_1$ and $x_2$ representing the end points of a segment.

### Standard output

Output a single number representing the maximum sum of costs you can get.

### Constraints and notes

$1 \leq N \leq 6000$$1 \leq K \leq N$$1 \leq x_{i1} < x_{i2} \leq 10^6$ for every $1 \leq i \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3<br>5 10<br>4 11<br>6 9<br>10 30<br>20 40 | 43 | One way to achieve the max cost is to group the segments $\{\{1, 2, 3\}, \{4\}, \{5\}\}$. $[5, 10] \cap [4, 11] \cap [6, 9] = [6, 9]$ having the cost $3$, $[10, 30]$ with cost $20$ and $[20, 40]$ with cost $20$ obtaining the cost $43$. |
| 5 3<br>5 11<br>16 22<br>14 20<br>10 20<br>6 10 | 18 | One way to achieve the max cost is to group the segments $\{\{1, 5\}, \{2, 3\}, \{4\}\}$.$[5, 11] \cap [6, 10] = [6, 10]]$ having the cost $4$, $[16, 22] \cap [14, 20] = [16, 20]$ with cost $4$ and $[10, 20]$ with cost $10$ obtaining the cost $4 + 4 + 10 = 18$. |
| 7 3<br>1 9<br>2 9<br>2 10<br>5 15<br>3 14<br>14 18<br>16 20 | 21 | One way to achieve the max cost is to group the segments $\{\{1, 2, 3, 6, 7\}, \{4\}, \{5\}\}$. $[1, 9] \cap [2, 9] \cap [2, 10] \cap [14, 18] \cap [16, 20] = \emptyset$ having the cost $0$, $[5, 15]$ with cost $10$ and $[3, 14]$ with cost $11$ obtaining the cost $0 + 10 + 11 = 21$. |
