# Pokémon Evolution

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pokemon-evolution/](https://csacademy.com/contest/archive/task/pokemon-evolution/)  

---

You have recently caught $N$ Pokémon and you also have $M$ Pokémon candy bars. You can evolve any of your Pokémon by paying $X$ candy bars. Alternatively, you can sell any of your Pokémon for a price of $Y$ candy bars. You cannot sell an evolved Pokémon.

Compute the maximum number of Pokémon you can evolve.

### Standard input

The first line contains $4$ integers $N\ M\ X\ Y$.

### Standard output

The output should contain a single integer representing the maximum number of Pokémon you can evolve.

### Constraints and notes

$1 \leq N, M, X, Y \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 10 2 1 | 5 | You can evolve all the Pokémon if you use all the available candy. |
| 3 10 4 2 | 2 | You can evolve $2$ Pokémon using the initial candy. Selling one Pokémon  would result in a total of $10+2=12$ candy bars. This is enough to evolve $3$ Pokémon, but you wouldn't have $3$ Pokémon left to evolve. |
| 10 3 1 1 | 6 |  |
