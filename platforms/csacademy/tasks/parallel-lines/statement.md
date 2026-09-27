# Parallel Lines

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/parallel-lines/](https://csacademy.com/contest/archive/task/parallel-lines/)  

---

$N$ points lie on a plane. Find the smallest $K$ such that it's possible to cover all the given points with a set of $K$ parallel lines, given that $K$ doesn't exceed $400$.

### Standard input

The first line contains the number of test cases $T$. Then, $T$ test cases follow.

For each test case, the first line contains an integer $N$ representing the number of points.

Each of the next $N$ lines contains two integers $X_i$ and $Y_i$ representing the coordinates of the $i$-th point.

### Standard output

For each test case, print the answer on a separate line.

### Constraints and notes

$1 \le T \le 10$ $1 \le N \le 30 000$ $-10^9 \le X_i, Y_i \le 10^9$  All points within one test case are distinct.The sum of values of $N$ over all test cases doesn't exceed $30000$.For each test case, the answer doesn't exceed $400$.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>5<br>2 2<br>1 2<br>2 1<br>3 2<br>2 3<br>7<br>1 2<br>1 3<br>1 5<br>2 3<br>2 4<br>3 4<br>4 5 | 3<br>3 | 012345601234-2-1012345671234567 |
