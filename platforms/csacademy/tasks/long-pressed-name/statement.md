# Long Pressed Name

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/long-pressed-name/](https://csacademy.com/contest/archive/task/long-pressed-name/)  

---

In this problem there's a little girl who just learned to use the computer. One of the first things she wants to do is to write her name using the keyboard. As she is not experienced she may sometimes long press a key, so the character may appear on the screen more than once.

You are given a string $A$ representing the girl's name. You are also given another string $B$. Decide if $B$ can be the girl's name spelled using long presses.

### Standard input

The first line contains the string $A$.

The second line contains the string $B$.

### Standard output

If $B$ can be the girl's name spelled with long presses output $1$, otherwise output $0$.

### Constraints and notes

The length of the strings is a number between $1$ and $10^3$.The strings consist of lower case letters of the English alphabet.

| Input | Output | Explanation |
| --- | --- | --- |
| abc<br>abbccc | 1 | The underlined characters were created due to long pressing the keys$ab\underline{b}c\underline{c}\underline{c}$ |
| abba<br>aabaa | 0 | String $B$ contains only one character $'b'$ |
| aabbba<br>aaabbba | 1 | $aa\underline{a}bbba$ |
| ccxzzz<br>ccxzzz | 1 | The $2$ strings are equal. |
