# Letters Deque

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/letters-deque/](https://csacademy.com/contest/archive/task/letters-deque/)  

---

You have a string $S$ that is initially empty. You perform $Q$ operations of the type:

Add a character $c$ to the front or the back of $S$.

Print the final string.

### Standard input

The first line contains a single integer $Q$.

Each of the next $Q$ lines contains an integer $a$ and and a character $c$. The integer $a$ if $0$ is $c$ is added to the front of $S$, and $1$ if $c$ is added to the back of $S$.

### Standard output

Print the final string on the first line.

### Constraints and notes

$1 \leq Q \leq 1000$ $c$ is a lowercase letter of the English alphabet

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>1 d<br>0 c<br>0 b<br>1 e<br>1 f<br>0 a | abcdef | After each operation, the string will be:dcdbcdbcdebcdefabcdef |
| 6<br>0 c<br>0 b<br>0 a<br>1 d<br>1 e<br>1 f | abcdef | After each operation, the string will be:cbcabcabcdabcdeabcdef |
| 6<br>1 e<br>0 d<br>0 c<br>0 b<br>0 a<br>1 f | abcdef | After each operation, the string will be:edecdebcdeabcdeabcdef |
