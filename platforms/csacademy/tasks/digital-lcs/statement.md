# Digital LCS

**Time Limit:** `1000 ms`  
**Memory Limit:** `64 MB`  
**Source:** [https://csacademy.com/contest/archive/task/digital-lcs/](https://csacademy.com/contest/archive/task/digital-lcs/)  

---

Define $string(X)$ as the decimal notation of number $X$, without any leading zeroes. Define $LCS(s_1,s_2)$ as the longest common subsequence of strings $s_1$ and $s_2$. You are given a non-negative integer $X$, find a non-negative integer $Y$, such that  $Y \leq X$, and the length of $LCS(string(Y),string(X-Y))$ is maximum possible.

### Standard input

The first line contains one integer $T$, the number of test cases. $T$ lines follow, each of which contains one integer $X$.

### Standard output

For each test case,output one integer $Y$ in one line. In case multiple solution exists, output the minimum possible value of $Y$.

### Constraints and notes

$1 \leq T\leq 10$ $0  \leq X \leq 10^{16}$

| Input | Output |
| --- | --- |
| 3<br>50<br>33<br>1001 | 25<br>3<br>91 |
