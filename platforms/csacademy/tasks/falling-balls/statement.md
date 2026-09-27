# Falling Balls

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/falling-balls/](https://csacademy.com/contest/archive/task/falling-balls/)  

---

Consider $N$ horizontal platforms, and for the sake of simplicity we represent them as horizontal segments in the cartesian plane. For each segment we know three values $x_1$, $x_2$ and $y$, where the endpoints of the segment are $(x_1, y)$ and $(x_2, y)$, respectively.

$M$ balls, represented as points, are about to fall from the sky, and for each of them we know their intial $x$ coordinate. The $y$ coordinate is irrelevant, because we consider the balls to fall from above all the segments.

A ball falls vertically, but when it hits a platform, it rolls towards the closest end, and then is continues its fall. If both endpoints of the platform are equally far from the landing place, the ball will always roll to the left.

For every ball you should determine the place on the x-axis where it's going to land.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains three integers $x_1$, $x_2$ and $y$.

The next line contains $M$ integers representing the $x$ coordinates of the balls.

### Standard output

Print $M$ lines, each containing a single integer representing the landing place on the x-axis for each of the balls.

### Constraints and notes

$1 \le N \le 10^5$ $1 \le M \le 10^5$ All the coordinates will be integers between $1$ and $10^5$

| Input | Output |
| --- | --- |
| 4 7<br>15 15 5<br>2 12 2<br>6 8 5<br>3 6 3<br>6<br>7<br>8<br>9<br>5<br>15<br>14 | 2<br>2<br>12<br>12<br>2<br>15<br>14 |
