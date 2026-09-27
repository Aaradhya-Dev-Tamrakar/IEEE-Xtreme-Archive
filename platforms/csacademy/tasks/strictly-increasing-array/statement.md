# Strictly Increasing Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/strictly-increasing-array/](https://csacademy.com/contest/archive/task/strictly-increasing-array/)  

---

You are given an array $V$ of $N$ integers. Suppose you are allowed to change an element into any integer with one operation. Find the minimum number of operations to make the array strictly increasing.

### Standard input

The first line contains an integer $N$.

The second line contains $N$ integers denoting $V$.

### Standard output

Print the answer on the first line of the output.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq V_i \leq 10^9$ for $1 \leq i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 2 3 6 | 2 | By changing the underlined elements the array becomes Strictly Increasing$1\ 2\ \underline{2}\ \underline{3}\ 6$$1\ 2\ 3\ 5\ 6$ |
| 3<br>1 1 1 | 2 | $\underline{1}\ 1\ \underline{1}$$-10\ 1\ 9$Note that the elements can become $<1$It's guaranteed that the initial values are between $1$ and $10^9$ |
| 6<br>4 2 4 4 6 8 | 2 | $\underline{4}\ 2\ 4\ \underline{4}\ 6\ 8$$1\ 2\ 4\ 5\ 6\ 8$ |
