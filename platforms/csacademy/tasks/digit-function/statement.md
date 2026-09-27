# Digit Function

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/digit-function/](https://csacademy.com/contest/archive/task/digit-function/)  

---

You are given an integer $X$ and a function $F$ defined as:

$F(0) = 0$ $F(X) = F(X - \text{Sum of digits of X})$ 

Find out the number of times the function $F$ will be called for a given value of $X$.

### Standard input

The first line contains a single integer $X$.

### Standard output

The first line should contain the answer.

### Constraints and notes

$0 \leq X \leq 10^4$

| Input | Output | Explanation |
| --- | --- | --- |
| 9 | 2 | $f(9) = f(9 - 9)$$f(0) = 0$ |
| 10 | 3 | $f(10) = f(10 - 1)$$f(9) = f(9 - 9)$$f(0) = 0$ |
| 47 | 6 | $f(47) = f(47 - 4 - 7)$  $f(36) = f(36 - 3 - 6)$ $f(27) = f(27 - 2 - 7)$  $f(18) = f(18 - 1 - 8)$ $f(9) = f(9 - 9)$ $f(0) = 0$ |
