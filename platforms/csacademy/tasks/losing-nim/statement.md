# Losing Nim

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/losing-nim/](https://csacademy.com/contest/archive/task/losing-nim/)  

---

You have $N$ objects that you want to distribute in some non-empty piles. The number of piles can vary between $1$ and $N$.

For every possible number of piles, count the number of ways of distributing the objects such that the bitwise xor of the sizes of the piles is $0$.

The objects are indistinguishable from each other, but the piles are ordered. So the following two ways of distributing $6$ objects in $3$ piles: $[3, 1, 2]$ and $[1, 2, 3]$, are considered different and should be counted separately.

### Standard input

The first line contains two integers $N$ and $P$.

### Standard output

Print $N$ values, representing the answer for every possible number of piles modulo $P$.

### Constraints and notes

$1 \leq N \leq 500$ $2 \leq P < 2^{30}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2 10 | 0<br>1 | The only solution is $[1, 1]$ |
| 3 100 | 0<br>0<br>0 | There is no way to distribute the objects such that the bitwise xor of the sizes of the piles is $0$. |
| 4 666013 | 0<br>1<br>0<br>1 | The $2$ ways are $[2, 2]$ of size $2$ and $[1, 1, 1, 1]$ of size 4 |
| 6 1337 | 0<br>1<br>6<br>6<br>0<br>1 | Size 2: $[3, 3]$Size 3: $[1, 2, 3]$, $[1, 3, 2]$, $[2, 1, 3]$, $[2, 3, 1]$, $[3, 1, 2]$, $[3, 2, 1]$Size 4: $[1, 1, 2, 2]$, $[1, 2, 1, 2]$, $[1, 2, 2, 1]$, $[2, 1, 1, 2]$, $[2, 1, 2, 1]$, $[2, 2, 1, 1]$Size 6: $[1, 1, 1, 1, 1, 1]$ |
