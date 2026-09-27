# Vaporeon

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/vaporeon/](https://csacademy.com/contest/archive/task/vaporeon/)  

---

Blanche, the leader of team Mystic, has been captured by Team Locket! She was taken in one of the team's hideouts that contains $N$ obstacles labeled from $1$ to $N$, each obstacle $i$ having an associated value $R_i$. Initially, Blanche is situated next to the $x^{th}$ obstacle. Trying to escape, she frees Vaporeon who destroys the $x^{th}$ obstacle and gains an attack power $A$ equal to $R_x$.

In order to escape, Vaporeon has to destroy all the obstacles. At any given moment when he has destroyed all the obstacles in an interval $[x, y]$, Vaporeon can perform one of the following moves:

Hydro Pump obstacle $x-1$ if $x-1 \geq 1$ and $R_{x-1} \leq A$ Hydro Pump obstacle $y+1$ if $y+1 \leq N$ and $R_{y+1} \leq A$ Work Up, which changes the attack power $A$ to $\text{min}(R_{x-1}, R_{y+1})$. If only one of these two obstacles exists, $A$ become equal to that obstacle's $R$ value.

A Hydro Pump move costs $1$ unit of effort, while a Work Up costs $K$ units. We say $E_x$ is equal to the minimum effort necessary to escape starting at obstacle $x$.

Team Locket has anticipated this strategy, so they are currently studying different arrangements of the obstacles and different starting obstacles where to place Blanche. They tell you the number of obstacles $N$, a value $K$ needed for a Work Up move and the $R$ values of the obstacles. Then, they ask you to do the following operations:

Change two adjacent obstacles $x$ and $x+1$ Find, for two indices $x$ and $y$, the value of $E_x + E_{x+1} + ... + E_{y}$ for the current arrangement of the obstacle

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers, representing the values $R$ of the obstacles.

The next lines, until the end of the file, describe an operation each. A line describing the first type of operation contains two integers $1$ and $x$. A line describing the second type of operations contains three integers $2$, $x$ and $y$.

### Standard output

For each operation of the second type print the answer on a distinct line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq K \leq 10^6$ $1 \leq R_i \leq 10^9$ The total number of operations is $\leq 200\,000$ For 20% of the test cases, $N \leq 1000$ and the total number of operations is $\leq 2000$

| Input | Output |
| --- | --- |
| 5 3<br>2 3 1 4 1<br>2 2 2<br>2 1 5<br>1 2<br>2 2 2<br>2 1 5 | 7<br>38<br>13<br>41 |
