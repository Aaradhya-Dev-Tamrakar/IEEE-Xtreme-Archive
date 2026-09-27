# Array Removal

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/array-removal/](https://csacademy.com/contest/archive/task/array-removal/)  

---

Alex has an array of $N$ integers. On this array he can perform the following operation: choose an element that was not previously chosen and mark it as unavailable. Alex wants to perform exactly $N$ operations, until all the elements are marked.

Alex defines the cost of a subarray as the sum of all the elements in the subarray. Before performing an operation, Alex wants to know the maximum cost of a subarray that doesn't contain any unavailable elements.

### Standard input

The first line contains a single integer $N$, the length of the array.

The second line contains the $N$ values of the array.

The third line contains a permutation of size $N$, representing the indices of the elements chosen for the operations, in order.

### Standard output

The output should contain $N$ lines. On each line output a single integer, the answer before each operation.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are integers between $0$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>6 1 2 3 2<br>2 5 1 4 3 | 14<br>7<br>6<br>5<br>2 | Available elements - Max sum - Max sum subarray:$11111 - 14 - [1, 5]$$10111 - 7- [3, 5]$$10110 - 6 - [1, 1]$$00110 - 5 - [2, 3]$$00100 - 2 - [3, 3]$ |
| 6<br>8 3 4 1 5 10<br>1 4 6 3 2 5 | 31<br>23<br>15<br>7<br>5<br>5 | $111111 - 31 - [1, 6]$$011111 - 23 - [2, 6]$$011011 - 15 - [5, 6]$$011010 - 7 - [2, 3]$$010010 - 5 - [5, 5]$$000010 - 5 - [5, 5]$ |
