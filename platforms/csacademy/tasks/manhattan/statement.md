# Manhattan

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/manhattan/](https://csacademy.com/contest/archive/task/manhattan/)  

---

In the first quadrant of the cartesian plan, we define a zone, denoted by $Z(x, y, u, v)$, as a set of lattice points which belong to a rectangle defined by to diagonally opposite points, $(x, y)$ and $(u, v)$, with $x\leq u$ and $y \leq v$. In particular, a zone can contain points on a single segment when $x=u$ or $y=v$. Also, it may be formed from a single point, if $x=u$ and $y=v$.

A path between two lattice points is defined as a minimal set of horizontal and vertical segments of length $1$ which join the two points.

Given two zones $Z_1(a, b, c, d)$ and $Z_2(e, f, g, h)$ which do not intersect in any point, compute the number of distinct paths, modulo $666\ 013$, that start in $Z_1$ and end in $Z_2$.

### Standard input

The first line contains $8$ integers $a,b,c,d,e,f,g,h$, the boundaries of the two zones.

### Standard output

The output should containt a single number representing the number of distinct paths modulo $666\ 013$.

### Constraints and notes

$1\leq a,b,c,d,e,f,g,h\leq10^5$ For tests worth 10 points, $a,b,c,d,e,f,g,h \leq 30$ For tests worth 30 points, $a,b,c,d,e,f,g,h \leq 300$ For tests worth 50 points, $a,b,c,d,e,f,g,h \leq 1000$ For tests worth 50 points, the projections of the zones on $Ox$ and $Oy$ do not intersect.

| Input | Output |
| --- | --- |
| 1 1 1 2 2 2 3 2 | 7 |
| 1 1 2 2 2 3 3 4 | 53 |
| 8 4 13 7 2 3 6 8 | 44702 |
| 80 40 130 70 20 30 60 80 | 145267 |
