# Alex Concatenates

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alex-concatenates/](https://csacademy.com/contest/archive/task/alex-concatenates/)  

---

You are given a string $s$ and a list of $n$ words $w_1, w_2, \ldots, w_n$. You have to count the number of ways to write $s$ as a concatenation of the form $a_1 + a_2 + \cdots + a_n$, where $a_i$ is a substring (a non-empty contiguous subsequence) of $w_i$.

### Standard input

The first line contains the string $s$.

The second line contains the number $n$.

The next $n$ lines contain the strings $w_1, w_2, \ldots, w_n$.

### Standard output

The output contains the answer to the problem modulo $10^9 + 7$.

### Constraints and notes

$1 \le |s| \le 10000$ $1 \le n \le 1000$ $1 \le \sum_{i=1}^n|w_i| \le 10^5$ Two substrings are considered the same even if they start at different positions in the given string.

| Input | Output | Explanation |
| --- | --- | --- |
| fiicode<br>3<br>fiipractic<br>coding<br>codema | 4 |  |
| alex<br>2<br>andreea<br>alex | 1 | Two substrings are considered the same even if they start at different positions in the given string. |
