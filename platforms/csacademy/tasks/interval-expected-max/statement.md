# Interval Expected Max

**Time Limit:** `4000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/interval-expected-max/](https://csacademy.com/contest/archive/task/interval-expected-max/)  

---

You are given an array $v$ of $N$ integers and $Q$ queries. Each query consists of two values $l$ and $r$. You are supposed to choose randomly two elements from the subarray $v_l, v_{l+1},..., v_{r-1}, v_r$ (the same element can be chosen twice). Compute the expected value of the maximum of the two chosen elements.

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains the $N$ elements of $v$.

Each of the following $Q$ lines contains two integers $l$ and $r$.

### Standard output

You should output $Q$ lines, each containing the answer for a query.

### Constraints and notes

$1 \leq N \leq 10^5$$1 \leq Q \leq 10^5$$1 \leq l \leq r \leq N$The values of $v$ are integers between $1$ and $10^5$Your results should differ from the official ones by less than $10^{-6}$ with absolute precision.

| Input | Output |
| --- | --- |
| 7 4<br>1 1 1 2 3 1 10<br>5 7<br>1 7<br>2 5<br>1 3 | 6.6666667<br>4.0204082<br>2.1875000<br>1.0000000 |
