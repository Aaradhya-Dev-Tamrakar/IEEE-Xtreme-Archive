# Parallel Rectangles

**Time Limit:** `2500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/parallel-rectangles/](https://csacademy.com/contest/archive/task/parallel-rectangles/)  

---

You are given $N$ points at integers coordinates. Find the numbers of ways of choosing $4$ points that represent the vertices of a rectangle with sides parallel to the coordinate axis.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers representing the coordinates of a point.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ The coordinates of the points are integers between $1$ and $10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 10<br>1 1<br>1 3<br>1 4<br>3 1<br>3 2<br>2 3<br>3 3<br>2 2<br>4 4<br>4 3 | 3 | 0123456012345 |
| 24<br>1 5<br>1 4<br>2 5<br>2 4<br>2 3<br>3 4<br>3 3<br>4 4<br>4 3<br>5 4<br>5 3<br>6 5<br>6 4<br>6 3<br>7 5<br>7 4<br>2 7<br>2 8<br>3 7<br>3 8<br>5 7<br>5 8<br>6 7<br>6 8 | 49 | 01234567823456789 |
