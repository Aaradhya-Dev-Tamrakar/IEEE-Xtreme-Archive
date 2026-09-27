# Distinct Neighbours

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/distinct_neighbours/](https://csacademy.com/contest/archive/task/distinct_neighbours/)  

---

You are given an array of $N$ integers. You should permute the elments such that there will be no two adjacent equal elements. Count the number of distinct arrays you can obtain.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

The output should contain a single value representing the number of distinct arrays that can be obtained modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq
750$The values of the array are between $1$ and $N$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 1 2 3 | 6 | The 6 distinct permutations are:(1, 2, 1, 3), (1, 2, 3, 1), (1, 3, 1, 2), (1, 3, 2, 1), (2, 1, 3, 1), (3, 1, 2, 1) |
| 5<br>1 1 1 2 3 | 2 | The 2 distinct permutations are:(1, 2, 1, 3, 1), (1, 3, 1, 2, 1) |
| 6<br>1 1 1 2 2 2 | 2 | The 2 distinct permutations are:(1, 2, 1, 2, 1, 2), (2, 1, 2, 1, 2, 1) |
| 9<br>3 3 3 6 6 6 9 9 9 | 174 | <p> |
| 13<br>1 2 3 4 5 6 7 8 9 10 11 12 13 | 227020758 | All N! permutations are correct. The number is printed modulo 1 000 000 007. |
