# Count Gigel Matrices

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cntgigelmat/](https://csacademy.com/contest/archive/task/cntgigelmat/)  

---

You are given a binary matrix of size $N\times M$. Count the number of square submatrices that contain $1$ on the borders and on the principal diagonal (top-left to bottom-right). There is no restriction for the rest of the cells, they can be either $0$ or $1$.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains a binary string of size $M$, representing the elements of the matrix.

### Standard Output

Print the answer on the first line.

### Constraints and notes

$1 \leq N, M \leq 2000$ 

| Input | Output |
| --- | --- |
| 5 5<br>11111<br>11001<br>10101<br>10011<br>11111 | 22 |
| 4 7<br>1111111<br>1101101<br>1011011<br>1111111 | 30 |
| 6 5<br>11111<br>10011<br>10101<br>11001<br>11111<br>10101 | 24 |
