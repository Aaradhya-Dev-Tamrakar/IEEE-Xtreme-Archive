# Towns

**Time Limit:** `600 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/towns/](https://csacademy.com/contest/archive/task/towns/)  

---

In a faraway land there are $N + 1$ towns. They were built in a straight line, in order $0, 1, \ldots, N$ such that there is a road between any two adjacent towns.

Each road has a length and a certain speed limit, measured in meters per second.

You want to travel from $0$ to $N$ in minimum time. For this, at most $X$ times, you can take and arbitrary road an increase its speed limit by $1$ meter per second. What is the minimum time you can achieve?

### Standard input

The first line contains two integers $N$ and $X$.

The second line contains $N$ integers, the $i^{\text{th}} \ (1 \leq i \leq N)$ one contains the length of the road between towns $i-1$ and $i$.

The third line contains $N$ integers, the $i^{\text{th}} \ (1 \leq i \leq N)$ one contains the speed limit of the road connecting $i-1$ and $i$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 5 * 10^4$ $1 \leq X \leq 10^7$ The length of a road is an integer in $[1, 10^4]$ The initial speed limit of a road is an integer in $[1, 10^4]$ Your answer will be considered correct if its absolute or relative error does not exceed $10^{-6}$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 5<br>5 3 7<br>2 1 4 | 3.650000000000 | The minimum time is $3.65$, obtained by changing the speed limits to $[4, 3, 5]$: $\frac{5}{4} + \frac{3}{3} + \frac{7}{5} = 3.65$ |
| 5 6<br>2 5 3 2 4<br>5 1 2 1 3 | 4.650000000000 | The changed speed limits are $[5, 4, 3, 3, 3]$; the answer is $\frac{2}{5} + \frac{5}{4} + \frac{3}{3} + \frac{2}{3} + \frac{4}{3} = 4.65$. |
| 4 6<br>3 8 10 5<br>4 3 7 3 | 4.321428571429 | The final speed limits will be $[4, 7, 7, 5]$ and the result is $\frac{3}{4} + \frac{8}{7} + \frac{10}{7} + \frac{5}{5} = 4.32142857$. |
