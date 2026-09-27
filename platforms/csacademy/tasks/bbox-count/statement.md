# BBox Count

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bbox-count/](https://csacademy.com/contest/archive/task/bbox-count/)  

---

You are given a set $S$ of $N$ points. Consider the bounding box of each possible subset of $S$. How many distinct non-degenerate bounding boxes are there?

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers representing the coordinates of a point in $S$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$2 \leq N \leq 2500$ The coordinates of the points are integers between $1$ and $2500$ The are no two points at the same coordinates

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 2<br>3 1<br>4 4<br>5 1 | 8 | The $8$ bounding boxes have have the following lower left and upper right corners:$(1, 1) ,(3, 2)$ $(1, 1) ,(4, 4)$ $(1, 1) ,(5, 2)$ $(1, 1) ,(5, 4)$ $(1, 2) ,(4, 4)$ $(3, 1) ,(4, 4)$ $(3, 1) ,(5, 4)$ $(4, 1) ,(5, 4)$ |
| 7<br>1 1<br>1 4<br>3 4<br>2 5<br>5 2<br>3 3<br>6 3 | 32 |  |
