# Suffix Flip

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/suffix-flip/](https://csacademy.com/contest/archive/task/suffix-flip/)  

---

Alex and Ben have a binary array $A$ of size $N$. They want to play a game where they take turns moving, Alex being the first to move. At each step, the player to move can take any suffix that starts with a $1$ and flip all the values in the suffix. Flipping a suffix means changing all the values from $0$ to $1$ and from $1$ to $0$. The player who cannot make a move loses the game.

If they both play optimally, find out the outcome of the game.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ binary values representing the elements of $A$. The values are not separated by spaces.

### Standard output

Print $1$ if Alex will win the game, $0$ otherwise.

### Constraints and notes

$1 \le N \le 10^5$ 

| Input | Output |
| --- | --- |
| 4<br>1010 | 0 |
| 3<br>111 | 1 |
