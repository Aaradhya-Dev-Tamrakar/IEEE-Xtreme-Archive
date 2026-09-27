# Aspirations

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/aspirations/](https://csacademy.com/contest/archive/task/aspirations/)  

---

Ambitious and perseverent: this is how we would describe Georgel, a first year student in Iași, and our most successful number theorist enthusiast yet. Lately, he has been dealing with greatest common divisor tasks, because it is universally agreed that they are at the heart of any number theory problem.

Number thoery crash course for non-specialists: The greatest common divisor of a non-empty set of positive integers $S$ is the biggest number $d$ such that $d$ divides all the numbers in the set $S$.

Georgel was wondering: were he to consider all the numbers between $l$ and $r$ inclusively, what would be the largest set $S$ of integers within the range $[l..r]$, such that its greatest common divisor is $d$?

### Standard input

The first line of input contains three positive integers: $l$, $r$ and $d$.

### Standard output

The first line of the output should contain a non-negative integer $L$, the length of the longest possible set $S$. The second line of the output should contain $L$ positive integers within the range $[l..r]$ in strictly increasing order, the elements of $S$.

If there is no set $S$ satisfying the constraints, output impossible.

### Constraints and notes

$1 \leq l \leq r \leq 10^4$ $1 \leq d \leq 10^4$ If there are multiple solutions, you can output any of them.

| Input | Output |
| --- | --- |
| 7 13 3 | 2<br>9 12 |
| 1 20 21 | impossible |
