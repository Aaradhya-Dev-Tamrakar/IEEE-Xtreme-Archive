# Strange Substring

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/strange-substring/](https://csacademy.com/contest/archive/task/strange-substring/)  

---

You are given two strings $A$ and $B$, consisting only of lowercase letters from the English alphabet. Count the number of distinct strings $S$, which are substrings of $A$, but not substrings of $B$.

### Standard input

The first line contains $A$.

The second line contains $B$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq |A|, |B| \leq 10^5$ 

| Input | Output |
| --- | --- |
| abcab<br>bcab | 3 |
| aaa<br>aa | 1 |
| acabad<br>abcacd | 12 |
