# And Closure

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/and-closure/](https://csacademy.com/contest/archive/task/and-closure/)  

---

You are given an array of $N$ integers. You can choose any subset of numbers and compute their binary and (operator $\&$ in some languages). Find the number of distinct results you can get.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of the array.

### Standard output

Output a single number representing the number of different results you can get.

### Constraints and notes

$1 \leq N \leq 10^5$The elements of the array are integers between $0$ and $10^6$.The chosen subset can be empty, and in this case we consider the and of the elements to be $0$.

| Input | Output |
| --- | --- |
| 4<br>1 3 6 7 | 6 |
| 4<br>23 54 39 23 | 8 |
