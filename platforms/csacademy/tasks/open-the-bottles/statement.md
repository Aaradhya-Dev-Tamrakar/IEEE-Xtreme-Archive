# Open the Bottles

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/open-the-bottles/](https://csacademy.com/contest/archive/task/open-the-bottles/)  

---

You have $3$ wine bottles and $3$ bottle openers. You know the time necessary to open each bottle using each opener. Find the minimum total time for opening all $3$ bottles.

### Standard input

The input consists of $3$ lines, each containing $3$ integers. The $j$th number on the $i$th line is the time necessary to open bottle $i$ using the opener $j$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq time \leq 100$ for any pair of bottle and bottle opener. All numbers are integers.You cannot open more bottle simultaneously

| Input | Output | Explanation |
| --- | --- | --- |
| 1 2 2<br>2 1 2<br>2 2 1 | 3 | Use bottle opener $i$ for bottle $i$ |
| 3 2 7<br>1 5 8<br>3 3 10 | 6 | Use opener $2$ for bottle $1$, opener $1$ for bottle $2$ and opener $1$ or $2$ for bottle $3$ |
| 5 4 3<br>7 6 11<br>7 9 2 | 11 | Use bottle openers $3$, $2$ and $3$ |
