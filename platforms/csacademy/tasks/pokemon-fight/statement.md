# Pokemon Fight

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pokemon-fight/](https://csacademy.com/contest/archive/task/pokemon-fight/)  

---

Alex has $N$ Pokémon, while Ben has $M$ Pokémon ($N \geq M$). For each of them you know their combat power, which we'll denote by $CP$. If two Pokémon fight the one with the higher $CP$ wins. If they have the same $CP$ the fight ends in a draw.

Alex wants to choose $M$ of his Pokémon and make each of them fight with one of Ben's Pokémon. Obviously, Alex wants to win all the $M$ fights. In every fight, the two Pokémon get hurt, no matter who wins. Alex is worried about this, because he wants to be as prepared as possible for other future confrontations. If there are more possibilities of winning all the $M$ fights, Alex is interested in maximizing the sum of $CP$ of all the other $N-M$ Pokémon that he doesn't choose to fight Ben. Your task is to help Alex.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $N$ integers representing the $CP$ of Alex's Pokémon.

The third line contains $M$ integers representing the $CP$ of Ben's Pokémon.

### Standard output

The first line should contain $-1$ if there is no possibility for Alex to win all the $M$ fights. Otherwise, output a single integer representing the maximum sum of $CP$ of the Pokémon that are not used to fight Ben.

### Constraints and notes

$1 \leq M \leq N \leq 10^5$The $CP$ of all the Pokémon are integers between $1$ and $2*10^5$

| Input | Output |
| --- | --- |
| 2 2<br>5 9<br>4 1 | 0 |
| 4 3<br>10 1 7 5<br>5 2 11 | -1 |
| 6 3<br>4 6 9 10 14 17<br>4 7 9 | 35 |
