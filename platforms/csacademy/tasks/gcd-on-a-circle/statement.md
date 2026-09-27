# Gcd on a Circle

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/gcd-on-a-circle/](https://csacademy.com/contest/archive/task/gcd-on-a-circle/)  

---

You are given a circular array $A$ of $N$ positive integers. Find the number of ways of partitioning $A$ into subarrays such that the greatest common divisor of the numbers in each subarray is greater than $1$.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of $A$.

### Standard output

Print a single number, representing the number of valid partitions modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^5$ The values of the array are between $2$ and $10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>2 4 6 | 5 | The ways to partition are:$(2)\ (4)\ (6)$<br><br>$(2\ 4)\ (6)$<br><br>$(2)\ (4\ 6)$<br><br>$2)\ (4)\ (6$<br><br>$(2\ 4\ 6)$<br><br><br><br>$2)\ (4)\ (6$ means that $2$ and $6$ are in the same partition.This way is the same as $(4)\ (6\ 2)$ since the array is circular. |
| 4<br>2 2 10 5 | 6 | The ways to partition are:$(2)\ (2)\ (10)\ (5)$<br><br>$(2)\ (2\ 10)\ (5)$<br><br>$(2)\ (2)\ (10\ 5)$<br><br>$(2\ 2)\ (10)\ (5)$<br><br>$(2\ 2)\ (10\ 5)$<br><br>$(2\ 2\ 10)\ (5)$ |
| 4<br>2 2 3 3 | 4 | The ways to partition are:$(2)\ (2)\ (3)\ (3)$<br><br>$(2)\ (2)\ (3\ 3)$<br><br>$(2\ 2)\ (3)\ (3)$<br><br>$(2\ 2)\ (3\ 3)$ |
