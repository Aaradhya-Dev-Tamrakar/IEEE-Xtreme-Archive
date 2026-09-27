# Cut the Tree

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cut-the-tree/](https://csacademy.com/contest/archive/task/cut-the-tree/)  

---

You are given a tree with $N$ vertices.

In one step you are allowed to cut off one leaf of the tree, but only if length of the diameter of the tree decreases by $1$. You can't cut a tree with one vertex.

What is the maximum number of consecutive steps you can make?

### Standard input

The first line contains one integer $N$.

Each of the following $N - 1$ lines contain two integers, representing two nodes that share an edge.

### Standard output

Print a single integer representing the maximum number of consecutive steps you can make.

### Constraints and notes

$1 \le N \le 10^5$ The diameter of a tree is defined as the longest path between any two nodes.

| Input | Output |
| --- | --- |
| 3<br>1 2<br>2 3 | 2 |
| 4<br>2 1<br>2 3<br>2 4 | 0 |
| 9<br>1 2<br>1 3<br>1 4<br>4 5<br>5 6<br>4 7<br>7 8<br>8 9 | 1 |
