# Adaptive Binary Search

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/adaptive-binary-search/](https://csacademy.com/contest/archive/task/adaptive-binary-search/)  

---

You are given an integer $N$. The interactor chooses a number $X$ between $1$ and $N$. Your task is to find $X$.

Your queries consist of a single integer $Y$. The interactor answers $0$ if $X \leq Y$, and $1$ if $X > Y$.

### Interaction

First you should read a single integer $N$.

Then you can start asking queries. Each query consists of the letter Q followed by a single integer $Y$. The letter and the integer should be separated by a single space.

After each query you can read the answer ($0$ or $1$).

When you found the solution output A followed by the value of $X$. The letter and the integer should be separated by a single space.

Warning: Don't forget to add a newline before flushing the output.

### Constraints and notes

This task is adaptive$2 \leq N \leq 10^6$You pass the tests if the number of queries is $\leq \lceil\log N\rceil$.

Interaction7Q 40Q 21Q 31A 4
