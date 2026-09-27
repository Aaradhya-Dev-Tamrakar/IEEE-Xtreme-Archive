# Rectangle Fit

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rectangle-fit/](https://csacademy.com/contest/archive/task/rectangle-fit/)  

---

You are given $N$ points and an integer $A$. Your task is to determine a rectangle having the area at most $A$ and one corner in $(0, 0)$ that contains the maximum number of given points inside it.

Note that points are considered inside the rectangle even if they are on the edge of the rectangle.

### Standard input

The first line contains $2$ integers $N$ and $A$.

Each of the next $N$ lines contain $2$ integers $x$ and $y$ describing a point.

### Standard output

The first line should contain the maximum number of points that can be contained inside a rectangle.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq x, y \leq 10^6$ $1 \leq A \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 10<br>1 2<br>3 1<br>2 3<br>2 4<br>1 5 | 4 | 0123456012345612345 |
| 2 1<br>1 3<br>3 1 | 0 | 00.511.522.533.540123412 |
| 7 16<br>1 2<br>1 2<br>1 6<br>2 4<br>3 1<br>6 1<br>6 5 | 4 | Note that there are $2$ points at coordinate $(1, 2)$ Note that the area of the rectangle is at most $16$ 01234567012345671, 234567 |
