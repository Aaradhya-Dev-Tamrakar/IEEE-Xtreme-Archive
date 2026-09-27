# Set Subtraction

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/set-subtraction/](https://csacademy.com/contest/archive/task/set-subtraction/)  

---

You have a set $S$ of $N$ integers. You choose a positive value $X$ and subtract it from every element of $S$, obtaining other $N$ integers. Then you build an array $A$ of size $2*N$ with the initial elements and the resulting elements, in a random order.

Given $A$, find $X$ and the elements of $S$.

### Standard input

The first line contains a single integer $N$.

The second line contains $2*N$ integers representing the elements of $A$.

### Standard output

If there is no solution output $-1$.

Otherwise, print on the first line a single integer $X$.

On the second line print the $N$ elements of $S$.

If the solution is not unique you can output any of them.

### Constraints and notes

$1 \leq N \leq 1000$ $1 \leq A_i \leq 10^9$ $X$ should be positive

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>1 2 3 4 | 2<br>4 3 |  |
| 2<br>1 2 3 4 | 1<br>4 2 | Note that any solution is valid. Both $X = 1$ and $X = 2$ are valid. |
| 4<br>2 5 1 5 4 2 8 5 | 3<br>8 5 5 4 |  |
| 4<br>4 4 2 3 5 1 3 6 | 1<br>6 4 4 2 |  |
| 2<br>1 2 4 4 | -1 |  |
