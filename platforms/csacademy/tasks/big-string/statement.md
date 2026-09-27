# Big String

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/big-string/](https://csacademy.com/contest/archive/task/big-string/)  

---

You are given  a string $S$ containing only lowercase English letters and you have to apply the following operation $K$ times:

Let $S$ be the current string and $P$ its prefix of length $|S|-1$. Replace $S$ with $S+reverse(P)$.

Find the number of times each letter in the English alphabet appears in $S$ after $K$ such operations.

### Standard input

The first line of the input contains the string $S$.

The second line of the input contains a positive integer $K$.

### Standard output

The first line of the output contains 26 integers: the number of times each letter in the English alphabet appears in $S$ after applying the described operation $K$ times. (The first number is the number of occurrences of letter "a", the second is for the letter "b", etc...)

### Constraints and notes

$1 \leq |S| \leq 500$ $1 \leq K \leq 50$

| Input | Output | Explanation |
| --- | --- | --- |
| xrabrsagqw<br>3 | 16 8 0 0 0 0 8 0 0 0 0 0 0 0 0 0 8 16 8 0 0 0 4 5 0 0 |  |
| agjv<br>1 | 2 0 0 0 0 0 2 0 0 2 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 | After the first operation $S$ = $agjv$+$jga$=$agjvjga$ |
