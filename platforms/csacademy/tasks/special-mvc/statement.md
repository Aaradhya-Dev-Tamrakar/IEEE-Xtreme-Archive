# Special MVC

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/special-mvc/](https://csacademy.com/contest/archive/task/special-mvc/)  

---

You are given a graph with $N$ nodes and $M$ edges. It is guaranteed the graph doesn't contain any simple cycles having even length. Find the size of a minimum vertex cover.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

Print a single integer representing the size of a minimum vertex cover.

### Constraints and notes

$1 \leq N \leq 10^5$ $0 \leq M \leq 2 * 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4<br>1 2<br>2 3<br>3 4<br>4 2 | 2 | 1234 |
| 7 6<br>1 2<br>1 5<br>2 3<br>2 4<br>5 6<br>6 7 | 3 | 1234567 |
| 10 11<br>1 2<br>1 10<br>2 3<br>2 4<br>4 5<br>4 7<br>4 8<br>7 8<br>5 9<br>5 6<br>3 6 | 5 | 12345671089 |
