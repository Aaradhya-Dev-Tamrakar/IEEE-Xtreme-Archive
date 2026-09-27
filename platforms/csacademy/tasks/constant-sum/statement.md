# Constant Sum

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/constant-sum/](https://csacademy.com/contest/archive/task/constant-sum/)  

---

You have an array $A$ of $N$ integers. You have to perform $Q$ operations of two types:

Update: given two integers $i$ and $s$, add $s$ to $A_i$ and decrease all the other elements of $A$ by $\large\frac{s}{N-1}$.Query: given an index i find the value of $A_i$.

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains the $N$ elements of $A$.

Each of the following $Q$ lines describes one operation. An update consists of three integers $0\ i\ s$, while a query consists of two inters $1\ i$.

### Standard output

For each query print the answer on a distinct line.

### Constraints and notes

$2 \leq N\leq 10^5$ $1 \leq Q \leq 10^5$ $0 \leq A_i \leq 1000$ $1 \leq s_i \leq 1000$ An answer is considered correct if the absolute difference between it and the official answer is less than $10^{-6}$.

| Input | Output |
| --- | --- |
| 4 6<br>1 2 4 3<br>0 2 6<br>1 1<br>0 1 3<br>1 3<br>0 1 2<br>1 4 | -1.0000000000<br>1.0000000000<br>-0.6666666667 |
