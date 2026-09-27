# Sliding Product Sum

**Time Limit:** `4000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sliding-product-sum/](https://csacademy.com/contest/archive/task/sliding-product-sum/)  

---

Given an integer $N$, we build an array $A = [1, 2, 3, ..., N]$. For each subarray of length less than or equal to $K$, compute the product of the subarray's elements. Output the sum of these products, modulo $M$.

### Standard input

The first line contains three integers $N$, $K$ and $M$.

### Standard output

Print the answer on the first line

### Constraints and notes

$1 \leq N \leq 10^{18}$ $1 \leq K \leq \text{min}(600, N)$ $1 \leq M \leq 10^{18}$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3 100 | 45 | The answer before begin truncated modulo $100$ was $145$. |
| 10 5 666013 | 68893 |  |
