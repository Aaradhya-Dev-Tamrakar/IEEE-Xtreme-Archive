# Rectangle Partition

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rectangle-partition/](https://csacademy.com/contest/archive/task/rectangle-partition/)  

---

You have a rectangle of height $H$ and width $W$, the lower left corner is considered to be at coordinates $(0, 0)$. You draw $N$ horizontal lines and $M$ vertical lines that divide the rectangle in $(N+1) \times (M+1)$ smaller rectangles. How many of those are squares?

### Standard input

The first line contains $4$ integers $H$, $W$, $N$ and $M$.

The second line contains $N$ integers representing the y-coordinates of the horizontal lines.

The third line contains $M$ integers representing the x-coordinates of the vertical lines.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N < H \leq10^5$ $1 \leq M < W \leq10^5$ All the lines will be distinct

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4 1 1<br>1<br>2 | 0 | Please note that we're interested only in the small rectangles. We do not take into consideration the big square $(0, 0),\ (4, 4)$.-1012345-1012345 |
| 5 5 2 2<br>1 4<br>2 3 | 2 | -10123456-10123456 |
| 5 10 2 4<br>2 4<br>1 4 9 7 | 4 | 0246810-10123456 |
