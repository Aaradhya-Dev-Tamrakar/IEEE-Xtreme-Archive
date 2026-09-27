# Fast Typing

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fast-typing/](https://csacademy.com/contest/archive/task/fast-typing/)  

---

You are given a word $S$ consisting of lowercase English letters. Each letter takes a certain given amount of time to print. How long will it take to print the whole word?

### Standard input

The first line contains a string $S$.

The next line contains $26$ integers $V_a$, $V_b$, ..., $V_z$, the time necessary to print $a$, $b$, ..., $z$.

### Standard output

The first line should consist of an integer, the necessary amount of time to print the given word.

### Constraints and notes

$1 \leq |S| \leq 100$ $1 \leq V_l \leq 1000$ for every $l \in \{a, b, ..., z\}$

| Input | Output |
| --- | --- |
| asabzabccz<br>2 7 5 5 5 6 7 9 3 5 5 8 6 1 8 6 8 1 7 6 2 2 8 9 1 4 | 45 |
| nopqrstuvwxyzmlkjihgfedcba<br>7 2 5 8 5 7 1 3 4 8 1 7 2 2 7 5 7 9 8 7 2 3 9 1 4 4 | 128 |
