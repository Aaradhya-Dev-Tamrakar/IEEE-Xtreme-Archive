# Three Ones

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/three-ones/](https://csacademy.com/contest/archive/task/three-ones/)  

---

You are given a binary string of size N. You should find the minimum value K such that any substring of length K contains at least $3$ values of 1.

### Standard input

The first line contains a single integer $N$.

The second line contains the binary string of size $N$.

### Standard output

Print the answer on the first line

### Constraints and notes

$3 \leq N \leq 5 *10^5$ It is guaranteed the string contains at least $3$ values of 1

| Input | Output | Explanation |
| --- | --- | --- |
| 10<br>0100011010 | 7 | For a value of $K = 6$ the following substring will not contain at least $3$ ones.0100011010..000110.. |
| 5<br>10011 | 5 | 100111001. |
| 12<br>101001001011 | 8 | 101001001011.0100100.... |
