# Dominant Point

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dominant-point/](https://csacademy.com/contest/archive/task/dominant-point/)  

---

You are given $N$ points in the cartesian plane. For each point $i$ you know its coordinates $x_i$ and $y_i$. We say that a point $i$ dominates a point $j$ if $x_i > x_j$ and $y_i > y_j$. Find out if there is a point that dominates all the others.

### Standard input

The first line contains a single integer $N$.

Each of the following $N$ lines contains two integers $x$ and $y$ representing the coordinates of a point.

### Standard output

Output $-1$ if there is no dominant point. Otherwise print the index of the dominant point.

### Constraints and notes

$2 \leq N \leq 1000$The coordinates of the points are integers between $1$ and $10^5$.No two points have the same $x$ or $y$.The points are considered to be 1-indexed.

| Input | Output |
| --- | --- |
| 7<br>42 7<br>16 20<br>41 24<br>1 12<br>48 40<br>32 35<br>47 29 | 5 |
| 7<br>20 30<br>71 78<br>31 8<br>67 16<br>35 79<br>79 19<br>30 48 | -1 |
