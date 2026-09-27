# Concatenated String

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/concatenated-string/](https://csacademy.com/contest/archive/task/concatenated-string/)  

---

You are given two strings $A$ and $B$. You want to build a new string $S$ by concatenating $A$ with itself $K$ times. What's the minimum value of $K$ such that $B$ is a subsequence of $S$?

### Standard input

The first line contains a single string $A$.

The second line contains a single string $B$.

### Standard output

Print a single integer, the minimum value of $K$.

### Constraints and notes

The lengths of $A$ and $B$ are between $1$ and $10^5$ Both $A$ and $B$ consist only of lowercase letters of the English alphabetIf $B$ cannot appear as a subsequence of $A$ no matter how large $K$ is, print -1.

| Input | Output |
| --- | --- |
| aba<br>aab | 2 |
| abc<br>cba | 3 |
| abbab<br>aabbba | 2 |
| abacdaba<br>aaabbacaab | 3 |
