# Smallest Missing Numbers

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/smallest-missing-numbers/](https://csacademy.com/contest/archive/task/smallest-missing-numbers/)  

---

You're given an array of integers $A$ of size $N$ and an integer $M$. Find the sum of the smallest positive $M$ numbers that don't appear in array $A$.

### Standard input

The first line contains the integers $N$ and $M$, and the next line contains the $N$ elements of the array.

### Standard output

The first line should contain the required sum.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq M \leq 10^9$ $1 \leq A_i \leq 10^9, 1 \leq i \leq N$ Array $A$ contains distinct elements

| Input | Output | Explanation |
| --- | --- | --- |
| 3 1<br>1 2 3 | 4 | The missing number is $4$ |
| 5 5<br>9 8 5 4 2 | 27 | The missing numbers are $1$, $3$, $6$, $7$ and $10$.$1+3+6+7+10=27$ |
| 3 3<br>10 11 12 | 6 | The missing numbers are $1$, $2$ and $3$.$1 + 2 + 3 = 6$ |
