# Final Index

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/final-index/](https://csacademy.com/contest/archive/task/final-index/)  

---

You have an array $A$ of size $N$. Initially, $A_i = i$, for all $1 \leq i \leq N$.

On this array you perform $M$ operations of two types:

Reverse a prefix of size $l$ Reverse a suffix of size $l$ 

You are interested in find the final index of a certain value $K$.

### Standard input

The first line contains three integers $N$, $M$ and $K$.

Each of the next $M$ lines contains two integers, describing an operation. The first integer is $0$ if we reverse a prefix, or $1$ if we reverse a suffix. The second integer is $l$, the length of the reversed prefix or suffix.

### Standard output

Print a single integer representing the final index of value $K$.

### Constraints and notes

$1 \leq K \leq N \leq 10^5$  $1 \leq M \leq 10^5$ $1 \leq l_i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3 4<br>0 4<br>1 4<br>0 3 | 3 | The array after each operation:$4\ 3\ 2\ 1\ 5$ $4\ 5\ 1\ 2\ 3$ $1\ 5\ 4\ 2\ 3$ |
| 7 2 2<br>0 6<br>1 5 | 5 | $6\ 5\ 4\ 3\ 2\ 1\ 7$ $6\ 5\ 7\ 1\ 2\ 3\ 4$ |
| 5 1 1<br>1 4 | 1 | $1\ 5\ 4\ 3\ 2$ |
