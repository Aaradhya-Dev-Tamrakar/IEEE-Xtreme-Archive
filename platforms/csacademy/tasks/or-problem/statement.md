# Or Problem

**Time Limit:** `5000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/or-problem/](https://csacademy.com/contest/archive/task/or-problem/)  

---

You are given an array $A$ of $N$ integers. The cost of a subarray is defined as the bitwise or value of all its elements. Suppose you split the array into $K$ non-empty subarrays and you compute the sum of their costs. What is the maximum value you can get?

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing array $A$.

### Standard output

The first line will contain the maximal possible answer.

### Constraints and notes

$1 \leq K \leq N \leq 2 * 10^5$ $0 \leq A_i < 2^{20}$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 2<br>1 4 3 4 8 | 20 | Put the first $2$ elements in one subarray and the remaining $3$ in the other. The answer will be $(A_1 \text{OR}\ A_2) + (A_3 \ \text{OR}\ A_4 \ \text{OR}\ A_5) = 5 + 15 = 20$. |
