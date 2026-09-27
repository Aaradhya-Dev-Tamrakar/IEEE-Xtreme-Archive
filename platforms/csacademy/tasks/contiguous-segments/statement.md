# Contiguous Segments

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/contiguous-segments/](https://csacademy.com/contest/archive/task/contiguous-segments/)  

---

There are $N$ non-overlapping segments on the x-axis. You need to move the segments such that they form a contiguous zone, without overlapping (with the exception of the segment ends). What is the minimum sum of distances the segments need to be moved?

### Standard input

The first line contains an integer $N$.

Each of the following $N$ lines contains $2$ integers representing the segments: $a_i$ and $b_i$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 2\ 000$ $0 \leq a_i \leq b_i \leq 10^9$, for every $1 \leq i \leq N$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 3<br>6 9<br>15 16 | 9 | Move the first segment $3$ units to the right and the last segment $6$ units to the left. The final coordinates of the segments will be:$(4, 6)$ $(6, 9)$ $(9, 10)$ |
| 4<br>2 7<br>8 20<br>35 49<br>21 21 | 17 | Move:The first segment $2$ units to the rightThe second segment $1$ unit to the rightThe third segment $14$ units to the left. |
