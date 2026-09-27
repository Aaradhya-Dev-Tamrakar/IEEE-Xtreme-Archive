# Array Macao

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/array-macao/](https://csacademy.com/contest/archive/task/array-macao/)  

---

Alice and Bob are playing a card game. Each of them has a deck of $N$ cards, and on each card there is written a number between $1$ and $10^9$. We will denote Alice's cards as $a_1, a_2, ..., a_N$ and Bob's cards by $b_1, b_2, ..., b_N$.

The game is played as follows: each player must play a card from his deck alternately: If Alice plays the card $a_i$, then Bob's next card must have a bigger index (some $b_j$ such that $j>i$). The same rule is applied to Alice: If Bob plays $b_i$, Alice's next card can be some $a_j$ such that $j > i$.

Moreover, every two consecutive played cards must have a common digit in their decimal representation. For example $126, 552, 5, 15$ is a valid sequence that can result after some correct moves, while $15, 64, 44$ is not ($15$ and $64$ have no common digit).

Alice always moves first.

Your task is to find the maximum number of turns the game can last. In other words, you have to find the maximum possible length of a sequence $a_{i_1}, b_{i_2}, a_{i_3}, b_{i_4}...$ with $i_1 < i_2 < i_3 < ...$, where each two consecutive elements have at least one digit in common.

### Standard input

The first line in the input contains a positive integer $N$, the number of cards in each of the two decks.

The second line contains Alice's deck of cards: $a_1, a_2, ..., a_N$,

The third line contains Bob's deck: $b_1, b_2, ..., b_N$.

### Standard output

You should output a single positive integer, the maximum number of turns the game may last.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq a_i, b_i \leq 10^9$ 

| Input | Output |
| --- | --- |
| 4<br>12 42 25 11<br>2 16 77 13 | 3 |
| 3<br>1 5 7<br>25 22 22 | 1 |
