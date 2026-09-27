# Falling Leaves

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/falling-leaves/](https://csacademy.com/contest/archive/task/falling-leaves/)  

---

There is a cat on the x-axis. The cat can start running from the origin towards infinity at an integer moment between $[0, T-1]$, at a speed of $C$ units/second.

There are also $N$ leaves, for the $i^{\text{th}}$ leaf you know its position $(x_i, y_i)$ in the plane. Each leaf will start to fall vertically at time $0$ at a speed of $S_i$ units/second.

We say the $i^{\text{th}}$ leaf hits that cat if the cat is at coordinate $x_i$ at the exact moment when the leaf touches the axis.

For each integer starting moment between $0$ and $T-1$, find the number of leaves that will hit the cat.

### Standard input

The first line contains three integers $T$, $C$ and $N$.

Each of the next $N$ lines contains three integers $x_i$, $y_i$ and $S_i$.

### Standard output

Print $T$ lines, each containing the answer for a starting moment between $0$ and $T-1$.

### Constraints and notes

$1 \leq T \leq 1\,000$ $1 \leq C \leq 10^5$ $1 \leq N \leq 1\,000$ $1 \leq x_i, y_i \leq 10^5$ $1 \leq S_i \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2 5<br>6 9 3<br>4 6 3<br>4 9 3<br>9 18 4<br>7 157 45 | 3<br>1<br>0 | If the cat starts at the moment of time $0$ it will hit the $1^{\text{st}}$, $2^{\text{nd}}$ and $4^{\text{th}}$ leaves. If she starts one moment later, she will hit the $3^{\text{rd}}$ leaf. |
