# Bob's Tree

**Time Limit:** `2500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bob-tree/](https://csacademy.com/contest/archive/task/bob-tree/)  

---

After being challanged so fiercefully by Alice in the last task, Bob grew a bit fond of trees as well. However, having participated in various Romanian programming contests, he is more interested in the so-called "update-query" type problems.

Bob's task sounds like this:

At the beginning, he has a tree where each vertex has a color assigned to it. He gives you a list of $Q$ operations to perform, of two types:

$1$ $v$ $c$ : the color of vertex $v$ becomes $c$; (this is the "update" operation)$2$ $c$ : output the maximum distance between two vertices having color $c$. (this is the "query" operation)

### Standard input

The first line contains $N$ representing the total number of vertices in the tree. The second line contains $N$ values representing the color of each vertex. Each of the following $N-1$ lines contains two values $a_i$ $b_i$, meaning that there is an edge between vertices $a_i$ and $b_i$ in the tree.

The following line contains a positive integer $Q$, the number of operations to be performed. The following $Q$ lines are of the form:

$1$ $v$ $c$ (an "update" operation);$2$ $c$ (a "query" operation). 

### Standard output

For each operation of type $2$ you should output a positive integer, the answer to the query, on a separate line.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq Q \leq 10^5$ All colors are positive integers, not exceeding $N$. It is guaranteed that at the moment of any query-type operation of form $2$ $c$, there are at least two distinct vertices with color $c$.

| Input | Output |
| --- | --- |
| 5<br>2 2 3 1 1<br>2 1<br>3 1<br>4 3<br>5 3<br>3<br>2 1<br>1 4 2<br>2 2 | 2<br>3 |
| 6<br>2 2 2 2 2 3<br>2 1<br>3 1<br>4 1<br>5 2<br>6 3<br>4<br>1 6 1<br>1 1 2<br>1 3 2<br>2 2 | 3 |
