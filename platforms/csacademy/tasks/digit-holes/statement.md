# Digit Holes

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/digit-holes/](https://csacademy.com/contest/archive/task/digit-holes/)  

---

When writing digits, some of them are considered to have holes: $0$, $6$ and $9$ have one hole, while $8$ has two holes. The other digits don't have any holes.

Given two integers $A$ and $B$, find a value in the interval $[A, B]$ that has the maximum total number of holes in its digits. If the solution is not unique, print the smallest one.

### Standard input

The first line contains two integers $A$ and $B$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$0 \leq A \leq B \leq 1000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 0 20 | 8 | $8$ is the first integer in $[0, 20]$ with $2$ holes. |
| 10 20 | 18 | $18$ is the only integer in $[10, 20]$ with $2$ holes. |
| 1 100 | 88 | $88$ is the only integer in $[1, 100]$ with $4$ holes. |
