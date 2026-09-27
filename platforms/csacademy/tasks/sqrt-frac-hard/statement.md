# Square Root Frac (Hard)

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sqrt-frac-hard/](https://csacademy.com/contest/archive/task/sqrt-frac-hard/)  

---

This task is identical to Square Root Frac (Easy), except for having larger restrictions.

In the post-quantum computing world, there's a lot of research going on to develop encryption and hashing algorithms that can't be cracked by a quantum computer easily. Your local government is planning to use the $sqrtFrac$ function. That is:

$sqrtFrac(x) = \lfloor \{ \sqrt x \} * 10^{18} \rfloor$, where $\{x\}=x-\lfloor x\rfloor$, i.e. the fractional part of x, meaning the values after the decimal dot.

For example $\sqrt 3 = 1.7320508075688772935274...$, and $sqrtFrac(3) = 732050807568877293$

You're a great hacker, and you need to show them that their hashing function can be easily reversed. That is, by knowing the sqrtFrac of a number between $1$ and $10^{18}$, find out what that number is.

### Standard input

There are multiple test cases in the input. The first line in the input contains the number $T$, and the next $T$ lines each contain a single number, the $sqrtFrac$ value of a number you must calculate.

### Standard output

You should output $T$ lines, representing the solutions for the given numbers.

### Constraints and notes

$1 \leq T \leq 4$ If there are multiple numbers that have the same $sqrtFrac$, any of them is considered a valid solution. 

| Input | Output |
| --- | --- |
| 3<br>414213562373095048<br>732050807568877293<br>49875621120890270 | 2<br>3<br>101 |
