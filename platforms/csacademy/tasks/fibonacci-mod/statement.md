# Fibonacci Mod

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fibonacci-mod/](https://csacademy.com/contest/archive/task/fibonacci-mod/)  

---

The sequence $F_N$ of Fibonacci numbers is defined by the recurrence relation:

$F_0 = 0$ $F_1 = 1$ $F_{N+2} = F_{N+1} + F_{N}$ 

Given $M$, $A$ and $B$, find the minimum index $K$ for which $F_K \ \text{mod}\ M \equiv A$ and $F_{K+1} \ \text{mod}\ M \equiv B$.

If there is no such $K$, output $-1$.

### Standard input

The first line will contain an integer $T$, denoting the number of tests.

Each of the following $T$ lines will contain $3$ integers, $M,  A, B$.

### Standard output

For each test print the answer on a separate line.

### Constraints and notes

$1 \leq T \leq 5$ $2 \leq M < 2^{30}$ $0 \leq A, B < M$

| Input | Output |
| --- | --- |
| 4<br>10 5 8<br>10 9 7<br>3 2 2<br>666013 640764 434166 | 5<br>-1<br>5<br>39 |
