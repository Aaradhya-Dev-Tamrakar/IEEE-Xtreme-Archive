# Field Activation

**Time Limit:** `4000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/field-activation/](https://csacademy.com/contest/archive/task/field-activation/)  

---

You have a recangular field with $N$ rows and $M$ columns. Each cell of the field can be activated in a single operation. Initially none of the cells is activated. You are also given $Q$ relations, each consisting of two rectangles with the sides parallel to the coordinate axes. The meaning of each relation is that if any cell in the first rectangle is activated then all the cells in the second rectangle are also activated. The activation process works recursively: the cells in the second rectangle can trigger another relation.

You should activate the entire field using the minimum number of single cell activations.

### Standard input

The first line contains three integers $N$, $M$ and $Q$.

Each of the following $Q$ lines contains eight integers. The first four integers correspond to the first rectangle, while the last four to the second rectangle. Each set of four numbers describing a rectangle is of the form $x_1\ y_1\ x_2\ y_2$ representing the lower left and the upper right corners.

### Standard output

Output a single number representing the minimum number of single cell activations needed for the entire field.

### Constraints and notes

$1 \leq N, M \leq 300$$1 \leq Q \leq 10^5$$0 \leq x_1 \leq x_2 < N$, $0 \leq y_1 \leq y_2 < M$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3 3<br>0 0 1 1 1 1 2 2<br>0 0 0 0 0 1 1 2<br>1 1 2 2 0 0 1 1 | 2 | A possible solution is to activate the cells $(0, 0)$ and $(2, 0)$. |
| 4 4 6<br>0 0 0 0 1 1 1 1<br>1 1 1 1 2 2 2 2<br>2 2 2 2 3 3 3 3<br>3 3 3 3 0 0 0 0<br>2 0 3 1 0 2 1 3<br>0 0 1 1 3 0 3 0 | 8 | Activate:$(2, 2)$$(0, 1)$$(1, 0)$$(2, 0)$$(2, 1)$$(2, 3)$$(3, 1)$$(3, 2)$ |
| 1 10 3<br>0 0 0 2 0 2 0 4<br>0 5 0 5 0 9 0 9<br>0 6 0 6 0 0 0 3 | 4 | Activate:$(0, 5)$$(0, 6)$$(0, 7)$$(0, 8)$ |
