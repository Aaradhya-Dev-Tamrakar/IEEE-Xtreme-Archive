# Adjacent Vowels

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/adjacent-vowels/](https://csacademy.com/contest/archive/task/adjacent-vowels/)  

---

You are given a string $S$ consisting of $N$ lowercase letters of the English alphabet. Count the number of adjacent pairs of vowels.

In this problem, we consider there are $5$ letters that represent vowels: a, e, i, o and u.

### Standard input

The first line contains a single integer $N$.

The second line contains the string $S$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 1000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>aeoui | 4 | $(ae)oui$$a(eo)ui$$ae(ou)i$$aeo(ui)$ |
| 7<br>abaebio | 2 | $ab(ae)bio$$abaeb(io)$ |
| 7<br>abcdefg | 0 |  |
| 6<br>aabbcc | 1 | $(aa)bbcc$ |
