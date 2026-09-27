# Subset Trees

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subset-trees/](https://csacademy.com/contest/archive/task/subset-trees/)  

---

For a set of segments we can build an associated graph where:

Each segment is represented by a nodeTwo nodes share an edge if the corresponding segments intersect in at least one point

You are given a set of $N$ segments. Count for how many nonempty subsets of segments the associated graph is a tree.

### Standard input

The first line contains a single integer $N$.

Each of the following $N$ lines contains two integers $l_i$ and $r_i$, representing a segment that starts at $l_i$ and ends at $r_i$.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

$1 \leq N \leq 2000$ $1 \leq l_i < r_i \leq 4000$ The segments are closed, e.g. $[1, 2]$ and $[2, 3]$ intersect in $2$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 3<br>2 3<br>3 4 | 6 | The $6$ ways are to select any segment ($3$ ways)Any combination of $2$ segments($3$ ways)All $3$ segments intersect in point $3$, so chosing all of them will create a cicle of length $3$ |
| 3<br>1 4<br>2 5<br>3 6 | 6 | The $6$ ways are to select any segment ($3$ ways)Any combination of $2$ segments($3$ ways)All $3$ segments intersect in point $3$, so chosing all of them will create a cicle of length $3$ |
| 5<br>1 4<br>2 3<br>4 5<br>2 6<br>3 7 | 17 | The segment with $Y$ coordinate $I$ represents the $I$th segment in the input0123456780123456 |
