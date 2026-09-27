# Prime Distance

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/prime-distance/](https://csacademy.com/contest/archive/task/prime-distance/)  

---

You are given two integers $A$ and $B$. A step consists of one of the following two operations:

Multiply $A$ by any prime.Divide $A$ by one of its prime divisors.

Find the minimum number of steps needed to make $A$ equal to $B$.

### Standard input

The first line contains two integers $A$ and $B$.

### Standard output

Print a single integer representing the minimum number of steps needed.

### Constraints and notes

$1 \leq A, B \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 10 15 | 2 | Divide by $2$ and multiply by $3$.$10 / 2 = 5$$5 * 3 = 15$ |
| 9 7 | 3 | Divide by $3$, multiply by $7$ and divide by $3$.$9 / 3 = 3$$3 * 7 = 21$$21 / 3 = 7$ |
