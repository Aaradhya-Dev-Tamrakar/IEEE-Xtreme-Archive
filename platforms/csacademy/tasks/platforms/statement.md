# Platforms

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/platforms/](https://csacademy.com/contest/archive/task/platforms/)  

---

There are $N$ horizontal platforms, each situated at a different height. For the sake of simplicity, we represent the platforms as horizontal segments in the cartesian plane. For each segment we know the $x$ coordinates of its endpoints. A platform can be moved left or right, the cost of such an operation being equal to the distance covered by the platform while moving.

$M$ unidimensional balls are about to fall from the sky, and for each of them we know the $x$ coordinate of the landing place on the $x$-axis. You have to move the platforms in such a way that no ball will fall strictly inside a platform. You should minimize the total cost of moving the platforms.

### Standard input

The first line contains two integers $N$ and $M$, the number of platforms and the number of balls, respectively.

Each of the next $N$ lines contains two values, the $x$ coordinates of the endpoints of a different platform. These two values are in increasing order.

Finally, the last line of the input contains $M$ values representing the landing coordinates of the balls on the $x$-axis.

### Standard output

The output should contain a single number representing the minimum cost of moving the platforms.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq M \leq 10^5$The endpoints of the segments are integers between $-10^8$ and $10^8$The landing coordinates of the balls are integers between $-10^8$ and $10^8$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 5<br>5 9<br>2 7<br>3 5<br>1 10 8 4 5 | 12 | We move the first platform $5$ units to the right, the second platform $6$ units to the left, and the third platform $1$ unit to the left. |
