# Boaty McBoatface

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/boaty-mcboatface/](https://csacademy.com/contest/archive/task/boaty-mcboatface/)  

---

Boaty McBoatface started its travel to the East. The goal is to move $D$ kilometers to the East. The boat travels at a speed of $V_1$ kilometers per hour. The East Wind just started and it'll last for another $T$ hours. The wind moves Boaty to the West with $V_2$ kilometers per hour.

How many hours will take Boaty to reach its destination? Print this number rounded up.

### Examples:

If $V_1 = 3$  and $V_2 = 5$ boaty will move with a speed of $2$ kilometers per hour to the West.If the answer is $3.1$ print $4$ and for $5$ print $5$.

### Standard input

The first contains four integers $D$, $T$, $V_1$ and $V_2$ with the meaning from the statement.

### Standard output

The first should should contain the answer, rounded up if necessary.

### Constraints and notes

$1 \leq D \leq 1000$ $0 \leq T \leq 100$ $1 \leq V_1 \leq 100$ $1 \leq V_2 \leq 100$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 10 2 5 7 | 5 | Explanation format:After moving for $T$ hours, Boaty needs to move $X$ to the East.$T = 0, X = 10$ $T = 1, X = 12$ $T = 2, X = 14$ - The East Wind ends$T = 3, X = 9$ $T = 4, X = 4$ $T = 5, X = 0$ Note that Boaty will complete the task at $T = 4.8$ but the number is rounded up, so $5$ is printed. |
| 11 3 3 2 | 6 | $T = 0, X = 11$ $T = 1, X = 10$ $T = 2, X = 9$ $T = 3, X = 8$ - The East Wind ends$T = 4, X = 5$ $T = 5, X = 2$ $T = 6, X = 0$ |
| 12 3 3 2 | 6 | $T = 0, X = 12$ $T = 1, X = 11$ $T = 2, X = 10$ $T = 3, X = 9$ - The East Wind ends$T = 4, X = 6$ $T = 5, X = 3$ $T = 6, X = 0$ Note that Boaty will arrive precisely at $T = 6$. |
| 13 3 3 2 | 7 | $T = 0, X = 13$ $T = 1, X = 12$ $T = 2, X = 11$ $T = 3, X = 10$ - The East Wind ends$T = 4, X = 7$ $T = 5, X = 4$ $T = 6, X = 1$ $T = 7, X = 0$ Note that Boaty will arrive at $T = 6.3$The answer will not be rounded down! |
