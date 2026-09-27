# Boring Number

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/boring-number/](https://csacademy.com/contest/archive/task/boring-number/)  

---

You are given an array $A$ of $N$ integers. Find the index $i$ of an element such that the absolute difference between $A_i$ and the arithmetic mean of all the $N$ integers is minimum. If the solution is not unique, find the smallest index $i$.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of the array $A$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^3$ $1 \leq A_i \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 2 3 4 | 2 | The arithmetic mean of the numbers is $2.5$. The absolute difference between the mean and $A_2$ or $A_3$ is $0.5$, but you should output the smallest index. |
| 3<br>1 2 2 | 2 | The artihmetic mean is $1.(6)$, $A_2$ and $A_3$ have the minimum absolute difference of $0.(3)$ |
| 3<br>2 1 1 | 2 | The artihmetic mean is $1.(3)$, $A_2$ and $A_3$ have the minimum absolute difference of $0.(3)$ |
