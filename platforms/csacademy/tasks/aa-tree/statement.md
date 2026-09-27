# AA Tree

**Time Limit:** `100 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/aa-tree/](https://csacademy.com/contest/archive/task/aa-tree/)  

---

An AA tree is a binary search tree with a special structure. Every node has a value and a level. Values obey the usual binary search tree properties:

The value of every left child is less than or equal to the value of its parent.The value of every right child is greater than or equal to the value of its parent.

Levels obey the following rules:

The level of every leaf node is 1.The level of every left child is exactly one less than that of its parent.The level of every right child is equal to or one less than that of its parent.The level of every right grandchild is strictly less than that of its grandparent.Every node of level greater than one has two children.

Below are five examples of AA trees, having 3, 5, 5, 11 and 11 nodes respectively. For clarity, right children on an equal level with their parent are shown in red.

Given two numbers $N$ and $L$, how many ways are there of arranging the values $1, 2, \dots, N$ in an AA tree such that it has exactly $L$ levels?

### Standard input

The only line of input will contain the integers $N$ and $L$ separated by a space.

### Standard output

Output the number of arrangements modulo $1\ 000\ 000\ 007$.

### Constraints and notes

$1 \leq L \leq 9$.$1 \leq N  \leq 10\ 000$.

#PointsRestrictions119$L\leq 4$234$5 \leq  L \leq 7$347No further constraints.

| Input | Output |
| --- | --- |
| 5 2 | 2 |
| 442 6 | 896944318 |
| 7133 9 | 980381648 |

### Explanations

For the first example, the two possible arrangements are shown in images 2 and 3 above.
