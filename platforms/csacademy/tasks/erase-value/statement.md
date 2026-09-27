# Erase Value

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/erase-value/](https://csacademy.com/contest/archive/task/erase-value/)  

---

You are given an array $A$ of $N$ positive integers. You can choose any positive value $x$ and erase all the elements of $A$ equal to $x$. In the end you want the sum of the elements of the array to be as small as possible.

### Standard input

The first line contains a single integer $N$.

The second lint contains $N$ integers representing the elements of $A$.

### Standard output

Print the resulting sum on the first line.

### Constraints and notes

$1 \leq N \leq 1000$ $1 \leq A_i \leq 1000$ The sum of elements of an empty array is $0$.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>3 2 2 2 5 | 8 | Erase $2$ in order to make the sum as small as possible $3 + 5 = 8$ |
| 5<br>1 2 1 4 2 | 6 | Erase $2$ in order to make the sum $1 + 1 + 4 = 6$ Or erase $4$ in order to make the sum $1 + 1 + 2 + 2 = 6$ |
