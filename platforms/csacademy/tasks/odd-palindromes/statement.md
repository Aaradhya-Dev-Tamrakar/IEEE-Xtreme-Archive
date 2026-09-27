# Odd Palindromes

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/odd-palindromes/](https://csacademy.com/contest/archive/task/odd-palindromes/)  

---

A string is odd palindromic if all it's odd length subarrays are palindromes.

You are given a string $S$ of size $N$. You are allowed to change at most $K$ letters in $S$. Your goal is obtain the longest possible odd palindromic subarray of $S$.

### Standard input

The first line contains a single integer $K$.

The second line contains the string $S$.

### Standard output

Print the maximum possible length of an odd palindromic subarray on the first line.

### Constraints and notes

$1 \leq K \leq N \leq 10^6$ $S$ contains only lowercase letters of the English alphabet

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>abbc | 4 | A possible solution:bbbb |
| 1<br>ab | 2 | aa |
| 1<br>abcdef | 3 | abadef |
| 1<br>accca | 5 | acaca |
| 3<br>abcd | 4 | aaaa |
