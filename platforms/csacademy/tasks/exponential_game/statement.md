# Exponential Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/exponential_game/](https://csacademy.com/contest/archive/task/exponential_game/)  

---

Alex and Ben have a set of $N$ heaps of objects and they decide to play a game. The two players take turns playing, Alex being the first to move. A move consists of choosing a heap of objects and removing it completely. In addition, a player can choose to add back in the set one or more new heaps: if the removed heap consists of $X$ objects they can add at most $X - 1$ heaps containing at most $X-1$ objects each. The added heaps can have different sizes.

The last player who makes a valid move wins. Considering that both players play optimally, compute the outcome of the game.

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consits of two lines:

The first line contains a single integer $N$, the number of heaps of objectsThe second line contains $N$ values representing the sizes of the heaps.

### Standard output

The output should contain the answer for each test case on a different line.

Each answer consists of a single character: if Alex wins print $A$, otherwise print $B$.

### Constraints and notes

$1 \leq T \leq 20\ 000$The sum of all the values of $N$ in an input file is $\leq 10^5$The sizes of the heaps are between $1$ and $10^9$

| Input | Output |
| --- | --- |
| 2<br>3<br>2 3 1<br>4<br>1 1 1 1 | A<br>B |
