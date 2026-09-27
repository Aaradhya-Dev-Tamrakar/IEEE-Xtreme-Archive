# Num Cube Sets

**Time Limit:** `2000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/num-cube-sets/](https://csacademy.com/contest/archive/task/num-cube-sets/)  

---

You are given two sets of numbers $A$ and $B$. You should find a subset $A'$ of $A$ and another subset $B'$ of $B$ such that:

$A'$ and $B'$ are non-empty.For each element $a$ in $A'$ and each element $b$ in $B'$, $a * b$ is a perfect cube.$|A'|^2+|B'|^2$ is maximized (we denote by $|A'|$ the number of elements of $A'$, the same goes for $|B'|$).

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consits of three lines:

The first line contains two integer $N$ and $M$, representing the size of $A$ and the size of $B$, respectively.The second line contains the $N$ values of $A$.The third line contains the $M$ values of $B$.

### Standard output

Output $T$ lines, each containing the answer for one test. If there is no solution, the line should contain $-1$, otherwise output the maximum possible value of $|A'|^2+|B'|^2$.

### Constraints and notes

$1 \leq T \leq 10^4$$1 \leq N, M \leq 5*10^5$The sum of $N+M$ for all the $T$ tests is between $1$ and $5*10^5$.The elements of $A$ and $B$ are integers between $1$ and $10^6$.

| Input | Output |
| --- | --- |
| 3<br>3 2<br>2 2 8<br>16 2<br>3 2<br>2 16 5<br>4 4<br>6 3<br>12 18 18 45 324 96<br>12 144 486 | -1<br>8<br>13 |
