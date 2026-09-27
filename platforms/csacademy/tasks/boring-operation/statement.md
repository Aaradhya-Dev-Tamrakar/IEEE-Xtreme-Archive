# Boring Operation

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/boring-operation/](https://csacademy.com/contest/archive/task/boring-operation/)  

---

You are given an array $A$ with $N$ elements: $A_1, A_2, ..., A_n$, ($1 \leq A_i \leq 10^9$). You can perform the following operation as many times as you wish:

Choose an element $A_i$, and replace it with $10^9-A_i$.  

Let $V_{min}$ be the minimum value in the resulting array, and $V_{max}$ the maximum value. Your task is to perform the operation above as many times as you wish, in order to minimize $V_{max}-V_{min}$.

  

### Standard input

In the first line of the input there will be the number $N$, representing the size of the array. On the second line there will be $n$ integers, denoting the elements in the array.

  

### Standard output

You should output a single line with the  minimal value of $V_{max}-V_{min}$ that can be obtained using the operation above as many times as you wish.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 10^9$  

| Input | Output |
| --- | --- |
| 4<br>10 999999999 999999998 5 | 9 |
