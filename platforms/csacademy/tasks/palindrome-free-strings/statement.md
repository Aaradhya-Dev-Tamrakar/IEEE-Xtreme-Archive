# Palindrome Free Strings

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/palindrome-free-strings/](https://csacademy.com/contest/archive/task/palindrome-free-strings/)  

---

You are given a string $S$. Your task is to change the minimum number of characters from $S$ so that it becomes palindrome free. We define a string as being palindrome free if it doesn't contain any palindrome of length $\geq 2$. Some example of palindrome free strings are: abc abca and some examples of non palindromic  free strings are aa aca caab and baab.

### Standard input

The first line contains the string $S$.

### Standard output

The first line should contain the minimum changes to string $S$ such that it becomes palindromic free.

### Constraints and notes

let $N$ be the length of string $S$, then $5 \leq N \leq 300$ $S$ contains only small latin letters. 

| Input | Output | Explanation |
| --- | --- | --- |
| abacd | 1 | abacdabecd |
| aacde | 1 | aacdedacde |
| abbaa | 2 | abbaaabcab |
| abbbe | 2 | abbbeaedbe |
