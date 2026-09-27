# Independent Rectangles

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/independent-rectangles/](https://csacademy.com/contest/archive/task/independent-rectangles/)  

---

You are given $N$ rectangles and for each rectangle $i$ you know its width $w_i$ and its height $h_i$.

We call a rectangle $i$ to be independent if there is no other rectangle $j$ such that $w_i < w_j$ and $h_i < h_j$.

Count the number of independent rectangles.

### Standard input

The first line contains a single integer $N$.

Each of the following $N$ lines contains two values $w$ and $h$ representing the width and the height of a rectangle.

### Standard output

Output a single number representing the number of independent rectangles.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq w_i, h_i \leq 10^6$

| Input | Output |
| --- | --- |
| 5<br>1 5<br>2 2<br>2 3<br>2 5<br>3 4 | 3 |
| 6<br>3 3<br>3 4<br>4 3<br>4 4<br>1 7<br>5 8 | 1 |
