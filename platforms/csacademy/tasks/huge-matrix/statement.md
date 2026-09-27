# Huge Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/huge-matrix/](https://csacademy.com/contest/archive/task/huge-matrix/)  

---

You have a matrix with $N$ rows and $M$ columns with values between $0$ and $K$. On each row, all the cells different than $0$ have the same value. Even more, they form a continuous sequence.

Find the column with the most distinct values.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains tree integers $l$, $r$ and $a$, representing an interval of columns $[l, r]$ equal to $a$ on a line.

### Standard output

Print a single integer representing the maximum number of distinct values on any column.

### Constraints and notes

$1 \leq N, M \leq 10^5$ $1 \leq K \leq 10$ $1 \leq l\leq r \leq M$ $1 \leq a \leq K$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4<br>1 3 1<br>1 3 2<br>2 4 1 | 3 | The matrix looks like this:$1\ 1\ 1\ 0$$2\ 2\ 2\ 0$$0\ 1\ 1\ 1$The maximum number of distinct values is found in column 1. |
| 5 10<br>3 5 2<br>1 7 2<br>1 5 1<br>1 3 3<br>5 7 4 | 4 | The matrix looks like this:$0\ 0\ 2\ 2\ 2\ 0\ 0\ 0\ 0\ 0$$2\ 2\ 2\ 2\ 2\ 2\ 2\ 0\ 0\ 0$$1\ 1\ 1\ 1\ 1\ 0\ 0\ 0\ 0\ 0$$3\ 3\ 3\ 0\ 0\ 0\ 0\ 0\ 0\ 0$$0\ 0\ 0\ 0\ 4\ 4\ 4\ 0\ 0\ 0$The maximum number of distinct values is found in columns 1, 2, 3 or 5. |
| 3 4<br>1 3 1<br>1 3 2<br>1 3 3 | 3 | The matrix looks like this:$1\ 1\ 1\ 0$$2\ 2\ 2\ 0$$3\ 3\ 3\ 0$The maximum number of distinct values is found in column 1, 2 or 3. |
