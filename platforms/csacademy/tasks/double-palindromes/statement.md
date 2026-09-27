# Double Palindromes

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/double-palindromes/](https://csacademy.com/contest/archive/task/double-palindromes/)  

---

Do you like the problems with a very long story? If yes, then this problem is not for you.

You are given a string $S$ of $N$ lowercase English letters. Let's denote by $A^r$ the reverse of string $A$. Compute the number of substrings of $S$ of the form $AA^rA$.

In other words, compute the number of pairs $(i,j)$ with the following properties:

$1\leq i \leq j \leq N$ There exists a string $A$ such that $S_{i..j} = AA^rA$ 

### Standard input

The input consists of a single line containing the string $S$.

### Standard output

Print a single number representing the number of substrings with the given property.

### Constraints and notes

$1\leq N\leq 2\cdot 10^6$ 

It is guaranteed that $S$ consists only of lowercase English letters.

| Input | Output | Explanation |
| --- | --- | --- |
| aaab | 1 | The substring consisting of the first 3 letters has the required properties. |
| xyyxxy | 1 | The whole string has the required properties, with $A = xy$ |
| aaaa | 2 | The two strings that have the required properties are the first 3, respectively the last 3 letters. Note that the substrings can overlap. |
