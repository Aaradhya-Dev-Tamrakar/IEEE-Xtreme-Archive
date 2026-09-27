# Balanced String

**Time Limit:** `500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/balanced-string/](https://csacademy.com/contest/archive/task/balanced-string/)  

---

We define a circular substring of a string $S$ to be a substring that can also cross over the end of the string and continue from the beginning. For example, the string EFAB is considered a circular substring of length $4$ of the string ABCDEF.

A string $S$ is considered to be a balanced string if the following conditions hold true:

Each character in the string is either A or B.For any two circular substrings of $S$ of the same length $l$ ( $1 \leq l \leq N$ ) the number of As in the first substring and the number of As in the second substring differ by at most $1$.

Given $T$ different strings that already satisfy the first condition, print for each of them whether they satisfy the second condition as well.

### Standard input

The first line contains an integer value, $T$.

Each of the next $T$ lines contains a string containing only A and B.

### Standard output

Output $T$ lines, each representing the answer for a string. If the balanced string conditions are met output $1$, otherwise output $0$

### Constraints and notes

$1 \leq T \leq 20$$1 \leq |S| \leq 50.000$

| Input | Output |
| --- | --- |
| 5<br>ABAABAABAB<br>AABABAABAB<br>ABBABBA<br>AABB<br>ABABABA | 0<br>1<br>0<br>0<br>1 |
