# Strange Transformation

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/strange-transformation/](https://csacademy.com/contest/archive/task/strange-transformation/)  

---

You are given a number $A$ and $2$ operation. Each operation allows you to change $A$ in the following ways:

multiply $A$ by $3$.divide $A$ by $2$. This operation can only be performed if $A$ is even.

You performed some operations and wrote down the values of $A$ after each of them. An example of such operations is the following: $24, 12, 6, 18, 54, 27, 81$. The problem is that you don't remember all the values, but you're sure you remember the following:

the initial value of $A$.the final value of $A$, denoted with $B$.some other values, but you're not sure about their order.

Given $A$ and $B$, the initial and final values and $N$ values in an arbitrary order, construct a sequence of integers such that the first value is $A$, the final value is $B$ and each of the $N$ other values appear in the sequence.  A sequence is considered valid if it can be achieved with the $2$ operations.

Any valid solution is accepted. If there is no valid sequence, print $-1$.

### Standard input

The first line contains $3$ integers, $N$, $A$ and $B$.

The second line contains an array $X$ with $N$ integers representing the additional values.

### Standard output

The first line should contain a valid sequence of integers. If there is no such sequence, print $-1$.

### Constraints and notes

$0 \leq N \leq 50$ $1 \leq A \leq 10^9$ $1 \leq B \leq 10^9$ $A \neq B$ 

For each of the additional $N$ values denoted by the array $X$ the following constraints are valid:

$1 \leq X_i \leq 10^9$ $A \neq X_i, B \neq X_i$ $X_i \neq X_j, i \neq j$ 

| Input | Output |
| --- | --- |
| 2 24 81<br>18 6 | 24 12 6 18 54 27 81 |
| 0 8 9 | 8 4 2 1 3 9 |
| 0 2 5 | -1 |
| 2 8 9<br>36 12 | 8 4 12 36 18 9 |
