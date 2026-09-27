# Flareon

**Time Limit:** `3000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flareon/](https://csacademy.com/contest/archive/task/flareon/)  

---

The city of Alexandria has been invaded by Durants, ant like Pokemons. They have build $N$ anthills labeled from $1$ to $N$, connected by $N-1$ bidirectional tunnels, such that any anthill is reachable from any other anthill by following one or more tunnels. We define the distance $d(i, j)$ to be the number of tunnels that need to be traversed in order to travel between the anthills $i$ and $j$.

Candela, the leader of team Valor, has summoned $M$ Flareons. The $i^{th}$ Flareon is positioned next to the anthill $\text{Pos}_i$ and has a Lava Plume move of strength $\text{Power}_i$. A Lava Plume attack of power $p$ that takes place next to anthill $i$, contributes to the destruction degree $\text{Dmg}_j$ of anthill $j$ by $\text{max}(0, p-d(i, j))$.

You are asked to find, for each anthill $i$, its destruction degree $\text{Dmg}_i$ after all the $M$ attacks.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains an array $V$ of $N-1$ integers. There is a tunnel between anthills $i+1$ and $V_i$.

Each of the next $M$ lines contains two integers $\text{Pos}_i$ and $\text{Power}_i$.

### Standard output

Print $N$ lines, on the $i^{th}$ line the value of $\text{Dmg}_i$ after the $M$ Flareon attacks.

### Constraints and notes

$1 \leq N \leq 200\,000$ $1 \leq M \leq 500\,000$ $1 \leq \text{Power}_i \leq 10^9$ $1 \leq \text{Pos}_i \leq N$ There can be more than one Flareon next to the same anthillFor 20% of the test cases $N \leq 1000$ and $M \leq 2000$ For 70% of the test cases $N \leq 30\,000$ and $M \leq 30\,000$ 

| Input | Output |
| --- | --- |
| 4 3<br>1 1 3<br>2 2<br>3 2<br>4 10 | 10<br>9<br>11<br>11 |
