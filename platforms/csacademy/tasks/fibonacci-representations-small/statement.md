# Fibonacci Representations Small

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fibonacci-representations-small/](https://csacademy.com/contest/archive/task/fibonacci-representations-small/)  

---

Note that the task was splitted into $2$ tasks:

Fibonacci Representations SmallFibonacci Representations Big

This was done due to different time limits per subtasks. This task is worth $50$ points.

Let us define the sequence of Fibonacci numbers as:

$F_1 = 1$ $F_2 = 2$ $F_n = F_{n-1} + F_{n-2} \text{ for } n \ge 3$

The first few elements of the sequence are $1, 2, 3, 5, 8, 13, 21, ...$

For a positive integer $p$, let $X(p)$ denote the number of different ways of expressing $p$ as a sum of different Fibonacci numbers. Two ways are considered different if there is a~Fibonacci number that exists in exactly one of them.

You are given a sequence of $n$ positive integers $a_1, a_2, ..., a_n$. For a non-empty prefix $a_1, a_2, ..., a_k$, we define $p_k = F_{a_1} + F_{a_2} + ... + F_{a_k}$. Your task is to find the values $X(p_k)$ modulo $10^9+7$, for all $k=1,..., n$.

### Standard input

The first line of the standard input contains an integer $n$.

The second line contains $n$ space-separated integers $a_1, a_2, \ldots, a_n$.

### Standard output

The standard output should contain $n$ lines.

In the $k$-th line, print the value $X(p_k)$ modulo $10^9+7$.

### Constraints and notes

$1 \le n \le 100\,000$ $1 \le a_i \le 10^9$ 

### Subtasks

SubtaskAdditional constraintsNumber of points1$n, a_i \le 15$$5$2$n, a_i \le 100$$20$3$n \le 100$, $a_i$ are squares of different natural numbers$15$4$n \le 100$$10$*5$a_i$ are different even numbers (available in task Fibonacci Big)$15$*6no additional constraints (available in task Fibonacci Big)$35$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>4 1 1 5 | 2<br>2<br>1<br>2 | The number $5$ can be expressed in two ways: $F_2 + F_3$ ($2 + 3$)$F_4$ ($5$).Hence, $X(p_1) = 2$.Then we have $X(p_2) = 2$ because $p_2 = 1 + 5 = 1 + 2 + 3$.The only way to express $7$ as a sum of different Fibonacci numbers is $2 + 5$.Finally, $15$ can be expressed as $2 + 13$ and $2 + 5 + 8$ (two ways). |
