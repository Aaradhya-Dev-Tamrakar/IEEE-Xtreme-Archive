# Fantastic 4

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fantastic-4/](https://csacademy.com/contest/archive/task/fantastic-4/)  

---

You have $4$ non-negative integers. You can perform the following type of operations:

Take one number and increment it by $2$, while decrementing the other three numbers by $1$. The operation can be performed only if the three numbers getting decremented are strictly positive.

Your goal is to maximise the maximum of the $4$ numbers.

### Standard input

The first line contains the four numbers.

### Standard output

Print the greatest maximum value you can obtain.

### Constraints and notes

The numbers are in the interval $[0, 10^9]$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 3 3 10 | 16 | The four numbers go through the following transformations:5 3 3 104 2 2 123 1 1 142 0 0 16 |
| 1 7 4 4 | 12 | 1 7 4 43 6 3 32 8 2 21 10 1 10 12 0 0 |
