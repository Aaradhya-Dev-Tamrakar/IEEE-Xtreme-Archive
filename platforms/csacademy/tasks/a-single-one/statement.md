# A Single One

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/a-single-one/](https://csacademy.com/contest/archive/task/a-single-one/)  

---

You have an array of size $N$ where all the elements are equal to $0$, except for a single one that is equal to $1$ (let's denote this position by $S$). On this array you can perform the following type of operations:

Choose a subarray of size $K$ and reverse it.

You want to compute the minimum number of operations needed to bring the $1$ on every position of the array. You should be careful though, as there are $M$ forbidden positions, where the element equal to $1$ can never be.

### Standard input

The first line contains the four integers $N$, $K$, $M$ and $S$.

The second line contains $M$ integers representing the forbidden positions.

### Standard output

Output $N$ values representing the minimum numbers of operations needed to reach every position. In the case of forbidden positions, or the ones that can never be reached, output $-1$.

### Constraints and notes

$2 \leq N \leq 10^5$$2 \leq K \leq N$$0 \leq M \leq N-1$$1 \leq S \leq N$The initial position is not forbidden.

| Input | Output |
| --- | --- |
| 6 2 0 1 | 0 1 2 3 4 5 |
| 6 5 0 1 | 0 -1 2 -1 1 -1 |
| 10 4 3 3<br>2 5 10 | 2 -1 0 1 -1 1 2 3 2 -1 |
