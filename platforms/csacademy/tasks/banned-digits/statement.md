# Banned Digits

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/banned-digits/](https://csacademy.com/contest/archive/task/banned-digits/)  

---

You are given a set $S$ of banned digits.

How many numbers formed only of the digits $\{0, 1, 2, .., 9\} \setminus S$ are less than a given number $N$?

Note that numbers don't have leading $0$s and the number $0$ is a valid number.

Note that $N$ can contain banned digits.

### Trivia

Tetraphobia is the practice of avoiding instances of the number 4. It's not unheard for hotels in the East Asian nations to skip floors with the number 4 in them. Sometimes floor 13 is missing as well.

### Standard input

The first line contains $10$ binary values. The $i^{\text{th}} (0 \leq i \leq 9)$ one is $1$ if the digit $i$ is banned and $0$ otherwise.

The second line contains the number $N$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^{18}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 0 0 0 0 1 0 0 0 0 0<br>25 | 22 | The only banned digit is $4$. The banned numbers are:41424Note that $0$ is counted while $25$ is not (the numbers should be $< N$) |
| 0 0 0 0 1 0 0 0 0 0<br>51 | 37 | The only banned digit is $4$. The banned numbers are:414243440 .. 49In total there are 14 banned numbers. |
| 0 0 0 0 0 0 0 0 0 0<br>30 | 30 | No digit is banned. All numbers from $0$ to $29$ are valid. |
| 1 0 0 0 0 0 0 0 0 0<br>30 | 27 | The only banned digit is $0$. The banned numbers are:01020 |
| 0 0 1 0 0 0 0 0 0 0<br>30 | 18 | The only banned digit is $2$. The banned numbers are:21220 .. 29In total there are 12 banned numbers. |
