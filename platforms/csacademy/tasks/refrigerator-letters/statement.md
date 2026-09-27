# Refrigerator Letters

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/refrigerator-letters/](https://csacademy.com/contest/archive/task/refrigerator-letters/)  

---

You have $N$ refrigerator magnets, each representing a letter. You want to write the word $S$, but you might need to buy some more letters.

Find the minimum number of new magnets you need to buy.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ letters, representing the magnets you already have.

The third line contains the word $S$.

### Standard output

Print the number of magnets you need to buy on the first line.

### Constraints and notes

$1 \leq N \leq 100$ The length of $S$ is between $1$ and $100$ All the input characters are lowercase letters of the English alphabet

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>a b c d e f<br>aabfe | 1 | Buying a a magnet will be enough to write aabfe, leaving a d magnet unused. |
| 6<br>q w e r t y<br>asdfg | 5 | None of the $6$ letter magnets can be used to write asdfg so you'll need to buy all $5$ magnets. |
