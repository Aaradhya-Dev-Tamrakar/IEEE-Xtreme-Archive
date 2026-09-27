# Consecutive Remainders

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/consecutive-remainders/](https://csacademy.com/contest/archive/task/consecutive-remainders/)  

---

Gică seemed to enjoy problems with remainders, so he continued to pursue his interest. After several successfully solved problems, he started to praise with his knowledge. But, one day he met his girlfriend, Gigica, which had a very strange problem with remainders which troubled Gică. The problem sounds like:

Gigica is thinking at $N$ consecutive numbers. Furthermore, she computes all the remainders modulo $X$ of all the numbers. Finally, she adds up all these remainders and obtains a number $Y$. This is the point where Gică kicks in; he needs to find the largest remainder out of all possible ones.

After several tries, Gică couldn't resolve it on its own, so he is asking you to help him, not to embarrass in front of Gigica, after stating that he is "the best in problems with remainders".

### Standard input

The first and only line of the input contains $3$ positive integers $N$, $X$, $Y$.

### Standard output

The output should consist in one line with only one integer - the maximum possible remainder that can be obtained by dividing the $N$ numbers with $X$.

### Constraints and notes

$1 \leq N \leq 10^6$ $1 \leq X \leq 10^9$ $1 \leq Y \leq 10^{18}$ It is guaranteed that a solution exists, so the input data is correct.

| Input | Output | Explanation |
| --- | --- | --- |
| 4 2 2 | 1 | There can be multiple sequences chosen by Gina, but they either reduce to $[0, 1, 0, 1]$ or $[1, 0, 1, 0]$ (mod $X=2$). Both will result in $Y=2$, and the answer is $1$ (the maximum possible remainder). |
| 3 6 9 | 5 | There can be sequences like $[2, 3, 4]$ or $[4, 5, 0]$ (mod $6$) which add up to $9$. The maximum possible remainder is $5$ . |
| 3 7 9 | 4 | There can be only one sequence of $3$ numbers: $[2, 3, 4]$ (mod $7$) which add up to $9$. So the answer will be $4$ (the maximum remainder possible). |
