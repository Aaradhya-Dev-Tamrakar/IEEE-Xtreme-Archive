# Borland

**Time Limit:** `6000 ms`  
**Memory Limit:** `3000 KB`  
**Source:** [https://csacademy.com/contest/archive/task/borland/](https://csacademy.com/contest/archive/task/borland/)  

---

This problem has an unusual memory limit!

You are given an array $V$ of $N$ integers. For every possible subarray, consider the maximum value in the subarray. Find the sum of these values.

### Standard input

Instead of reading the array itself, the first line will contain $5$ integers $N$, $S$, $A$, $B$, $C$.

The array $V$ is defined as follows:

$V_1 = S$ $V_{i+1} = (A * V_i + B)\  \text{mod}\ C$, for any $1 \leq i < N$ 

### Standard output

On the first line print the answer modulo $10^9 + 7$.

### Constraints and notes

$1 \leq N \leq 3* 10^6$ $2 \leq C < 2^{30}$, $C$ is prime$1 \leq S, A, B < C$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2 3 18 67 | 121 | $V = [2, 24, 23]$For $[1, 2]$, the maximum value is $\text{max}(2, 24)=24$.For $[2, 3]$, the maximum value is $\text{max}(24, 23)=24$.For $[1, 3]$, the maximum value is $\text{max}(2, 24, 23)=24$.Therefore, the answer is $2 + 23 + 24 + 24 + 24 + 24 = 121$. |
