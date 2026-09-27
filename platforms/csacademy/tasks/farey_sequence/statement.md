# Farey Sequence

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/farey_sequence/](https://csacademy.com/contest/archive/task/farey_sequence/)  

---

A Farey sequence of order $N$ is the sequence of completely reduced fractions between $0$ and $1$ which, when in lowest terms, have denominators less than or equal to $N$, arranged in order of increasing size.

For example the Farey sequence of order $5$ is:

$\frac{1}{5}, \frac{1}{4}, \frac{1}{3}, \frac{2}{5}, \frac{1}{2}, \frac{3}{5}, \frac{2}{3}, \frac{3}{4}, \frac{4}{5}$

We consider this array to be 1-indexed. For example the $6$th element in a Farey sequence of order $5$ is $\frac{3}{5}$.

Given to values $N$ and $K$, compute the $K$-th element in a Farey sequence of order $N$.

### Standard input

The first line contains two integer values $N$ and $K$.

### Standard output

The output should contain two integers $P$ and $Q$. The greatest common divisor of $P$ and $Q$ should be equal to $1$ and the fraction $\frac{P}{Q}$ should be the $K$-th element in a Farey sequence of order $N$.

### Constraints and notes

$1 \leq N \leq 2*10^5$For 20% of the test cases, $N \leq 1000$For 40% of the test cases, $K \leq 30\ 000$It is guaranteed $K$ is a valid index in a Farey sequence of order $N$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2 | 1 2 | Farey sequence of order $3$ is: $\frac{1}{3}$, $\frac{1}{2}$, $\frac{2}{3}$. |
| 5 4 | 2 5 | Farey sequence of order $5$ is: $\frac{1}{5}$, $\frac{1}{4}$, $\frac{1}{3}$, $\frac{2}{5}$, $\frac{1}{2}$, $\frac{3}{5}$, $\frac{2}{3}$, $\frac{3}{4}$, $\frac{4}{5}$. |
| 10 25 | 7 9 | <p></p> |
| 20 10 | 1 11 | <p></p> |
