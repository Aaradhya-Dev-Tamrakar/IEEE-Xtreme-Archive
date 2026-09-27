# Hallway

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/hallway/](https://csacademy.com/contest/archive/task/hallway/)  

---

Let's consider a corridor represented as a rectangle of size $N * M$ with the lower left corner in the origin of the cartesian system. In this corridor there are some obstacles of negligible thickness. You are asked to find the largest radius of a circle that can pass through the corridor from left to right in a way that will not intersect the obstacles.

### Standard input

The first line contains two integer values $N$ and $M$.

The second line contains a single integer $K$ representing the number of obstacles.

Each of the next $K$ lines contains two integer values representing the coordinates of an obstacle.

### Standard output

The output should contain a single real value representing the maximum radius of a circle that can pass through the corridor.

### Constraints and notes

$1 \leq N, M \leq 10^6$$1 \leq K \leq 5 000$For 50% of the test cases, $K \leq 400$For 75% of the test cases, $K \leq 1000$Your result should differ from the official one by less than $10^{-6}$ with absolute or relative precision.

| Input | Output |
| --- | --- |
| 5 5 1<br>1 3 | 1.50000000 |
| 10 5 2<br>1 1<br>2 3 | 1.11803399 |
| 10 10 3<br>3 5<br>9 7<br>9 9 | 2.50000000 |
| 10 10 5<br>5 9<br>7 9<br>9 2<br>1 9<br>1 3 | 3.00000000 |
