# Strange Distance

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/strange-distance/](https://csacademy.com/contest/archive/task/strange-distance/)  

---

You are given $N$ points in the cartesian plane. We define the distance between two points $(x1,y1)$ and $(x2,y2)$ as $min(|x1-x2|,|y1-y2|)$. Compute the value of the $K$-th distance between every pair of points.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the following $N$ lines contains two integer values representing the coordinates of the points.

### Standard output

The output should consist of a single integer value representing the value of the $K$-th distance.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq K \leq N*(N-1)/2$The coordinates of the points are integers between $1$ and $10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>1 1<br>2 2<br>4 4 | 2 | $dist(1, 2)=1$; $dist(1, 3)=3$; $dist(2, 3)=2$Sorted distances: $\{1, 2, 3\}$ |
| 4 5<br>1 5<br>4 1<br>5 5<br>3 7 | 2 | $dist(1, 2)=3$; $dist(1, 3)=0$; $dist(1, 4)=2$; $dist(2, 3)=1$; $dist(2, 4)=1$; $dist(3, 4)=2$Sorted distances: $\{0, 1, 1, 2, 2, 3\}$ |
| 4 4<br>1 7<br>5 1<br>2 6<br>2 3 | 2 | $dist(1, 2)=4$; $dist(1, 3)=1$; $dist(1, 4)=1$; $dist(2, 3)=3$; $dist(2, 4)=2$; $dist(3, 4)=0$Sorted distances: $\{0, 1, 1, 2, 3, 4\}$ |
