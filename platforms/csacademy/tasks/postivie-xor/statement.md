# Positive Xor

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/postivie-xor/](https://csacademy.com/contest/archive/task/postivie-xor/)  

---

You are given an array $A$ of $N$ integers. Find the largest subarray having a strictly positive xor sum of the elements.

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ elements of the array.

### Standard output

Print the length of the subarray on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq A_i \leq 10^5$ It is guaranteed at least one subarray has positive xor sum.

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 1 1 1 | 3 | Take the first 3 ones or the last 3. |
| 4<br>1 0 0 1 | 3 | You can either take $[1, 0, 0]$ or $[0, 0, 1]$ |
| 4<br>0 5 3 8 | 4 | The xor value of the whole array is 14. |
