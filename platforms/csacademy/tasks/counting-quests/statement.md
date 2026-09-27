# Counting Quests

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/counting-quests/](https://csacademy.com/contest/archive/task/counting-quests/)  

---

Consider the following problem:

Alex thinks of a number between $1$ and $N$. Ben then starts to ask him questions of the type:

Considering an interval $[l, r$], $1 \leq l \leq r \leq N$, is the number in the interval $[l, r]$?

There are a total of $\binom{N+1}{2}$ distinct questions. This means there are $2^{\binom{N+1}{2}}$ possible sets of questions Ben can ask. You should count for how many of these sets Ben can always uniquely identify the chosen number.

### Standard input

The first line contains two integers $N$ and $P$.

### Standard output

Print the answer modulo $P$ on the first line.

### Constraints and notes

$1 \leq N \leq 300$ $10^8 \leq P \leq 10^9+7$, $P$ is prime

| Input | Output |
| --- | --- |
| 3 1000000007 | 48 |
| 7 999997543 | 256097184 |
