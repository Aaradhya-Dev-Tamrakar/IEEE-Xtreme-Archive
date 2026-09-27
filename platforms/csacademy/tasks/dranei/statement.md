# Dr. Anei

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dranei/](https://csacademy.com/contest/archive/task/dranei/)  

---

As you probably heard, Paul loves oranges. It's not a surprise that at each training round he brings one orange for each problem in the contest, and the first one to solve that problem will win the corresponding orange. Of course, the harder the problem is, the more beautiful the orange is considered.

To ensure the freshness and quality of the fruits, Paul built a tree of oranges. The tree can be represented as an undirected connected acyclic graph, with the mention that in each node $i$ there is an orange of $c_i$ beauty.

On the tree we can apply the following operations:

Update: For this operation, Paul rootes the tree in $x$, and among the sons of $x$, he chooses the one whose subtree contains the node $y$. Then, he will water the oranges in the subtree of that node with $z$ units of magic potion. In other words, each orange in the subtree will get its beauty degree increased with $z$ units.Query: Paul asks you what is the beauty degree of the orange in node $p$.

### Standard input

The first line contains two numbers: $n$ (the number of nodes) and $q$ (the number of operations).

The second line contains $n$ integers representing the beauty degrees of the oranges, starting with node $1$ and ending with node $n$.

Each of the next $n - 1$ lines contains two numbers $a$ and $b$, meaning that there exists an edge between nodes $a$ and $b$.

The last $q$ lines describe the events, according to the following format:

1 x y z for updates;2 p for queries.

### Standard output

The output contains as many lines as there are operations of type 2. The $i$'th line will contain the answer for the $i$'th query.

### Constraints and notes

$3 \le n, q \le 10^5$ $1 \le x, y, p \le n$ $1 \le z \le 10^6$ $1 \le c_i \le 10^6, i = \overline{1, n}$

| Input | Output |
| --- | --- |
| 5 5<br>4 2 3 3 4 <br>3 5<br>5 1<br>4 2<br>5 2<br>2 2<br>1 2 4 2<br>2 3<br>1 3 4 3<br>2 3 | 2<br>3<br>3 |
| 5 10<br>3 3 3 1 3 <br>1 2<br>2 3<br>4 3<br>5 3<br>1 2 4 2<br>1 3 2 1<br>1 3 4 1<br>2 4<br>1 3 4 3<br>2 2<br>2 3<br>1 3 4 1<br>1 4 3 2<br>2 2 | 4<br>4<br>5<br>6 |
