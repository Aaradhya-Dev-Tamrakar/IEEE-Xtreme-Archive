# Replace A

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/replace-a/](https://csacademy.com/contest/archive/task/replace-a/)  

---

You are given a string $S$ containing only letters A or B. You can take any two adjacent As and replace them by a single A. You perform operations as long as possible. Print the final string.

### Standard input

The first line contains the string $S$.

### Standard output

Print the final string on the first line.

### Constraints and notes

$S$ contains between $1$ and $100$ characters.

| Input | Output | Explanation |
| --- | --- | --- |
| AAABB | ABB | At the first step you can choose the first two As, obtaining AABB.At the second step, you can choose the only two adjacent As remaining, obtaining ABB.You cannot do any more operations on this string. |
