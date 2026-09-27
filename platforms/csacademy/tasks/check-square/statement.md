# Check Square

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/check-square/](https://csacademy.com/contest/archive/task/check-square/)  

---

You are given $4$ points, check if they can be the vertices of a square. The square shouldn't necessarily have the sides parallel to the coordinate axes.

### Standard input

The first line contains a single integer $T$ representing the number of test that follow.

Each test consists of $4$ lines. Each line contains two integers representing the coordinates of a point.

### Standard output

Print the answer for each test on a distinct line: $1$ if the four points are the vertices of a square, $0$ if not.

### Constraints and notes

$1 \leq T \leq 100$ The coordinates of the points are integers between $1$ and $100$.The $4$ points in a test are distinct.

| Input | Output | Explanation |
| --- | --- | --- |
| 1<br>2 2<br>3 3<br>3 1<br>4 2 | 1 | 012345601234 |
| 2<br>3 4<br>3 2<br>1 1<br>1 3<br>3 1<br>1 4<br>6 3<br>4 6 | 0<br>1 | 012345601234560123456701234567 |
| 3<br>1 1<br>1 2<br>1 3<br>2 2<br>1 3<br>3 1<br>1 1<br>2 2<br>3 1<br>2 4<br>1 2<br>4 3 | 0<br>0<br>1 | 0.511.522.5311.522.533.5  0.511.522.533.50.511.522.533.5    -10123456-10123456 |
