# Limited Swaps

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/limited-swaps/](https://csacademy.com/contest/archive/task/limited-swaps/)  

---

You are given an array of $N$ integers and another integer $K$. You are allowed to swap any two adjacent elements at most $K$ times. What's the largest lexicographical array you can get?

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Print on a single line the $N$ elements of the largest lexicographical array you can get.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq K \leq 5 * 10^9$ The elements of the array are integers between $0$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 2<br>1 3 2 4 | 3 2 1 4 | Initial array - $[1, 3, 2, 4]$Swap positions $1$ and $2$ - $[3, 1, 2, 4]$Swap positions $2$ and $3$ - $[3, 2, 1, 4]$ |
| 4 3<br>1 3 2 3 | 3 3 1 2 | Initial array - $[1, 3, 2, 3]$$[\underline{3}, \underline{1}, 2, 3]$$[3, 1, \underline{3}, \underline{2}]$$[3, \underline{3}, \underline{1}, 2]$ |
| 6 6<br>1 2 2 3 2 3 | 3 2 2 2 1 3 | Initial array - $[1, 2, 2, 3, 2, 3]$$[\underline{2}, \underline{1}, 2, 3, 2, 3]$$[2, \underline{2}, \underline{1}, 3, 2, 3]$$[2, 2, \underline{3}, \underline{1}, 2, 3]$$[2, \underline{3}, \underline{2}, 1, 2, 3]$$[\underline{3}, \underline{2}, 2, 1, 2, 3]$$[3, 2, 2, \underline{2}, \underline{1}, 3]$ |
| 6 7<br>1 2 2 3 2 3 | 3 3 1 2 2 2 | Initial array - $[1, 2, 2, 3, 2, 3]$$[1, 2, \underline{3}, \underline{2}, 2, 3]$$[1, \underline{3}, \underline{2}, 2, 2, 3]$$[\underline{3}, \underline{1}, 2, 2, 2, 3]$$[3, 1, 2, 2, \underline{3}, \underline{2}]$$[3, 1, 2, \underline{3}, \underline{2}, 2]$$[3, 1, \underline{3}, \underline{2}, 2, 2]$$[3, \underline{3}, \underline{1}, 2, 2, 2]$ |
