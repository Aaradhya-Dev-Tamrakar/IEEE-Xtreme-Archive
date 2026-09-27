# Restricted Arrays

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/restricted-arrays/](https://csacademy.com/contest/archive/task/restricted-arrays/)  

---

You are given an array $A$ of size $N$ and an integer $K$. How many arrays $B$ can you build such that:

$\text{max}(B_i)$ is minimum$B_i > 0$ For any two indices $i$ and $j$,  $|i - j| < K$: $B_i = B_j$ if $A_i = A_j$ and $B_i \neq B_j$ if $A_i \neq A_j$ 

### Standard input

The first line contains integers $N$ and $K$.

The next line contains $N$ integers, the elements in array $A$.

### Standard output

The first line should contain the answer modulo $10^9+7$.

### Constraints and notes

$1 \leq K \leq N \leq 10^5$ $1 \leq A_i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1<br>1 3 2 3 | 1 | The only array which satisfies the conditions is $[1, 1, 1, 1]$.$max(B_i) = 1$ |
| 4 2<br>2 1 2 2 | 2 | The $2$ arrays are:$[1, 2, 1, 1]$ $[2, 1, 2, 2]$ $max(B_i) = 2$ |
| 7 3<br>1 2 1 3 4 1 4 | 6 | The $6$ arrays are:$[1,	2,	1,	3,	2,	1,	2]$ $[1,	3,	1,	2,	3,	1,	3]$ $[2,	1,	2,	3,	1,	2,	1]$ $[2,	3,	2,	1,	3,	2,	3]$ $[3,	1,	3,	2,	1,	3,	1]$ $[3,	2,	3,	1,	2,	3,	2]$ $max(B_i) = 3$ |
