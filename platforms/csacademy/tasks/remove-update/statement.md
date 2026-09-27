# Remove Update

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/remove-update/](https://csacademy.com/contest/archive/task/remove-update/)  

---

You have an array $A$ of size $N$. Initially all the elements of $A$ are equal to $0$.

You have $Q$ updates of the form:

Given $l$, $r$ and $x$ ($1 \leq l \leq r \leq N$, $x$ is positive), add $x$ to $A_l, A_{l+1},..., A_r$ 

You can choose to skip exactly one of the updates. In the end you want the maximum element of $A$ to be as small as possible.

### Standard input

The first line contains two integers $N$ and $Q$.

Each of the next $Q$ lines contains three integers $l$, $r$ and $x$.

### Standard output

Print on the first line the smallest maximum value you can get by skipping one update.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq Q \leq 10^5$ $1 \leq l \leq r \leq N$ $1 \leq x \leq 10^9$ It is guaranteed that if you perform all the updates $A_i \leq 10^9$

| Input | Output |
| --- | --- |
| 4 2<br>1 3 1<br>2 4 1 | 1 |
| 4 3<br>2 4 2<br>1 2 2<br>3 4 1 | 2 |
| 6 4<br>2 3 1<br>4 6 2<br>3 4 3<br>1 4 2 | 4 |
