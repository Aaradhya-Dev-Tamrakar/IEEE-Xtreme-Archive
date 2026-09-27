# Online XorMax

**Time Limit:** `2500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/online_xormax/](https://csacademy.com/contest/archive/task/online_xormax/)  

---

Alex has an array of $N$ integers. On this array he can perform the following operation: choose an element that was not previously chosen and mark it as unavailable. Alex wants to perform exactly $N$ operations, until all the elements are marked.

Alex defines the cost of a subarray as the xor value of all the elements in the subarray. Before performing an operation, Alex wants to know the maximum cost of a subarray that doesn't contain any unavailable elements.

### Standard input

The first line contains a single integer $N$, the length of the array.

The second line contains the $N$ values of the array.

The third line contains a permutation of size $N$, representing the indices of the elements chosen for the operations, in order.

### Standard output

The output should contain $N$ lines. On each line output a single integer, the answer before each operation.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are between $0$ and $10^9$The time limit is quite strict for Java or Python. We recommend C++ for this task.

| Input | Output | Explanation |
| --- | --- | --- |
| 10<br>169 816 709 896 58 490 97 254 99 796 <br>4 2 3 10 5 6 1 8 9 7 | 1008<br>992<br>992<br>992<br>490<br>490<br>254<br>254<br>99<br>97 | Initially, the largest xor value is determined by the subarray $(1, 9)$. After the first operation, the element at index $4$ becomes unavailable. The best subarray becomes $(7, 10)$. For the next updates the answers correspond to the following subarrays: $(7, 10)$, $(7, 10)$, $(6, 6)$, $(6, 6)$, $(8, 8)$, $(8, 8)$, $(9, 9)$ and $(7, 7)$. |
