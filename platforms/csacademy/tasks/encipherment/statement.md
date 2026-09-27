# Encipherment

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/encipherment/](https://csacademy.com/contest/archive/task/encipherment/)  

---

You are given a string $S$ and a permutation $P$ of the lowercase English alphabet. You are supposed to encode $S$ by the means of the following method: for every character $c$ in $S$, we'll find its' order in the English alphabet; let it be $i$. We will then replace $c$ with $P_i$.

### Standard input

The first line contains $S$.

The second line contains $26$ lowercase letters representing $P$.

### Standard output

Print the encoded string on the first line of the output.

### Constraints and notes

$1 \leq |S| \leq 100$ $S$ only consists of lowercase English letters 

| Input | Output | Explanation |
| --- | --- | --- |
| csacademy<br>chtyvsduiaklqegonwmrzpxbfj | tmctcyvqf | Since 'c' is the third letter of the alphabet, its encoding will be 't'. The same for the rest of the letters. |
