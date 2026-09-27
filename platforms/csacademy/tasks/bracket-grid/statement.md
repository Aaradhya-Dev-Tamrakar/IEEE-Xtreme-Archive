# Bracket Grid

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bracket-grid/](https://csacademy.com/contest/archive/task/bracket-grid/)  

---

A bracket sequence $S$ is a correct bracket sequence if either of the following holds :

It is empty.It is the concatenation of $2$ correct bracket sequences.It is of the form $(T)$, where $T$ is a correct bracket sequence.

For example, $(()), (()()), (()(()))(()())$ are correct bracket sequences while $())(, (()))(, ()((, ($ are not correct bracket sequences.

Construct a grid where each cell is filled with either $($ or $)$ such that there are exactly $K$ paths from the top left corner to the bottom right corner which goes only downwards and rightwards, and the bracket sequence formed by the squares visited in the path is a correct bracket sequence.

### Standard input

The first and only line of input contains a single integer $K$.

### Standard output

The first line of output should contain two integers $N, M$, denoting the number of rows and the number of columns of the grid respectively.

The next $N$ should contain $M$ characters each, where each character should be either $($ or $)$. The output grid must contain exactly $K$ paths from the top-left corner to the bottom-right corner which goes only downwards or rightwards such that the sequence of brackets formed from the path is a correct bracket sequence. If there are multiple solutions, any valid solution will be accepted.

### Constraints and notes

$1 \le K \le 10^{9}$ The output must satisfy $1 \le N, M \le 200$.

| Input | Output | Explanation |
| --- | --- | --- |
| 4 | 3 4<br>()))<br>((()<br>())) | Let the cell on the $i$-th row and $j$-th column be $(i, j)$. There are $4$ paths that form a correct bracket sequence :$(1, 1) \rightarrow (1, 2) \rightarrow (2, 2) \rightarrow (2, 3) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $()(())$.$(1, 1) \rightarrow (1, 2) \rightarrow (2, 2) \rightarrow (2, 3) \rightarrow (2, 4) \rightarrow (3, 4)$ with bracket sequence $()(())$.$(1, 1) \rightarrow (2, 1) \rightarrow (2, 2) \rightarrow (3, 2) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $((()))$.$(1, 1) \rightarrow (2, 1) \rightarrow (3, 1) \rightarrow (3, 2) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $((()))$. |
| 5 | 3 4<br>()()<br>)())<br>))() | Let the cell on the $i$-th row and $j$-th column be $(i, j)$. There are $5$ paths that form a correct bracket sequence :$(1, 1) \rightarrow (1, 2) \rightarrow (1, 3) \rightarrow (2, 3) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $()()()$.$(1, 1) \rightarrow (1, 2) \rightarrow (2, 2) \rightarrow (2, 3) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $()()()$.$(1, 1) \rightarrow (1, 2) \rightarrow (2, 2) \rightarrow (3, 2) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $()()()$.$(1, 1) \rightarrow (2, 1) \rightarrow (2, 2) \rightarrow (3, 2) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $()()()$. $(1, 1) \rightarrow (2, 1) \rightarrow (2, 2) \rightarrow (2, 3) \rightarrow (3, 3) \rightarrow (3, 4)$ with bracket sequence $()()()$. |
