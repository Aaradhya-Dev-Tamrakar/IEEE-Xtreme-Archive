# Expected Max

**Time Limit:** `4000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/expected-max/](https://csacademy.com/contest/archive/task/expected-max/)  

---

Mike has an array $A$ of length $N$. Initially all the elements in the array are equal to $0$.

Mike is playing a game consisting of $M$ steps. At each step he will choose exactly one cell. At step $i$ he will choose cell number $j$ with probability $\frac{p_{1,i,j} + p_{2,i,j} + p_{3,i,j}}{10^6}$ and increase $a_j$ by $1$ with probability $\frac{p_{1,i,j}}{10^6}$, by $2$ with probability $\frac{p_{2,i,j}}{10^6}$ and by $3$ with probability $\frac{p_{3,i,j}}{10^6}$.

For every $i$ it is guaranted that $\sum_{j = 1}^{N} \frac{p_{1,i,j} + p_{2,i,j} + p_{3,i,j}}{10^6} = 1$.

At the end of $M^{th}$ step Mike will calculate value of $\text{max}(a_1, a_2, ... , a_N)$. He wants to find its expected value, help him to calculate it.

Let this value be representable in the form of an irreducible fraction $\frac{P}{Q}$. You need to calculate $P * Q^{-1}$ modulo $10^9 + 7$.

### Standard input

The first line contains two integers $N$ and $M$.

The next $3$ blocks contain $M$ lines with $N$ integers each representing values of $P_{k,i,j}$ ( $1 \leq k \leq 3,1 \leq i \leq M,1\leq j \leq N$ ).

### Standard output

On the first line print a number equal to $P * Q^{-1}$ modulo $10^9 + 7$.

### Constraints and notes

$1 \leq N \leq 20$ $1 \leq M \leq 10$ $0 \leq p_{k,i,j} \leq 10^6$ ( $1 \leq k \leq 3,1 \leq i \leq M,1\leq j \leq N$ )

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>250000 500000 250000<br>100000 200000 700000<br>0 0 0<br>0 0 0<br>0 0 0<br>0 0 0 | 100000002 | There are 2 steps and on each step there is a non-zero chance to add 1 to either of 3 cells. Maximum will be 2 with a chance of 0.25 * 0.1 + 0.5 * 0.2 + 0.25 * 0.7 = 0.3, otherwise it will be 1. So the expected value is 1 * 0.7 + 2 * 0.3 = 1.3 or 13 / 10. |
| 1 1<br>84116<br>353080<br>562804 | 931616009 |  |
| 1 2<br>99589<br>541806<br>243600<br>11934<br>656811<br>446260 | 648332009 |  |
