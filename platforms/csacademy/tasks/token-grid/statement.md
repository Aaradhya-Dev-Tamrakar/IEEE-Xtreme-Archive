# Tokens on a grid

**Time Limit:** `1500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/token-grid/](https://csacademy.com/contest/archive/task/token-grid/)  

---

You are given an $N$ by $M$ grid.

Each grid square is either empty, or contains a token with a color labeled from 'a' to 'z'. Empty squares are denoted by '.'.

You would like to remove some tokens, such that the following conditions are satisfied:

Each column only has tokens of a single colorThere are exactly $K$ empty rows.

Print the number of ways to remove the tokens, for each $K$ between $0$ and $N$, modulo $10^9+7$.

### Standard input

The first line contains two integers $N, M$.

The next $N$ lines will contain a string with exactly $M$ characters, consisting of '.' or a English lowercase letter.

### Standard output

Print out $N+1$ integers. The $i^{th}$ integer is the number of ways to satisfy the constraints with exactly $i$ empty rows, modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 16$ $1 \leq M \leq 1000$ 

| Input | Output |
| --- | --- |
| 5 2<br>ab<br>ab<br>ab<br>ab<br>ab | 243 405 270 90 15 1 |
| 5 1<br>a<br>b<br>a<br>a<br>b | 0 0 1 4 5 1 |
| 3 2<br>a.<br>.b<br>c. | 0 2 3 1 |
