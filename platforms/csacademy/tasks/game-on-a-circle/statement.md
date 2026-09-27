# Game on a Circle

**Time Limit:** `1000 ms`  
**Memory Limit:** `64 MB`  
**Source:** [https://csacademy.com/contest/archive/task/game-on-a-circle/](https://csacademy.com/contest/archive/task/game-on-a-circle/)  

---

Consider a circular array of $100$ cells. The cells are indexed from $0$ to $99$ and initially they are all painted white.

The interactor chooses two values $a$ and $b$ (not necessarily distinct), and then paints in black all the cells: $a, a+1, a + 2, ..., a+9$ and $b, b + 10, b + 20, ..., b + 90$. Note that the values are considered modulo $100$, and its possible that a cell is painted twice (nothing happens in that case, it just stays black).

You should ask exactly $11$ queries of the type:

What is the color of cell $x$?

You cannot interrogate the same cell twice.

Your goal is to ask about black cells exactly twice.

### Interaction

First you should read a number $T$, representing the number of tests that follow.

For each test, you perform $11$ queries:

Print the index of a cellThen read the answer given by the interactor: $0$ for a white cell, $1$ for a black one.

Warnings:

Don't forget to flush after every output operationYou should always read the interactor's answer

### Constraints and notes

$1 \leq T \leq 100$ You cannot interrogate the same cell twice for a test

InteractionExplanation20110203040506070809010110150240501490511910940970980990For the first test $a = 0$ and $b = 10$.For the second test $a = 30$ and $b = 50$
