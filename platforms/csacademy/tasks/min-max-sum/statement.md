# Min Max Sum

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/min-max-sum/](https://csacademy.com/contest/archive/task/min-max-sum/)  

---

You are given an array $A$ of $N$ integers. Consider all the possible partitions of $A$ into subarrays (there are $2^{N-1}$ partitions).

We define the cost $F$ of a subarray $A_{[i, j]}$ to be $\text{min}(A_i, A_{i+1},...,A_j) * \text{max}(A_i, A_{i+1},...,A_j)$. The cost $G$ of a partition is the sum of $F$ for all its subarrays.

Print the sum of $G$ for all $2^{N-1}$ partitions.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of $A$.

### Standard output

Print the answer modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 10^9$

| Input | Output |
| --- | --- |
| 5<br>2 4 1 3 5 | 478 |
