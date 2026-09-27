# Infinity War

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/infinity-war/](https://csacademy.com/contest/archive/task/infinity-war/)  

---

Alex and Paul play a game with two piles of stones. Initially, they have $a$ and respectively $b$ stones. Alex starts the game, and the players alternate moving. At each step, the current player chooses one of the two piles and, if it's possible, he divides it into two new piles, each one having at least one stone. The pile that was not chosen is removed and the game continues only with the two new piles. If the current player can't make any move, he loses and the game ends. Knowing the values of $a$ and $b$ and the fact that both Alex and Paul play optimally, your task is to determine who will win the game.

### Standard input

The first line contains two integers $a$ and $b$ – the initial sizes of the two piles.

### Standard output

The output contains one character – A if Alex wins the game, or P otherwise.

### Constraints and notes

$1 \le a, b \le 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2 2 | A | Alex chooses a pile with $2$ stones, and he divides it into two new piles, each one having $1$ stone. Now there are two piles with size $1$ (note that the other pile of size $2$ was removed and can not be chosen later).Then, it follows Paul's turn, but he can't make any move, so the game ends and Alex is declared the winner. |
