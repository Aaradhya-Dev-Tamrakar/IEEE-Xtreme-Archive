# Flip the Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flip-the-matrix/](https://csacademy.com/contest/archive/task/flip-the-matrix/)  

---

You are given two square matrices $A$ and $B$ of size $N \times N$. Decide whether you can get $B$ by flipping $A$ horizontally or vertically.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains $N$ integers representing the elements of $A$.

After that, each of the following next $N$ lines contains $N$ integers representing the elments of $B$.

### Standard output

Output $1$ if it's possible and $0$ if not. It is necessary to flip $A$ exactly one, either horizontally of vertically.

### Constraints and notes

$1 \leq N \leq 100$ $1 \leq A_{i,j}, B_{i, j} \leq 100$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>1 2<br>3 4<br>3 4<br>1 2 | 1 | $B$ can be obtained by flipping $A$ horizontally. |
| 2<br>1 2<br>3 4<br>2 1<br>4 3 | 1 | $B$ can be obtained by flipping $A$ vertically. |
| 2<br>1 2<br>3 4<br>4 3<br>2 1 | 0 | Note that you can only flip horizontally or vertically, not both. |
| 2<br>1 2<br>3 4<br>1 2<br>3 4 | 0 | Note that you must do one flip horizontally or vertically. |
