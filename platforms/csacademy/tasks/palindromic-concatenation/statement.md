# Palindromic Concatenation

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/palindromic-concatenation/](https://csacademy.com/contest/archive/task/palindromic-concatenation/)  

---

You are given $N$ strings. Find the number of pairs $(i, j)$ such that concatenation of the $i$-th and the $j$-th strings is a palindrome.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains a string.

### Standard output

Output a single number representing the number of valid pairs.

### Constraints and notes

$1 \leq N \leq 10^5$ The sum of lengths of all the strings is between $1$ and $10^5$ The strings consist of lowercase letters of the English alphabetYou should only consider pairs whehre $i \neq j$ It's possible that both $(i, j)$ and $(j, i)$ are valid pairs, in which case you should count both.

| Input | Output |
| --- | --- |
| 8<br>abaccabaab<br>accaba<br>abacc<br>ab<br>ba<br>aba<br>ccaba<br>abaaba | 14 |
| 5<br>bac<br>ccab<br>ba<br>cab<br>bac | 8 |
| 5<br>aa<br>a<br>aaa<br>a<br>ab | 14 |
