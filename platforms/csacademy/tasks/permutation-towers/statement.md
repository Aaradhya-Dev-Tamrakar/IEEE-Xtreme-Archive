# Permutation Towers

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/permutation-towers/](https://csacademy.com/contest/archive/task/permutation-towers/)  

---

You want to build $N$ towers having distinct heights between $1$ and $N$. The towers should be build in a straight line, so we can consider each of them is build at a certain coordinate between $1$ and $X$.

The distance between two towers is equal to their coordinate difference. For each tower the distance to the previous and the next towers should be equal or greater than the tower's height.

Find the number of possibilities of building the towers.

### Standard input

The first line contains three integers $N$, $X$ and $M$.

### Standard output

Print a single integer representing the number of ways of building the towers modulo $M$.

### Constraints and notes

$1 \leq N \leq 100$ $1 \leq X \leq 10^5$ $10^8 \leq M \leq 10^9$ $M$ is a prime number

| Input | Output |
| --- | --- |
| 2 3 400000009 | 2 |
| 2 4 400000043 | 6 |
| 3 6 400000049 | 4 |
| 3 7 400000067 | 18 |
