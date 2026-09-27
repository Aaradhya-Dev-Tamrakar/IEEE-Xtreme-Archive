# Growing Trees

**Time Limit:** `8000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/growing-trees/](https://csacademy.com/contest/archive/task/growing-trees/)  

---

You are given a weighted tree $T$ with $N$ nodes. The initial weight of the $i^{th}$ edge is $C_i$, but every day the weight changes by $A_i$. Thus, its weight will be $C_i + k * A_i$ in day $k$. Note that the weights might be negative.

The diameter of $T$ is defined as a the maximum distance between any two nodes. Note that because the weights might be negative, it is possible the two nodes determining the diameter are not distinct.

You will observe the tree for $D+1$ days, starting from day 0 until day $D$. You want to find a date which minimizes the diameter. Formally, you need to find an integer $x \in [0, D]$ such that no other integer in $[0, D]$ yields a smaller diameter. If there is more than one such integer, you should find a smallest such integer.

### Standard input

The first line contains the number of nodes $N$, and the number of observing days $D$.

Each of the next $N-1$ lines contains four integer $S_i, E_i, C_i, A_i$, which indicates edge $i$ connects two vertices $S_i$ and $E_i$, and it has cost $C_i$ in day $0$, and it changes by $A_i$ everyday.

### Standard output

On the first line, print the integer $x \in [0, D]$ that minimizes the diameter in interval $[0, D]$. If there is more than one such integer, find a smallest such integer.

On the next line, print the diameter of tree in day $x$, when $x$ is the day you found in first line.

### Constraints and notes

$1 \leq N \leq 250\ 000$ $0 \leq D \leq 10^6$ $1 \leq S_i, E_i \leq N$ $|C_i| \leq 10^8$ $|A_i| \leq 10^3$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4<br>1 2 10 -2<br>2 3 20 2 | 0<br>30 | At days $0$ and $4$ the tree will look like:Note that the value of the diameter is the same $(30)$ The longest path is marked with red.1020123228123 |
| 3 10<br>1 2 20 -3<br>2 3 30 -4 | 8<br>0 | At days $0$ and $8$ the tree will look like:Note that the value of the diameter at time $D=8$ is $(0)$ from the distance between node $1$ and $1$.The longest path is marked with red.2030123 -4-2123 |
| 5 5<br>1 2 20 -3<br>2 3 10 -3<br>3 4 22 -2<br>3 5 26 -3 | 5<br>23 | At day $5$ the tree will look like:The longest path is marked with red.5-5121112345 |
| 4 0<br>1 2 -1 0<br>2 3 20 0<br>3 4 -1 0 | 0<br>20 | At day $0$ the tree will look like:The longest path is marked with red.-120-11234 |
