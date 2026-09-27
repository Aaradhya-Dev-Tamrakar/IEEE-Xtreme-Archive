# Balanced Number

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/balanced-number/](https://csacademy.com/contest/archive/task/balanced-number/)  

---

You are given a positive number $N$. We say the frequency of $c$ is equal to the number of digits of $N$ equal to $c$.

$N$ is balanced if the frequency of all $c$ ($0 \leq c \leq 9$) is the same. Decide whether $N$ is balanced or not.

### Standard input

The first line contains a single integer $N$.

### Standard output

If $N$ is balanced output $1$, otherwise output $0$.

### Constraints and notes

The number of digits of $N$ is between $1$ and $1000$ $N$ does not have leading zeroes, but $N$ can be 0

| Input | Output | Explanation |
| --- | --- | --- |
| 1234567890 | 1 | The number has all digits exactly once. |
| 12345678905 | 0 | $5$ occurs twice, while all the others only once. |
| 1337 | 0 | Several digits don't occur at all, for example $2$ or $9$. |
