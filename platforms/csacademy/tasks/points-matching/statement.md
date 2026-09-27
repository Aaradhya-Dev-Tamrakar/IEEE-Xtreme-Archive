# Points Matching

**Time Limit:** `1200 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/points-matching/](https://csacademy.com/contest/archive/task/points-matching/)  

---

You are given $2*N$ points on the $x$-axis. Each point is colored either black or red. Exactly $N$ points are red, the other $N$ are black.

You want to draw $N$ segments, each between $2$ points of different colors, such that the sum of lengths of all the segments is minimum.

### Standard input

The first line contains a single integer $N$.

The second line contains the coordinates of the red points.

The third line the coordinates of the black points.

### Standard output

Print a single line containing a permutation $\sigma$ of size $N$, where  $\sigma(i)$ represents the index of the black point connected to the $i$-th red point.

The indices of the points, both red and black, are those from the input.

If there is more than one solution, print the first lexicographical one.

### Constraints and notes

$1 \leq N \leq 10^5$The coordinates of the points are distinct integers between $1$ and $2*N$

| Input | Output |
| --- | --- |
| 6<br>5 9 1 12 11 8<br>6 3 7 2 4 10 | 2 1 4 3 6 5 |
