# Balanced Strings

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/balanced-strings/](https://csacademy.com/contest/archive/task/balanced-strings/)  

---

You would like to construct strings out of the characters a, b, and c.

Let $f(s,c)$ be the number of occurrences of the character c in the string $s$.

A string $s$ is called balanced if the following conditions are satisfied:

Let $t$ be any non-empty contiguous substring of $s$.We have the following equation satisfied $|f(t,x) - f(t,y)| \leq K$ for any $\{x,y\} \subseteq \{a,b,c\}$, where $K$ is a fixed constant given as input.

Count the number of strings with exactly $N$ characters we can create, modulo a given number $X$.

### Standard input

The first and only line of input contains three integers $N,K,X$.

### Standard output

Print the number of balanced strings modulo $X$.

### Constraints and notes

$1 \leq N \leq 10^9$ $1 \leq K \leq 5$ $10^8 \leq X \leq 10^9+10$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 1 1000000007 | 6 | The 6 ways are "abcab", "acbac", "bacba", "bcabc", "cabca", "cbacb". |
