# Trailing Zeros

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/trailing-zeros/](https://csacademy.com/contest/archive/task/trailing-zeros/)  

---

You should guess a number $N$ by asking queries of the type:

For a chosen $X$, does $N!$ have at least $X$ trailing zeros?

### Interaction

You can start asking your queries right away. Each query should consist of the character Q followed be a number $X$.

After each query read the answer given by the interactor: $1$ if $N!$ has at least $X$ trailing zeros, or $0$ otherwise.

When you are done, print the character A followed by the answer. If the solution is not unique, print the smallest possible $N$.

### Constraints and notes

This task is NOT adaptive$5 \leq N \leq 10^5$$0 \leq X \leq 10^6$You can ask at most $20$ queries

InteractionQ 30Q 11Q 21A 10Q 21Q 70Q 51A 25
