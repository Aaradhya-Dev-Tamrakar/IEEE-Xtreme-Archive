# Alternant Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alternant-array/](https://csacademy.com/contest/archive/task/alternant-array/)  

---

You have a binary array $V$ of size $2 * N$ composed of $N$ values of $0$ and $N$ values of $1$. You can swap any two elements. What is the minimum number of swaps to make the array alternant? A binary array is /alternant/ if no two consecutive elements are equal.

### Standard input

The first line contains $N$.

The second line contains the $2 * N$ binary values of $V$.

### Standard output

Print the answer on the first line of the output.

### Constraints and notes

$1 \leq N \leq 10^4$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>0 0 0 1 1 1 | 1 | $0\ \underline{0}\ 0\ 1\ \underline{1}\ 1$$0\ 1\ 0\ 1\ 0\ 1$ |
| 4<br>0 1 1 0 1 0 0 1 | 2 | $\underline{0}\ \underline{1}\ 1\ 0\ 1\ 0\ 0\ 1$$1\ 0\ 1\ 0\ 1\ 0\ 0\ 1$$1\ 0\ 1\ 0\ 1\ 0\ \underline{0}\ \underline{1}$$1\ 0\ 1\ 0\ 1\ 0\ 1\ 0$ |
| 2<br>1 0 1 0 | 0 | The array is already alternant. |
