# Cuinelo

**Time Limit:** `1000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cuinelo/](https://csacademy.com/contest/archive/task/cuinelo/)  

---

Alex received as a gift for his birthday two integer arrays: $a$ (of length $m$) and $b$ (of length $n$). Everybody knows that Alex likes inversions! That's why he wants to merge $a$ and $b$ in such a way that he will obtain a new array $c$ with as many inversions as possible.

By merging two arrays $a$ and $b$, Alex refers to the process of applying the following operation a number of $m + n$ times: We remove the first element of either $a$ or $b$ (at our choice) and we append it to the end of $c$.

Alex realised that $a$ and $b$ can be merged in too many ways, so he asks you to determine the maximum number of inversions of any array $c$ that can be obtained by merging $a$ and $b$.

### Standard input

The first two lines contain the number $m$ and, respectively, $m$ positive integers, representing the elements of $a$.

The next two lines contain the number $n$ and, respectively, $n$ positive integers, representing the elements of $b$.

### Standard output

The output contains a single number – the maximum number of inversions that $c$ can have.

### Constraints and notes

$1 \le m, n \le 5\,000$ $1 \le a_i \le 10^9, i = \overline{1, m}$ $1 \le b_j \le 10^9, j = \overline{1, n}$ For an array $v$, of length $k$, the pair $(i, j)$ is called an inversion if $1 \le i \lt j \le k$ and $v_i \gt v_j$.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>5 6 8 5 4<br>3<br>7 1 3 | 22 | A possible configuration of $c$ with the maximum number of inversions ($22$) is $\langle 7, 5, 6, 8, 5, 4, 1, 3 \rangle$. |
