# License Plates

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/license-plates/](https://csacademy.com/contest/archive/task/license-plates/)  

---

You know that in a far away country all licence plates contain digits $(0..9)$ and characters $(a..z)$ and each of them respects a pattern. You are given a pattern $P$ containing characters $d$ and $c$, $d$ representing any digit and $c$ representing any character.

How many licence plates are possible knowing that it's not allowed to have $2$ consecutive symbols with the same value.

e.g: for pattern dd it's not allowed to have the licence plate 00 or 11 but 01 and 10 are considered valid.

### Standard input

The first line contains a string $P$ representing the pattern.

### Standard output

The first line should contain the number of possible number plates.

### Constraints and notes

the length of the string is $\leq 4$ it's guaranteed that the answer is $\leq 10^6$ the string contains only characters d and c 

| Input | Output | Explanation |
| --- | --- | --- |
| dd | 90 | Considering all 100 strings from 00 to 99 the invalid ones are00 11 22 33 44 55 66 77 88 99 |
| cc | 650 | There are $676$ strings in total of which $26$ are invalid. |
| dcdd | 23400 | Some invalid strings are 7e33 or 5h55 |
