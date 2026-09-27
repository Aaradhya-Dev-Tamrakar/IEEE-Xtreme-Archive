# Build Binary Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/build-binary-matrix/](https://csacademy.com/contest/archive/task/build-binary-matrix/)  

---

You are given two arrays, $R$ of size $N$ and $C$ of size $M$. You should generate a binary matrix of $N$ rows and $M$ columns, such that:

Two rows $i$ and $j$ are equal if $R_i =R_j$, otherwise they are differentTwo columns $i$ and $j$ are equal if $C_i = C_j$, otherwise they are different

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains the elements of $R$.

The third line contains the elements of $C$.

### Standard output

If there is no solution output $-1$.

Otherwise, print the values of the matrix on the first $N$ lines, each containing $M$ characters.

### Constraints and notes

$1 \leq N, M \leq 1000$ $1 \leq R_i \leq N$ $1 \leq C_i \leq M$ 

| Input | Output |
| --- | --- |
| 6 4<br>5 3 6 6 6 3<br>3 1 2 1 | 1000<br>0101<br>0010<br>0010<br>0010<br>0101 |
| 2 5<br>1 2<br>1 3 5 2 4 | -1 |
