# Jokers

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/jokers/](https://csacademy.com/contest/archive/task/jokers/)  

---

You have $N$ playing cards, on each of them is written a distinct number between $1$ and $1000$. You also have $M$ jokers that can be considered to be any card with a number between $1$ and $1000$.

A straight is a subset of $K$ cards that have or can be considered to have (in the case of jokers) consecutive numbers. Two straights are considered different if the largest cards in the straights have different values.

Find the number of different straights you can obtain.

### Standard input

The first line contains three integers $N$, $M$ and $K$.

The second line contains $N$ integers representing the values written on the $N$ cards.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N, M, K \leq 1000$

| Input | Output | Explanation |
| --- | --- | --- |
| 7 2 4<br>7 1 4 6 8 9 5 | 8 | The valid straights are (jokers are bold):1 2 3 42 3 4 53 4 5 64 5 6 75 6 7 86 7 8 97 8 9 108 9 10 11 |
