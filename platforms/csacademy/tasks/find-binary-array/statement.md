# Find Binary Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/find-binary-array/](https://csacademy.com/contest/archive/task/find-binary-array/)  

---

You have a binary array of length $N$. For each index $i (1 \leq i \leq N)$ you know the number of zeroes among the positions on the left side of $i$ and on the right side of $i$, respectively. Find the array!

### Standard input

The first line contains an integer $N$, the length of the binary array.

The second line contains $N$ integer values, where the $i$-th value represents the number of zeroes among the positions on the left side of the $i$-th index of the array.

The third line contains $N$ integer values, where the $i$-th value represents the number of zeroes among the positions on the right side of the $i$-th index of the array.

### Standard output

The first line will contain $N$ bits ($0$ or $1$), representing the binary array.

### Constraints and notes

$2 \leq N \leq 10^5$ It is guaranteed that there is always at least one solution

| Input | Output |
| --- | --- |
| 5<br>0 1 1 1 2<br>1 1 1 0 0 | 01101 |
