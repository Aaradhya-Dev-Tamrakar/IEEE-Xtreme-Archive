# Histogram Partition

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/histogram-partition/](https://csacademy.com/contest/archive/task/histogram-partition/)  

---

You are given an array $A$ of $N$ positive integers. You have another array $B$ of size $N$ that initially contains only $0$s. You can perform the following type of operations:

Choose a subarray of $B$ having the property that all elements of the subarray are equal and increment the value of each element by any positive $x$. 

What's the minimum number of operations you need to make $B$ equal to $A$?

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 2 * 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>1 2 3 4 3 2 1 | 4 | We can do the following operations:add $1$ to $B_1 .. B_7$ add $1$ to $B_2 .. B_6$ add $1$ to $B_3 .. B_5$ add $1$ to $B_4 .. B_4$ |
| 5<br>3 2 1 1 2 | 4 | We can do the following operations:add $2$ to $B_1 .. B_2$ add $1$ to $B_1$ add $1$ to $B_3 .. B_5$ add $1$ to $B_5 .. B_5$ |
| 7<br>1 2 2 2 3 3 4 | 4 | We can do the following operations:add $1$ to $B_1 .. B_4$ add $1$ to $B_2 .. B_4$ add $3$ to $B_5 .. B_6$ add $4$ to $B_7 .. B_7$ |
| 9<br>3 4 2 1 1 4 5 6 3 | 8 | We can do the following operations:add $3$ to $B_1$ add $2$ to $B_2 .. B_3$ add $2$ to $B_2$ add $1$ to $B_4 .. B_5$ add $3$ to $B_6 .. B_9$ add $1$ to $B_6 .. B_7$ add $1$ to $B_7.. B_7$ add $3$ to $B_8.. B_8$ |
