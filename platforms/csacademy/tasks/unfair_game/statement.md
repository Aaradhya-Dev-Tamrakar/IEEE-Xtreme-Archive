# Unfair Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/unfair_game/](https://csacademy.com/contest/archive/task/unfair_game/)  

---

Alex and Ben have a set of $N$ integers, so they decided to play a game. The two players take turns playing, Alex being the first to move. This game is asymmetrical, as follows:

When it's Alex's turn, he chooses any non-empty subset of numbers and removes them from the set.When it's Ben's turn, he chooses exactly one number and removes it from the set.

The game ends when there are no numbers left in the set. Alex's goal is to maximize the sum of the numbers he chooses, while Ben just tries to minimize Alex's sum. Considering that both of them play optimally, you should compute the outcome of the game.

### Standard input

The first line contains a single integer $N$, the size of the set.

The second line contains the $N$ values in the set.

### Standard output

The output should contain a single number representing Alex's sum if they both play optimally.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array will be between $-10^9$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>-1 2 10 -10 3 | 14 | Alex chooses $-1$, $2$, $3$, and $10$.Ben chooses $-10$. |
| 5<br>-5 2 -10 4 -7 | -1 | Alex chooses $2$ and $4$.Ben chooses $-5$.Alex chooses $-7$.Ben chooses $-10$. |
