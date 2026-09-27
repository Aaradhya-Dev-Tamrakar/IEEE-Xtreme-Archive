# Distinct Palindromes

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/distinct-palindromes/](https://csacademy.com/contest/archive/task/distinct-palindromes/)  

---

You are given a string $S$ consisting of lowercase letters of the English alphabet. Count the number of distinct palindromes that are subsequences of $S$. Note that the same palindrome can occur multiple times as a subsequence, but it should only be counted once.

### Standard input

The first line contains the string $S$.

### Standard output

Print the answer modulo $10^9+7$ on the first line.

### Constraints and notes

The length of $S$ is between $1$ and $1\,000$ $S$ consists of lowercase letters of the English alphabet

| Input | Output | Explanation |
| --- | --- | --- |
| aaaaa | 5 | $\{\text{a, aa, aaa, aaaa, aaaaa}\}$ |
| abbaab | 10 | $\{\text{a, aa, aaa, aba, abba, b, baab, bab, bb, bbb}\}$ |
