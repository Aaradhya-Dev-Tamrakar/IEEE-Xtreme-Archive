# Right Down Path

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/right-down-path/](https://csacademy.com/contest/archive/task/right-down-path/)  

---

You are given a binary matrix $A$ of size $N \times M$. You should find a path that starts in a cell, then goes to the right at least one cell, then goes down at least one other cell. That path should contain only cells equal to $1$.

Find the longest path respecting these constraints.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $M$ integers, $0$ or $1$, representing the elements of matrix $A$.

### Standard output

Print the size of the longest path on the first line.

### Constraints and notes

$2 \leq N, M \leq 300$ It is guaranteed there is always at least one valid path

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4<br>0 1 1 0<br>1 1 1 0<br>1 0 1 0<br>1 1 0 0 | 4 | One of the solutions of length $4$ is bolded below.$0\ \bold{1}\ \bold{1}\ 0$$1\ 1\ \bold{1}\ 0$$1\ 0\ \bold{1}\ 0$$1\ 1\ 0\ 0$ |
| 5 4<br>1 0 1 0<br>1 1 1 1<br>1 0 1 0<br>1 0 1 1<br>0 0 0 1 | 5 | The solutions of length $5$ is bolded below.$1\ 0\ 1\ 0$$\bold{1}\ \bold{1}\ \bold{1}\ 1$$1\ 0\ \bold{1}\ 0$$1\ 0\ \bold{1}\ 1$$0\ 0\ 0\ 1$ |
| 5 5<br>0 0 0 0 1<br>1 1 0 0 1<br>0 1 0 1 1<br>0 0 0 0 1<br>1 1 1 1 1 | 4 | Note that you need to move at least once right and down.Because of this, the solutions consisting of the 5 ones on the sides is not valid.The valid solution is bolded below.$0\ 0\ 0\ 0\ 1$$1\ 1\ 0\ 0\ 1$$0\ 1\ 0\ \bold{1}\ \bold{1}$$0\ 0\ 0\ 0\ \bold{1}$$1\ 1\ 1\ 1\ \bold{1}$ |
