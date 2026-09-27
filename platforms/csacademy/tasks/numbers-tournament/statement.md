# Numbers Tournament

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/numbers-tournament/](https://csacademy.com/contest/archive/task/numbers-tournament/)  

---

There are $N$ children, each one of them has an array of $N$ numbers. They will start a tournament where every pair of children will play exactly one game.

In a game the two children involved find their lowest and highest common numbers, let's call these values $a$ and $b$. Each of them will then count how many numbers his array has outside of the interval $[a, b]$. The child with the highest count wins, in case of equality the game is declared a draw.

The winner of game is awarded $2$ points, and in case of a draw they each get $1$ point. Losing a game doesn't score any points. Find the final standings of the tournament. In case two or more children have the same score print them in increasing order of their index.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains $N$ integers, representing the array of a child.

### Standard output

Print a permutation representing the final standings.

### Constraints and notes

$1 \leq N \leq 100$ The numbers in the arrays are integers between $0$ and $10\,000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 2 4 5<br>2 3 4 5<br>8 7 6 5<br>3 4 5 8 | 1<br>4<br>2<br>3 | $1$ beats $2$ and $4$ beats $3$.The other $4$ games end in a tie.That means that both $1$ and $4$ have $4$ points while $2$ and $3$ have $2$ points. |
