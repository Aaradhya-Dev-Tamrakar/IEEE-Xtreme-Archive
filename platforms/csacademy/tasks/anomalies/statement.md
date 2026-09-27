# Anomalies

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/anomalies/](https://csacademy.com/contest/archive/task/anomalies/)  

---

You are given an array $A$ of $N$ integers. An anomaly is a number for which the absolute difference between it and all the other numbers in the array is greater than $K$. Find the number of anomalies.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers, representing the $A$ array.

### Standard output

The first line should contain the number of anomalies.

### Constraints and notes

$1 \leq N, K \leq 100$ $1 \leq A_i \leq 1000$, for any $1 \leq i \leq N$ 

| Input | Output |
| --- | --- |
| 3 1<br>1 3 5 | 3 |
| 3 5<br>7 1 8 | 1 |
| 5 1<br>1 2 2 2 2 | 0 |
