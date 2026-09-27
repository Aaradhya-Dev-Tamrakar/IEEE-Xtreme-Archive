# Array Elimination

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/array-elimination/](https://csacademy.com/contest/archive/task/array-elimination/)  

---

You are given an array $A$ of $N$ integer, not necessarily distinct. You also have a pointer $p$ that initially points to the first element of the array. You are allowed to perform the following type of operations:

Increment $p$ to point to the next elementDecrement $p$ to point to the previous elementErase the element $p$ is currently pointing to. After the erase you must choose whether $p$ will point to the previous or the next element.

It is necessary to pop all the elements, in non-decreasing order. What's the minimum number of operations you need?

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of the array.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>2 1 3 3 2 | 8 | The underlined element represents the position of the pointer.$\underline{2}\ 1\ 3\ 3\ 2$ - increment pointer $2\ \underline{1}\ 3\ 3\ 2$ - erase the current element, set the pointer to be on the previous element$\underline{2}\ 3\ 3\ 2$ - erase the current element, set the pointer to be on the next element$\underline{3}\ 3\ 2$ - increment pointer$3\ \underline{3}\ 2$ - increment pointer $3\ 3\ \underline{2}$ - erase the current element, set the pointer to be on the previous element$3\ \underline{3}$ - erase the current element, set the pointer to be on the previous element$\underline{3}$ - erase the current element and end afterwards. The array is empty.The order in which the elements were popped is $[1, 2, 2, 3, 3]$ which is in non-decreasing order. |
| 4<br>1 2 3 4 | 4 | The operations are:erase and move righterase and move righterase and move righterase finish |
| 5<br>1 3 5 3 2 | 9 | The operations are:erase and move rightmove rightmove rightmove righterase and move lefterase and move leftmove lefterase and move righterase and finish |
| 7<br>3 3 2 1 2 2 3 | 10 | The operations are:move rightmove rightmove righterase and move righterase and move righterase and move lefterase and move righterase and move lefterase and move lefterase and finish |
