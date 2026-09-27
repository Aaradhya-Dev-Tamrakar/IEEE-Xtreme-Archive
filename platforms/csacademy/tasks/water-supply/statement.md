# Water Supply

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/water-supply/](https://csacademy.com/contest/archive/task/water-supply/)  

---

There are $N$ cities that don't have any water provision. In each city $i$ you can build a fountain with cost $F_i$. Additionally, between any pair of cities $(i, j)$ you can build a water pipe with cost $C_{i, j}$. You goal is to supply all cities with water with minimum cost, building at most $K$ fountains.

A city is considered to be supplied with water if:

A fountain is build in that cityIt is connected to some other city with a fountain using the water pipes.

### Standard input

The first line contains a single integer $T$ representing the number of tests that follow.

For each test:

The first line contains two integers $N$ and $K$.The second line contains $N$ integers represeting the values of $F$.Each of the next $N$ lines contains $N$ integers representing the costs $C$. It is guaranteed $C_{i, j} = C_{j, i}$ and $C_{i, i} = 0$.

### Standard output

For each test print a single number, the minimum cost of supplying all the cities with water.

### Constraints and notes

$1 \leq T \leq 2000$ $1 \leq K \leq N \leq 2000$ The sum of $N$ for all tests $\leq 2000$ $1 \leq F_i, C_{i, j}\leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>3 1<br>2 5 8<br>0 7 10<br>7 0 10<br>10 10 0<br>3 2<br>2 5 8<br>0 7 10<br>7 0 10<br>10 10 0 | 19<br>17 | Building a fountain in city $1$ costs 2.The total cost will be $(2 + 10 + 7 = 19)$ 71010123Building a fountain in city $1$ costs 2.Building a fountain in city $2$ costs 5.The total cost will be $(2 + 5 + 10 = 17)$ 71010123 |
| 1<br>3 3<br>2 5 8<br>0 7 10<br>7 0 10<br>10 10 0 | 15 | Building a fountain in city $1$ costs 2.Building a fountain in city $2$ costs 5.Building a fountain in city $3$ costs 8.The total cost will be $(2 + 5 + 8 = 15)$ 71010123 |
| 1<br>4 2<br>2 1 3 10<br>0 5 1 15<br>5 0 20 20<br>1 20 0 20<br>15 20 20 0 | 17 | Building a fountain in city $2$ costs 1.Building a fountain in city $4$ costs 10.The total cost will be $(1 + 10 + 5 + 1 = 17)$ 51152020201234 |
