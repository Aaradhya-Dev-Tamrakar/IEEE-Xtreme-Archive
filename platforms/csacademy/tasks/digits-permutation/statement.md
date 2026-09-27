# Digits Permutation

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/digits-permutation/](https://csacademy.com/contest/archive/task/digits-permutation/)  

---

You are given two numbers, $A$ and $B$. You are allowed to permute the digits of $A$ to obtain another number $C$.

What is the greatest possible value of $C$, given that it must be less or equal to $B$?

Print $-1$ if there is no such value.

### Standard input

The first line contains two integers $A$ and $B$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq A, B < 10^9$ $C$ may not have leading zeros No digit may be discarded

| Input | Output |
| --- | --- |
| 1234 3456 | 3421 |
| 10000 5 | -1 |
| 789 123 | -1 |
