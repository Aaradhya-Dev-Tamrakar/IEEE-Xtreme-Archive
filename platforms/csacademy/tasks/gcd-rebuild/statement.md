# Gcd Rebuild

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/gcd-rebuild/](https://csacademy.com/contest/archive/task/gcd-rebuild/)  

---

Consider two arrays: $V$ of size $N$ and $U$ of size $M$. The elements of both arrays are integers between $1$ and $10^9$.

You are given a matrix $A$ where $A_{i,j} = \gcd(V_i, U_j)$ and $\gcd$ refers to the greatest common divisor. You are asked to find $V$ and $U$.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ integers, representing the elements of $A$.

### Standard output

If there is no solution, or you cannot find a solution where the elements of $V$ and $U$ are in the range $[1, 10^9]$, output $-1$.

Otherwise, print the $N$ elements of $V$ on the first line and the $M$ elements of $U$ on the second line. If the solution is not unique you can output any of them.

### Constraints and notes

$1 \leq N, M \leq 300$ $1 \leq A_{i, j} \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>1 2 2<br>3 2 2<br>3 1 1 | 2 6 3 <br>3 2 2 | $gcd(2, 3)=1$$gcd(2, 2)=2$$gcd(6, 3)=3$$gcd(6, 2)=2$$gcd(3, 3)=3$$gcd(3, 2)=1$ |
| 3 2<br>2 2<br>2 2<br>4 2 | 2 2 4 <br>4 2 | $gcd(2, 2)=2$$gcd(2, 4)=2$$gcd(4, 4)=4$ |
| 2 2<br>1 1<br>1 1 | 1 1 <br>1 1 | $gcd(1, 1)=1$ |
| 3 3<br>4 2 4<br>2 4 2<br>4 2 4 | -1 | There is no solution. |
