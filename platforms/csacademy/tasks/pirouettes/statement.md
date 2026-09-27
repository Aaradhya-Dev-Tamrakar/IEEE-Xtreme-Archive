# Pirouettes

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pirouettes/](https://csacademy.com/contest/archive/task/pirouettes/)  

---

Given an integer $N$, consider a room of length $2*N+2$ represented as an interval $[-N-1, N+1]$. In the center $C = 0$ of the room, there's initially a ballerina called Costelina Salopeta. She's about to perform $T$ dancing steps of length $1$, the first one being to the right. In the $2*N$ points of integer coordinates in the room you can place $K$ obstacles. When the ballerina reaches an obstacle, she trips and performs a pirouette. This way, she changes moving direction and the obstacle disappears.

You are not allowed to add an obstacle at coordinates $-N-1$, $0$ or $N+1$. The walls of the room at coordinates $-N-1$ and $N+1$ are considered to be permanent obstacles, that are never going to disappear, and the point of coordinate $C=0$ is the initial position of Costelina.

Given the values of $T$, $N$ and $K$, compute the number of ways of placing $K$ obstacles, such that after $T$ steps Costelina will end back in the starting point $C$.

### Standard input

The first line contains $3$ integers $T$, $N$ and $K$.

### Standard output

Output a single integer representing the answer modulo $10^9+7$.

### Constraints and notes

$0 \leq T \leq 200$, $T$ is even$1 \leq N \leq 100$ $0 \leq K \leq 2*N$ For 10% of the testcases, $N \leq 10$ For 30% of the testcases, $N \leq 30$ For 70% of the testcases, $T \leq 2*N+2$ 

| Input | Output |
| --- | --- |
| 6 3 4 | 7 |
| 8 3 1 | 3 |
