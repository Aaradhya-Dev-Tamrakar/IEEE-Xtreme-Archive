# Partial Maximums

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/partial-maximums/](https://csacademy.com/contest/archive/task/partial-maximums/)  

---

You are given an array $V$ of length $N$. We'll call a position $1 \leq j \leq N$ a partial maximum if for any $1 \leq i \leq j - 1$ we have $V_i < V_j$. Suppose you erase exactly one element from the array; what is the maximum number of partial maximums that you can get?

### Standard input

The first line contains an integer $N$.

The second line contains $N$ integers, the $V$ array.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 2*10^5$ $1 \leq V_i \leq 10^9$ for any $1 \leq i \leq N$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 17 3 5 | 4 | We can erase the $3^{\text{rd}}$ element and every remaining element will be a partial maximum. |
| 11<br>9 3 7 1 8 12 12 20 15 18 5 | 5 | If we erase the first element, we'll have the following partial maximums:3 7 1 8 12 12 20 15 18 5 |
