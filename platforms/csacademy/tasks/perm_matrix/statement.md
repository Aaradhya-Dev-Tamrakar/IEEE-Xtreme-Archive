# Perm Matrix

**Time Limit:** `4000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/perm_matrix/](https://csacademy.com/contest/archive/task/perm_matrix/)  

---

You are given a matrix with $N$ rows and $M$ columns. For each row you are allowed to permute its elements. Decide if you can reach a state where there are no adjacent cells on the same column having the same value.

### Standard input

The first line contains two integer values $N$ and $M$.

Each of the next $N$ lines contains $M$ integer values, representing the elements of the matrix.

### Standard output

The output should contain a matrix that represents a possible solution. If there is no solution, print $-1$ instead.

### Constraints and notes

$1 \leq N * M \leq 10^6$The values in the matrix are integers between $1$ and $10^6$If there are more solutions you can output any of them

| Input | Output |
| --- | --- |
| 3 3<br>1 2 2<br>1 1 2<br>1 2 3 | 1 2 2<br>2 1 1<br>1 2 3 |
| 3 3<br>3 1 3<br>1 1 1<br>1 3 3 | -1 |
| 3 5<br>1 2 3 1 1<br>2 2 2 2 3<br>3 3 1 2 1 | 1 2 3 1 1<br>2 3 2 2 2<br>3 2 1 3 1 |
| 1 5<br>1 1 1 1 1 | 1 1 1 1 1 |
| 3 1<br>1<br>2<br>1 | 1<br>2<br>1 |
| 1 1<br>4 | 4 |
