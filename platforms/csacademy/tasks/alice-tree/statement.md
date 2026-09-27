# Alice's Tree

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alice-tree/](https://csacademy.com/contest/archive/task/alice-tree/)  

---

For the past two hours, Alice has been playing with trees, trying to find various interesting properties of them. Lately, she was fascinated by the maximum distance between two vertices, which she (unknowingly) called the length of the tree.

After playing with this property for a while, she comes to Bob, asking him the following question:

"Say I have a tree with $N$ vertices. I will not give you the tree itself, but all I'm telling you is the number of incident edges for each of the $N$ vertices. However, I'll also require you that the length of the tree should be exactly $X$ [after this follows a thorough explanation of what the length of a tree is]. Now, you have to recover the tree. Can you do it?"

"You know it's not called like that..."

"Stop changing the subject!"

### Standard input

The first line of the input contains two integers $N$ and $X$. The second line of the input contains $N$ positive integer numbers $d_i$, denoting the number of edges incident to vertex $i$ of the tree.

### Standard output

The output should contain exactly $N - 1$ lines. Each line should contain two positive integers $a_i$ and $b_i$ ($1 \leq a_i, b_i \leq N$), denoting an edge between $a_i$ and $b_i$. The result should be a tree.

### Constraints and notes

$2 \leq N \leq 10^5$ Alice guarantees that there is at least one tree that satisfies a given input.

| Input | Output |
| --- | --- |
| 4 2<br>1 3 1 1 | 1 2<br>3 2<br>2 4 |
| 5 4<br>1 2 2 2 1 | 1 2<br>2 3<br>3 4<br>4 5 |
| 8 4<br>3 3 1 3 1 1 1 1 | 1 2<br>1 3<br>1 4<br>2 5<br>2 6<br>4 7<br>4 8 |
