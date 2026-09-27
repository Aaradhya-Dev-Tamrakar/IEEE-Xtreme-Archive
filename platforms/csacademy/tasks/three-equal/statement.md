# Three Equal

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/three-equal/](https://csacademy.com/contest/archive/task/three-equal/)  

---

You are given an array $A$ of $N$ integers between $0$ and $2$. With cost $1$ you can apply the following operation $A_i = ((A_i + 1)\ \% \ 3)$.

Find the minimum cost to make all elements equal.

### Standard input

The first line contains one integer $N$.

The second line contains $N$ integers representing the elements of the array $A$.

### Standard output

Output a single number representing the minimum cost to make all elements of $A$ equal.

### Constraints and notes

$1 \leq N \leq 10^3$The elements of the array $A$ are integers between $0$ and $2$.

| Input | Output |
| --- | --- |
| 4<br>1 0 0 2 | 3 |
| 3<br>1 2 2 | 1 |
| 3<br>1 1 1 | 0 |
