# Nonempty Rectangles

**Time Limit:** `2500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/nonempty-rectangles/](https://csacademy.com/contest/archive/task/nonempty-rectangles/)  

---

You are given a set of $N$ points in the cartesian plane. You should decide if the following property holds true:

Every non-degenerate rectangle determined by two points contains at least another point inside or on its sides.

The rectangle determined by two points $(x1,y1)$ and $(x2,y2)$ has the sides parallel to the coordinate axes, the lower left corner is $(min(x1,x2), min(y1,y2))$ and the upper right corner is $(max(x1,x2), max(y1,y2))$.

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consits of several lines:

The first line contains a single integer $N$.Each of the following $N$ lines contains two integers representing the coordinates of a point in the set.

### Standard output

For each test output a single line containing one integer: $1$ if the property holds true, or $0$ otherwise.

### Constraints and notes

$1 \leq T \leq 6$$1 \leq N \leq 10^5$The coordinates of the points are integers between $1$ and $10^9$There are no two points sharing the same pair of coordinates.For 20% of the test cases the sum of the $N$ values is less than $500$For 40% of the test cases the sum of the $N$ values is less than $5000$For 60% of the test cases the sum of the $N$ values is less than $10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>3<br>1 1<br>1 2<br>2 1<br><br>6<br>1 1<br>1 2<br>1 3<br>2 3<br>3 3<br>3 2 | 1<br>1 | Both test cases meet the required property. |
| 1<br>4<br>1 1<br>1 3<br>4 3<br>4 2 | 0 | The rectangle determined by  $(1, 1)$ and $(4, 2)$ has no points inside or on it's border. |
| 1<br>4<br>2 2<br>2 4<br>1 6<br>5 4 | 0 | The rectangle determined by $(2, 4)$ and $(1, 6)$ has no points inside or on it's border. |
