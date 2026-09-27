# Array Coloring

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/array_coloring/](https://csacademy.com/contest/archive/task/array_coloring/)  

---

Alex has an array of size $N$. Initially all the cells of the array are white. Alex performs $M$ operations of the form: choose a non-empty subarray and paint all the cells in a color identified by a number between $1$ and $M$.

The colors used are pairwise distinct, so each color will appear in exactly one operation. In the end, there are no white cells left.

Suppose we identify the cell that was painted most often. The cost of the entire process is equal to the number of times this cell was painted. You want to reconstruct Alex's operations in a way that will maximize the cost.

## Standard input

The first line contains two integer values $N$ and $M$.

The second line contains $N$ integer values between $1$ and $M$, representing the colors of the cells at the end of the process.

## Standard output

The output should contain a single integer value representing the maximum possible cost.

## Constraints and notes

$1 \leq N, M \leq 10^5$

| Input | Output |
| --- | --- |
| 7 4<br>1 2 3 2 1 4 1 | 3 |
| 6 4<br>1 2 3 2 4 1 | 4 |
| 10 7<br>1 2 3 1 4 5 6 5 7 4 | 5 |
