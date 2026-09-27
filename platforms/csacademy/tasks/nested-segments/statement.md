# Nested Segments

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/nested-segments/](https://csacademy.com/contest/archive/task/nested-segments/)  

---

You are given $N$ segments. For each segment $i$ you know two integers $l_i$ and $r_i$, representing the left and the right ends of the segment.

A segment $i$ is nested inside segment $j$ if $l_j < l_i$ and $r_i <r_j$. Find the number of segments that are nested inside at least one other segment.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains two integers $l_i$ and $r_i$.

### Standard output

Print the number of nested segments on the first line.

### Constraints and notes

$2 \leq N \leq 100$ $0 \leq l_i \leq r_i \leq 100$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>0 5<br>2 6<br>3 4<br>0 7 | 2 | Segments $(3, 4)$ and $(2, 6)$ are nested inside $(0, 7)$. |
| 4<br>1 5<br>0 5<br>0 5<br>1 6 | 0 |  |
