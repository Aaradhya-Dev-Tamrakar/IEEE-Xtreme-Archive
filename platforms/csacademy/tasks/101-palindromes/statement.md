# 101 Palindromes

**Time Limit:** `800 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/101-palindromes/](https://csacademy.com/contest/archive/task/101-palindromes/)  

---

You are given a string $S$ where each character is a digit from $0$ to $9$. You should count the number of subsequences respecting the following two properties:

The subsequence is a palindrome.If we interpret the characters as digits we get a number divisible by $101$.

### Standard input

The first line contains a single integer represing the length of $S$.

The second line contains the string $S$.

### Standard output

Output a single number representing the number of valid subsequences modulo $10^9+7$.

### Constraints and notes

The length of $S$ is between $1$ and $200$.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>31313 | 0 | $3131$ is divisible by $101$ but it's not a palindrome. |
| 6<br>102201 | 7 | Considering the array to be 1-indexed, the $7$ valid subsequences are: $\{1, 2, 6\}=>101$ $\{1, 5, 6\}=>101$$\{1, 2, 3, 5, 6\}=>10201$ $\{1, 2, 4, 5, 6\}=>10201$$\{2\}=>0$ $\{5\}=>0$$\{2, 5\}=>00$Notice that you also need to count subsequences with leading zeroes. |
| 5<br>77777 | 5 | Any subsequence of $4$ elements is a valid. |
