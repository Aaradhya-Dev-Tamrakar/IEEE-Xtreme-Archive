# Min Pairing

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/min-pairing/](https://csacademy.com/contest/archive/task/min-pairing/)  

---

You have an array $A$ of $N$ integers, $N$ is always even. You should group the numbers in $N/2$ pairs. For each pair you calculate the absolute difference between the two elements. You want to minimize the sum of all the absolute differences.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers, the elements of $A$.

### Standard output

Print the minimum sum of the absolute differences on the first line.

### Constraints and notes

$2 \leq N \leq 1000$ $0 \leq A_i \leq 1000$ $N$ is even

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>5 10 10 15 | 10 | One way to make the pairs is $(5, 15)$ and $(10, 10)$The other one is $(5, 10)$ and $(10, 15)$Both of them minimize the required sum. |
| 6<br>1 3 3 7 4 7 | 3 | One way to make the pairs is $(1, 3)$, $(3, 4)$ and $(7, 7)$The other one is $(3, 3)$, $(1, 4)$ and $(7, 7)$Both of them minimize the required sum. |
