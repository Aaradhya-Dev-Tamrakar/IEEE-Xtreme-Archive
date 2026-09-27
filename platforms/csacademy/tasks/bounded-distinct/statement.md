# Bounded Distinct

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bounded-distinct/](https://csacademy.com/contest/archive/task/bounded-distinct/)  

---

You are given an array of $N$ integers. Find the number of subarrays having a length between $L$ and $R$ that contain only distinct elements.

### Standard input

The first line contains three integers $N$, $L$ and $R$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq L \leq R \leq N \leq 10^5$ The elements of the array are integers between $0$ and $10^9$

| Input | Output |
| --- | --- |
| 5 2 4<br>1 2 1 3 4 | 7 |
| 5 1 3<br>1 2 1 2 1 | 9 |
| 6 2 2<br>1 2 1 3 1 3 | 5 |
