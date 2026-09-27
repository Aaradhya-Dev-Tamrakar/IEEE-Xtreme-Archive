# Strange Matrix

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/strange-matrix/](https://csacademy.com/contest/archive/task/strange-matrix/)  

---

You are given a $N \times M$ matrix of costs, $A$.

A path in the matrix is a sequence of $M$ cells $(X_1, 1), (X_2, 2), (X_3, 3), ..., (X_M, M)$ such that:

$1 \leq X_i \leq N$ for $1 \leq i \leq M$ $X_{i + 1} - X_{i} \in \{-1, 0, 1\}$ for $1 \leq i < M$ 

The cost of this path is $C := \sum_{i=1}^{M} A_{X_i, i}$. The optimal cost is the maximum possible value of $C$.

You are given $Q$ updates in which you are given a triplet $(R, C, T)$, which means that $A_{R, C}$ is now equal to $T$.

After each change, print the value of the optimal cost.

### Standard input

The first line contains three integers $N$,  $M$ and $Q$.

The next $N$ lines contain $M$ integers, the $A$ matrix.

On each of the following $Q$ lines, there will be three integers, $R$, $C$ and $T$.

### Standard output

Print $Q$ lines, each containing the answer after the change.

### Constraints and notes

$1 \leq N \leq 5$ $1 \leq M \leq 2 * 10^4$ $1 \leq Q \leq 2 * 10^4$ $0 \leq A_{i, j} \leq 5 * 10^4$ for $1 \leq i \leq N$, $1 \leq j \leq M$ $0 \leq T \leq 5 * 10^4$ $1 \leq R \leq N$ and $1 \leq C \leq M$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4 5<br>1 3 3 5<br>2 2 1 1<br>3 3 4 1<br>1 2 0<br>1 3 1<br>3 3 1<br>2 3 3<br>1 4 0 | 13<br>12<br>12<br>14<br>10 | The underlined cells are part of  one of the paths with optimal cost. (there can be more paths which yield the optimal cost. only one of them is showcased)After each query the matrix will look like:$\begin{bmatrix} 1 & 0 & \underline3 & \underline5 \\ 2 & \underline2 & 1 & 1 \\ \underline3 & 3 & 4 & 1 \end{bmatrix}$$\begin{bmatrix} 1 & 0 & 1 & \underline5 \\ 2 & 2 & \underline1 & 1 \\ \underline3 & \underline3 & 4 & 1 \end{bmatrix}$$\begin{bmatrix} 1 & 0 & 1 & \underline5 \\ 2 & 2 & \underline1 & 1 \\ \underline3 & \underline3 & 1 & 1 \end{bmatrix}$$\begin{bmatrix} 1 & 0 & 1 & \underline5 \\ 2 & 2 & \underline3 & 1 \\ \underline3 & \underline3 & 1 & 1 \end{bmatrix}$$\begin{bmatrix} 1 & 0 & 1 & 0 \\ 2 & 2 & \underline3 & 1 \\ \underline3 & \underline3 & 1 & \underline1 \end{bmatrix}$ |
