# Subsequence Queries

**Time Limit:** `1500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subsequence-queries/](https://csacademy.com/contest/archive/task/subsequence-queries/)  

---

You are given a string $S$ and $Q$ queries. For each query you are given two values $l$ and $r$. You should find the number of distinct subsequences of the substring $S_l, S_{l+1},...\ S_r$.

### Standard input

The first line contains the string $S$.

The second line contains a single integer $Q$.

Each of the next $Q$ lines contains two integers $l$ and $r$.

### Standard output

Print $Q$ lines, each containing the answer for a query modulo $10^9+7$.

### Constraints and notes

The length of $S$ is between $1$ and $3 * 10^4$ $1 \leq Q \leq 10^5$ $1 \leq l_i \leq r_i \leq |S|$ $S$ contains only letters from a to i (9 letters)

| Input | Output |
| --- | --- |
| aaccbb<br>5<br>1 6<br>3 4<br>2 5<br>1 4<br>3 6 | 26<br>2<br>11<br>8<br>8 |
| aabababb<br>5<br>1 8<br>1 4<br>3 5<br>5 7<br>3 8 | 63<br>9<br>6<br>6<br>27 |
