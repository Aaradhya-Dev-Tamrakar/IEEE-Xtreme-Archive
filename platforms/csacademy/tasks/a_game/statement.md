# A-Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/a_game/](https://csacademy.com/contest/archive/task/a_game/)  

---

Alex and Ben have a string $S$ consisting of $N$ characters from the set $\{A, B\}$, so they decided to play a game. The two players take turns playing, Alex being the first to move. A move consists of choosing a non-empty substring of $S$ that does not overlap with any substring chosen before it. The game ends when all elements of $S$ are chosen, and the winner of the game is the player who selected  fewer $A$s among his substrings. In case they both choose the same number of $A$s the game is a draw.

Considering that both players play optimally, compute the outcome of the game.

### Standard input

The first line contains a single integer $N$, the size of the string.

The second line contains the string $S$.

### Standard output

The output should contain the outcome of the game. If Alex wins, print $A$, if Ben wins, print $B$ and if the game ends in a draw, print $-1$.

### Constraints and notes

$1 \leq N \leq 10^5$Alex chooses first

| Input | Output |
| --- | --- |
| 2<br>AA | -1 |
| 9<br>AABABABBA | A |
| 11<br>ABAABBABBBA | B |
