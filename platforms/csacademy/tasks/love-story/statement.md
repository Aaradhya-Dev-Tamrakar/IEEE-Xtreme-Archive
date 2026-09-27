# Love Story

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/love-story/](https://csacademy.com/contest/archive/task/love-story/)  

---

Romeo and Juliet find themselves on the x-axis. Romeo is in the origin (coordinate 0), while Juliet is at coordinate N. The segment between them is divided in $M$ zones, for each zone you know its length (the sum of lengths is equal to N). They start walking towards each other with the same speed, in which zone will they meet?

### Standard input

The first line contains $2$ integers $N$ and $M$.

The next line contains $M$ integeres representing the lengths of the zones.

### Standard output

The first line should contain the index of the zone of their meeting place. If they meet between $2$ zones print $-1$.

### Constraints and notes

$1\leq M \leq 100$ $1 \leq N \leq 10\,000$ the length of each zone is a number between $1$ and $1000$.It's guaranteed that the sum of zones length is $N$.

| Input | Output | Explanation |
| --- | --- | --- |
| 13 3<br>3 2 8 | 3 | The $3$ zones are between$(0, 3)$ $(3, 5)$ $(5, 13)$They meet at point $6.5$ which is in the $3rd$ zone. |
| 10 3<br>3 2 5 | -1 | The $3$ zones are between$(0, 3)$ $(3, 5)$ $(5, 10)$They meet at point $5$ which is between zones $2$ and $3$. |
| 5 5<br>1 1 1 1 1 | 3 | The $3$ zones are between$(0, 1)$ $(1, 2)$ $(2, 3)$ $(3, 4)$ $(4, 5)$ They meet at point $2.5$ which is in the $3rd$ zone. |
