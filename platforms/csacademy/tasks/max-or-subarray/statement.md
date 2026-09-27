# Max Or Subarray

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/max-or-subarray/](https://csacademy.com/contest/archive/task/max-or-subarray/)  

---

You are given an array $A$ of $N$ integers. Find the subarray for which the bitwise or of its elements is maximum. If the solution is not unique, we are interested in the shortest one.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of $A$.

### Standard output

Print the length of the subarray on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i < 2^{30}$ The subarray can't be empty

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>2 6 1 12 | 3 | The shortest subarray is $[6, 1, 12]$ having the or value $15$ |
| 4<br>1 2 4 8 | 4 | In order to have the maximum or value, we need to take all 4 elements. |
| 5<br>5 3 6 5 6 | 2 | Any subarray of size $2$ has the or value equal to $7$, which is the maximum one that can be obtained. |
