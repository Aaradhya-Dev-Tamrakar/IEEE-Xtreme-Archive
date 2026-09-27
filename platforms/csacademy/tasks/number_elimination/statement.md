# Number Elimination

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/number_elimination/](https://csacademy.com/contest/archive/task/number_elimination/)  

---

You are given an array of $N$ integers. On this array you can perform the following operation: choose two indices and eliminate the smaller value. In case the two values are equal the one with the smaller index is eliminated.

The cost of such an operation is equal to the greater value of the two. Note that in such an operation you are not allowed to choose an index of a number previously eliminated.

On this array you should perform $N-1$ operations until you are left with only one number. The total cost of the operations should be minimal. You have to count the number of sequences of operations that achieve the minimal cost. Two sequences of operations are considered different if there is an index $i$ for which the $i$th unordered pair of indices from one sequence is different than the $i$th pair in the other sequence.

### Standard input

The first line contains an integer $N$ representing the length of the array.

The second line contains the $N$ values of the array.

### Standard output

The output should contain a single number representing the number of sequences of operations that achieve minimal cost.

As this number can be very large, output its value modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are between $0$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 4 2 3 | 1 | There's only one way of achieving a minimum cost:Choose indices $1$ and $3$. The element at index $1$ is eliminated. The cost is $2$.Choose indices $3$ and $4$. The element at index $3$ is eliminated. The cost is $3$.Choose indices $2$ and $4$. The element at index $4$ is eliminated. The cost is $4$. |
| 6<br>3 1 8 1 5 8 | 6 |  |
| 12<br>3 9 0 7 0 7 9 0 7 9 7 3 | 4490640 |  |
