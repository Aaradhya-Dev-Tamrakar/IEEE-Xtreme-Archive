# Triangle Count

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/triangle-count/](https://csacademy.com/contest/archive/task/triangle-count/)  

---

You have $N$ sticks for which you know their length. Count the number of ways you can choose $3$ sticks that can be used to build a non-degenerate triangle.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the lengths of the sticks.

### Standard output

Print a single number representing the number of ways you can choose the sticks.

### Constraints and notes

$3 \leq N \leq 100$ The lengths of the sticks are integers between $1$ and $10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 3 9 10 | 2 | The 2 triangles are formed using the lenghts $\{2, 9, 10\}$ and $\{3, 9, 10\}$Using $\{1, 2, 3\}$ or $\{1, 9, 10\}$ formes a degenerate triangle which is invalid. |
| 4<br>2 2 2 3 | 4 | $\{2, 2, 3\}$, first and second stick of length $2$$\{2, 2, 3\}$, first and third stick of length $2$$\{2, 2, 3\}$, second and third stick of length $2$and using all the sticks of length $2$, $\{2, 2, 2\}$ |
| 10<br>1 8 7 4 4 1 2 4 1 1 | 27 |  |
