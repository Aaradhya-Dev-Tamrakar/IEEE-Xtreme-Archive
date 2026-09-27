# Disk Mechanism

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/disk-mechanism/](https://csacademy.com/contest/archive/task/disk-mechanism/)  

---

You have $N$ points on an axis. In each point you want to center a disk of integer radius. Every two disks centered in consecutive points need to be tangent. For each disk you have some additional restrictions concerning its minimum and maximum possible radius. Count the number of possible solutions.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers in increasing order representing the coordinates of the points.

Each of the next $N$ lines contains $2$ integers: the minimum and the maximum radius allowed for a disk.

### Standard output

Print a single integer representing the number of possible solutions.

### Constraints and notes

$2 \leq N \leq 10^5$ The point coordinates are given in increasing order and they are integers between $0$ and $10^9$ The minimum and the maximum dimensions for the radius of a disk are integers between $1$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>0 4 7 10 <br>1 5<br>1 5<br>1 3<br>1 3 | 2 | 2 2 1 23 1 2 1 |
| 4<br>0 4 7 10 <br>2 5<br>1 5<br>1 3<br>2 3 | 1 | 2 2 1 2 |
| 3<br>4 9 14 <br>1 10<br>3 10<br>1 5 | 2 | 2 3 21 4 1 |
| 3<br>1 4 9 <br>2 2<br>1 3<br>1 3 | 0 |  |
