# Binary Isomorphism

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/binary-isomorphism/](https://csacademy.com/contest/archive/task/binary-isomorphism/)  

---

You are given two binary trees. These two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping the children of some nodes. Two leaves are isomorphic.

Both these trees will be given through their parents array. In a parents array,

nodes are $1$-basedthere is only one position $r$ where $P_r = 0$. This means that $r$ is the root of the tree.for every node $i \neq r$, its direct parent is $P_i$. 

### Standard input

The first line contains $T$, the number of test cases.

For every test:

the first line contains $N$, representing the number of nodes in both of the treesthe second line contains $N$ integers, representing the parents array of the first treethe third line contains $N$ integers, representing the parents array of the second tree

### Standard output

For every test case, print a line containing 1 if the two trees are isomorphic, or 0 otherwise.

### Constraints and notes

$1 \leq T \leq 20$ $1 \leq N \leq 10^5$. The sum of all values of $N$ in a test is $\leq 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>4<br>3 0 2 3<br>3 4 0 3<br>5<br>5 1 0 3 4<br>5 1 4 2 0<br>5<br>0 1 2 1 4<br>0 1 4 1 2 | 0<br>1<br>1 | 1324314215234423511234512543 |
