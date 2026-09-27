# Square Cover

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/square-cover/](https://csacademy.com/contest/archive/task/square-cover/)  

---

You are given a matrix $A$ of size $N \times M$. You should partition the matrix in square submatrices such that each submatrix contains cells having the same value. Even more, all the cells having the same value should be part of the same square.  Find out if it's possible or not to do this.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ integers representing the elements of the matrix $A$.

### Standard output

Print $1$ if there is a solution, otherwise print $0$.

### Constraints and notes

$1 \leq N, M \leq 300$ $0 \leq A_{i, j} \leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>1 1 2<br>1 1 3<br>4 5 6 | 1 | We can cover the matrix using $6$ squares (one $2 \times 2$  and $5$ squares of size $1\times 1$) |
| 4 4<br>1 1 3 3<br>1 1 3 3<br>2 2 4 4<br>2 2 4 4 | 1 | We can cover the matrix using $4$ squares of size $2\times 2$ |
| 2 5<br>1 1 1 2 2<br>1 1 1 2 2 | 0 | It's impossible to cover all $1$s with a square. |
| 3 3<br>1 1 1<br>1 2 1<br>1 1 1 | 0 | Even if the $1$s form a square, it must contain only values of $1$. |
| 3 3<br>1 1 2<br>1 1 3<br>4 5 1 | 0 | This is similar to the first example, the only difference being that the $6$ is now a $1$. The answer is $0$ because all values of $1$ must be covered with only one square. Here we'll need $2$ squares containing $1$s, which is not possible. |
