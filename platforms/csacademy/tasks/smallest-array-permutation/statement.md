# Smallest Array Permutation

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/smallest-array-permutation/](https://csacademy.com/contest/archive/task/smallest-array-permutation/)  

---

You are given an array of $N$ integers. You should permute the elements of the array in such a way that:

There are no adjacent equal valuesThe resulting array is the smallest lexicographical one.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

If there is no solution output $-1$.

Otherwise, print the elements of the resulting array.

### Constraints and notes

$1\leq N \leq 10^5$ The elements of the array are integers in $[1, 10^5]$.

| Input | Output |
| --- | --- |
| 5<br>1 1 2 2 3 | 1 2 1 2 3 |
| 5<br>1 1 2 3 3 | 1 2 3 1 3 |
| 11<br>1 1 1 2 3 3 3 4 4 5 5 | 1 2 1 3 1 3 4 3 5 4 5 |
