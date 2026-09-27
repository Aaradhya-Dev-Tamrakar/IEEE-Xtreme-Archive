# Safe Spots

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/safe-spots/](https://csacademy.com/contest/archive/task/safe-spots/)  

---

There are $N$ people in a row. Some of them are thieves, other are just regular people. A regular person is safe if amongst all those at distance at most $K$ there is at most $1$ thief. Find out the number of safe people.

### Standard input

The first line contains two integer $N$ and $K$.

The second line contains $N$ integers corresponding to the people in the row. A thief is represented by a $1$, while a regular person by a $0$.

### Standard output

Print the number of safe people on the first line.

### Constraints and notes

$1 \leq K \leq N \leq 10^5$ The distance between two people with indices $i$ and $j$ is equal to $|i-j|$

| Input | Output | Explanation |
| --- | --- | --- |
| 8 2<br>1 1 0 0 0 0 0 1 | 4 | The third person in the row is not safe, since there are two thieves at distance at most $2$ from him ($1$ and $2$). |
