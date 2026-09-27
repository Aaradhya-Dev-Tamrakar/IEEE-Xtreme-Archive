# Manhattan Distances

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/manhattan-distances/](https://csacademy.com/contest/archive/task/manhattan-distances/)  

---

Alex drew $3$ points at integer coordinates, but then he lost the paper. Now he only remembers the Manhattan distance between every pair of points. Help him find a possible set of $3$ points that respect these distances.

### Standard input

The first line contains a single integer $T$ representing the number of test cases that follow.

Each of the next $T$ lines contains $3$ integer, representing the Manhattan distances between the points. Note that these numbers are not given in any particular order.

### Standard output

For each test print the answer on a single line.

If there is no solution, output $-1$. Otherwise, print $6$ integers $x_1, y_1, x_2, y_2, x_3, y_3$ representing the coordinates of the $3$ points.

### Constraints and notes

$1 \leq T \leq 10\,000$ The distances are integers between $1$ and $10^8$ You can print any solution where the coordinate of the points are integers between $-10^8$ and $10^8$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>3 5 4<br>30 1 20<br>5 10 12 | 12 11 10 10 11 14<br>-1<br>-1 | For the first test case we have the points $(12, 11)$, $(10, 10)$ and $(11, 14)$. The distances between the first and the second is $3$, the first and the third is $4$, and between the last two is $5$ |
