# Binary Swaps

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/binary-swaps/](https://csacademy.com/contest/archive/task/binary-swaps/)  

---

You are given a binary array $A$ of size $N$. At each step all the elements $i$ and $i+1$ having the property that $A_i = 0$ and $A_{i+1}=1$ get swapped.

Print the array after $T$ steps.

### Standard input

The first line contains two integers $N$ and $T$.

The second line contains the $N$ elements of $A$.

### Standard output

Print $N$ integers on the first line, representing the array $A$ after $T$ steps.

### Constraints and notes

$1 \leq N, T \leq 10^6$

| Input | Output |
| --- | --- |
| 5 1<br>0 1 0 1 1 | 1 0 1 0 1 |
| 6 2<br>0 1 1 0 1 1 | 1 1 0 1 1 0 |
