# Matching Substrings

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/matching-substrings/](https://csacademy.com/contest/archive/task/matching-substrings/)  

---

You are given $N$ (not necessarily distinct) strings of length $K$. You should build a string $S$ of length $N+K-1$.

For any string $T$ of length $K$, if it occurs among the $N$ given strings $X$ times, then there should be exactly $X$ substrings of $S$ equal to $T$.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N$ lines contains a string of length $K$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the string $S$ on the first line. If the solution is not unique you can print any of them.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq K \leq 10^5$ $1 \leq N * K \leq 10^6$ The strings contain lowercase letters of the English alphabet

| Input | Output |
| --- | --- |
| 6 2<br>ab<br>ae<br>ef<br>cd<br>da<br>bc | abcdaef |
| 3 3<br>bcd<br>cda<br>abc | abcda |
| 1 5<br>hello | hello |
| 3 6<br>meowth<br>mewand<br>mewtwo | -1 |
| 2 3<br>abc<br>abd | -1 |
