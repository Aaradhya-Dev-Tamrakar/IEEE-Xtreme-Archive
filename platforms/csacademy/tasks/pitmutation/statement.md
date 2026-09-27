# Pitmutation

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pitmutation/](https://csacademy.com/contest/archive/task/pitmutation/)  

---

Pitmuation is a two player card game, where each player has a deck of $N$ cards numbered from $1$ to $N$. The two players shuffle their decks and they put the cards on the table one by one. At each step, the player with the higher card wins one point. If the two cards are equal, there are no points awarded. The game ends after $N$ steps, when all the cards have been used.

For some indices between $1$ and $N$ you know the cards of the first player, and for the other indices you know the cards of the second player.

Given the size of the decks $N$, an integer $S$ and the known cards for the two players, determine the number of configurations of the unknown cards where the first player is awarded a total of exactly $S$ points.

### Standard input

The first line contains two integers $N$ and $S$.

The second line contains $N$ integers between $0$ and $N$, corresponding to the first player. The $0$s represent unknown cards, while the other values represent known cards.

The third line contains $N$ integers corresponding to the cards of the second player, in the same manner.

### Standard output

Output the answer modulo $10^9+7$.

### Constraints and notes

$0 \leq S < N \leq 300$ 

| Input | Output |
| --- | --- |
| 4 2<br>4 2 0 0<br>0 0 4 2 | 2 |
