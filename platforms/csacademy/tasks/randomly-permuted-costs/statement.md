# Randomly Permuted Costs

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/randomly-permuted-costs/](https://csacademy.com/contest/archive/task/randomly-permuted-costs/)  

---

You are given a DAG with $N$ nodes and $M$ arcs. The DAG can contain multiple arcs and self loops. All the arcs have associated costs.

You want to travel from node $S$ to node $D$. Everytime you reach a node $u$, the costs of its outgoing arcs are randomly permuted. This is also true for the initial step when you start in $S$.

You want to reach the destination as fast as possible. What is the expected cost if you travel optimally?

After each move you are aware of the assignment, so you can the path dynamically, based on the current shuffle.

### Standard input

The first line contains $4$ integers $N$, $M$, $S$ and $D$.

Each of the next $M$ lines contains three numbers, $a$, $b$ and $c$, representing an arc from node $a$ to node $b$, having cost $c$.

$a$ and $b$ are integers between $1$ and $N$ and $c$ is a positive real number.

### Standard output

If there is no way to reach $D$ output $-1$.

Otherwise, print the expected cost.

### Constraints and notes

$2 \leq N \leq 1000$ $1 \leq M \leq 1000$$S \neq D$The costs are real numbers from $1.0$ to $100.0$An answer is considered correct if the absolute difference between it and the official answer is less than 10^-6 (0.000001).

| Input | Output |
| --- | --- |
| 3 2 1 3<br>1 2 5.00000000<br>1 3 6.00000000 | 5.500000000 |
| 4 4 1 3<br>1 2 1.00000000<br>2 3 6.00000000<br>2 4 3.00000000<br>1 1 3.00000000 | 6.500000000 |
| 2 4 1 2<br>1 1 1.00000000<br>1 1 1.50000000<br>1 2 2.00000000<br>1 2 2.50000000 | 1.333333333 |
| 4 7 1 4<br>3 4 1.22107652<br>3 4 1.03142261<br>2 3 3.41053088<br>1 1 1.87415428<br>1 1 4.59629983<br>1 1 4.52859830<br>1 2 2.74330909 | 7.877543864 |
