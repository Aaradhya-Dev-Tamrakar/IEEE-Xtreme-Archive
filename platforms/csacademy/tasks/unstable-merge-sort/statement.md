# Unstable Merge Sort

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/unstable-merge-sort/](https://csacademy.com/contest/archive/task/unstable-merge-sort/)  

---

Given an array $A$ of size $N$ with elements indexed from $1$ to $N$ we apply merge sort to it. Below is it's pseudocode. Note thatrnd() returns either true or false randomly and equiprobably.

1  ההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

The main feature of this merge sort is that when it encounters equal elements on the left and the right side, it always chooses one of them randomly and equiprobably. The choices are independent.

Your task is for each element of the initial array to find the expected value of index of it's position in the sorted array (after calling merge_sort(A, 1, N)).

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing elements of $A$.

### Standard output

Print $N$ lines, $i^{th}$ line should contain expected value of index of element $A[i]$ in the sorted array.

### Constraints and notes

$1 \leq N \leq 600$ Elements of $A$ are integers between $1$ and $N$ The answer will be considered correct if it's absolute error does not exceed $10^{-6}$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>3 2 1 2 | 4.000000000000000<br>2.500000000000000<br>1.000000000000000<br>2.500000000000000 | Both of the $2$'s may end up either on position 2 or 3. |
| 3<br>3 3 3 | 2.125000000000000<br>2.125000000000000<br>1.750000000000000 | Here first happens the merge of the first two elements, then the merge of segments [1,2] with [3,3].After the last merge element $3$ will end up at position $1$ with a chance of 50%, at positions $2$ and $3$ with a chance of 25% each.The remaining $2$ elements will be placed on the remaining two positions equiprobably. |
