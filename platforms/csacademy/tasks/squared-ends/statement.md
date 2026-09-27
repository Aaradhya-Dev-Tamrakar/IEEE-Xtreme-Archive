# Squared Ends

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/squared-ends/](https://csacademy.com/contest/archive/task/squared-ends/)  

---

You are given an array $A$ of $N$ integers. The cost of a subarray $[A_l, A_{l+1},...A_r]$is equal to $(A_l -A_r)^2$.  Partition the array in $K$ subarrays having a minimum total cost.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

Print the minimum total cost on the first line.

### Constraints and notes

$1 \leq N \leq 10^4$ $1 \leq K \leq min(N, 100)$ $1 \leq A_i \leq 10^6$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 1<br>1 2 3 4 5 | 16 | The only partition is $[1, 5]$ with cost $(5 - 1)^2 = 16$ |
| 4 2<br>2 4 3 10 | 1 | The partitions is $[1, 3]$ and $[4, 4]$ |
| 11 3<br>2 4 1 5 3 4 3 5 7 100 100 | 5 | The $3$ partitions are$[2\ 4\ 1]\ [5\ 3\ 4\ 3\ 5\ 7]\ [100\ 100]$ |
