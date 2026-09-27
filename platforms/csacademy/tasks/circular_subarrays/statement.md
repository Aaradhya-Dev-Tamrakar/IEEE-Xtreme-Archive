# Circular Subarrays

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/circular_subarrays/](https://csacademy.com/contest/archive/task/circular_subarrays/)  

---

You are given a circular array of size $N$ and an integer $K$. On this array, you can perform operations of incrementing or decrementing an element. The cost of such an operation is $1$. You can perform more than one operation on a single element.

You want each subarray of length $K$ to have the same sum of elements. Compute the minimum cost needed to achieve this.

### Standard input

The first line contains two integer values $N$ and $K$.

The second line contains $N$ integers, the values of the array.

### Standard output

The output should contain a single integer value representing the minimum cost needed.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq K \leq N$The values of the array are between ${-10\ 000}$ and $10\ 000$The array is circular, so there are always exactly $N$ subarrays of length $K$.

| Input | Output |
| --- | --- |
| 10 1<br>1 2 3 4 5 6 7 8 9 10 | 25 |
| 10 2<br>1 6 2 7 3 8 4 9 5 10 | 12 |
| 9 3<br>1 4 7 2 5 8 3 6 9 | 6 |
| 10 10<br>1 2 3 4 5 6 7 8 9 10 | 0 |
