# Binary Matching

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/binary_matching/](https://csacademy.com/contest/archive/task/binary_matching/)  

---

You are given two binary arrays $Text$ and $Pattern$. You can perform the following operation: choose two adjacent elements of $Text$ and swap them. You have to choose a series of operations in order to maximize the number of matchings of $Pattern$ in $Text$. A matching is a subarray of $Text$ equal to $Pattern$.

Compute the maximum possible number of matchings. Also compute the minimum number of operations needed to achieve a maximum number of matchings.

### Standard input

The first line contains the binary string $Text$.

The second line contains the binary string $Pattern$.

### Standard output

The output should contain two values: the maximum number of possible matchings and the minimum number of operations needed to achieve it..

### Constraints and notes

The length of both $Text$ and $Pattern$ will be between $1$ and $500$.

| Input | Output | Explanation |
| --- | --- | --- |
| 01100<br>010 | 2 1 | By swapping just the second and third bits, we obtain string $1010101$, in which $010$ is matched twice. |
| 000111<br>1100 | 1 4 | With four swaps, we can obtain string $011001$ in which $1100$ occurs once. There is no better solution. |
