# Limited Moves

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/limited-moves/](https://csacademy.com/contest/archive/task/limited-moves/)  

---

Consider a heap of $N$ objects. Two players take turns playing the following game:

At his very first move, the first player removes from the heap between $1$ and $N-1$ objectsAfter that, at each step the player to move can remove any number of objects between $1$ and the number of objects removed by the other player at the previous moveWhen the heap becomes empty, the player to move loses the game.

Write a program that simulates the moves of the first player. It is guaranteed you will have a winning strategy on all the tests.

### Interaction

First you should read the number of $N$.

Then you can start making your moves: just print an integer representing the number of objects removed. After each of your moves you should read the interactor's move.

Your program should stop when the heap becomes empty or after making $500$ moves.

### Constraints and notes

This task is adaptive$2 \leq N \leq 10^{8}$ It is guaranteed the first player has a winning strategy on all the tests

InteractionExplanation511111Note that you must stop after the number of objects reach 062221024000Note: use this example to check if your program stops after making 500 movesYou must read the interactor's answer after making the 500th moveIn short, you must do the paired interaction 500 timesprovide your moveget computer's move
