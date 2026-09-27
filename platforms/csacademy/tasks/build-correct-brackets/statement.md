# Build Correct Brackets

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/build-correct-brackets/](https://csacademy.com/contest/archive/task/build-correct-brackets/)  

---

You are given a string consisting of open and closed parentheses: characters ( and ). You can flip any character, from ( to ) , or from ) to (.

Find the minimum number of flips necessary to make the string correctly parenthesised. Also, find the number of ways of using a minimum number of flips.

### Standard input

The first line contains a string consisting of parentheses.

### Standard output

Print two integers on the first line. The first integer should represent the minimum number of flips, while the second integer should represent the number of ways of doing it modulo $10^9 + 7$.

### Constraints and notes

The length of the string is an even integer between $2$ and $2500$

| Input | Output | Explanation |
| --- | --- | --- |
| (()))) | 1 3 | (())()(()())((())) |
| ))(( | 2 1 | The only way to achieve cost $2$ is  ()() |
| ()(())() | 0 1 | The string is correctly parenthesised |
| ()))(( | 2 2 | ()()()(())() |
