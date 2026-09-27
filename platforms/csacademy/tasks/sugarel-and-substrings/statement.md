# Sugarel and Substrings

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sugarel-and-substrings/](https://csacademy.com/contest/archive/task/sugarel-and-substrings/)  

---

Sugarel solved the first problem and discovered how many application modulo has in cryptography. Today he has the hacker mood on.  He wants to do some reverse engineering on a LONG string, but he got stuck at this problem :

Given a string containing only lowercase English letters, Sugarel is supposed to find the number of substrings which contain distinct letters.  Two substrings are considered distinct (can be counted separately) if their beginning or ending index is different.

Sugarel wants to move fast and thus he wants you to solve it for him meanwhile.

### Standard input

The first line of the input contains a positive integer $N$ representing length of the string.

The second line of the input contains a string.

### Standard output

The first line of the output contains only a positive integer representing the number of substrings with non-repeating letters.

### Constraints and notes

$1 \leq N \leq 10^5$

| Input | Output |
| --- | --- |
| 3<br>fii | 4 |
| 9<br>csacademy | 29 |
