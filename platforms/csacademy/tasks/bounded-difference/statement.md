# Bounded Difference

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bounded-difference/](https://csacademy.com/contest/archive/task/bounded-difference/)  

---

You are given an array $A$ of $N$ integers. The array is valid if the absolute difference between any two adjacent elements is at most $K$. In other words, $|A_i - A_{i+1}| \leq K$, $1 \leq i < N$.

You are allowed to take any two elements and swap them. You can perform this operation at most one time. Decide whether it's possible to make the array $A$ valid.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

If there is no solution, output $-1$.

If $A$ is already valid, output $0$.

Otherwise, print two distinct integers representing the indices of the swapped elements.

### Constraints and notes

$2 \leq N \leq 10^5$ $0 \leq K \leq 10^9$ $0 \leq A_i \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1<br>1 3 2 4 | 1 4 | Swapping $\underline{1}\ 3\ 2\ \underline{4}$ gives $4\ 3\ 2\ 1$Also, swapping $1\ \underline{3}\ \underline{2}\ 4$ gives $1\ 2\ 3\ 4$ which is also a correct solution. |
| 7 3<br>1 2 10 4 7 5 8 | 3 6 |  |
| 4 2<br>1 2 3 4 | 0 | The initial array respects the problem's constraints. |
| 4 4<br>0 5 10 15 | -1 | There is no valid solution. The difference between any $2$ numbers is bigger than $4$ |
