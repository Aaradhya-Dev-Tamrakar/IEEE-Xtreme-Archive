# Catch the Thief

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/catch-the-thief/](https://csacademy.com/contest/archive/task/catch-the-thief/)  

---

You are given a graph with $N$ nodes and $M$ edges. Initially, there's a thief in one of the nodes, but you don't know which one. Every day you can check exactly one of the nodes to see if the thief is there. You know that the thief likes to travel in order to avoid getting caught, so every night he moves in one of the neighbours of its current node.

Find a strategy to catch the thief regardless of his starting node and the way he moves.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $M$ lines contains two integer values, representing two nodes that share an edge.

### Standard output

If there is no solution print $-1$.

Otherwise, the first line should contain the number $K$ of days of your strategy.

The second line should contains $K$ numbers representing the nodes where you want to check for the thief in each of the $K$ days.

### Constraints and notes

$1 \leq N, M \leq 2500$ In order to pass a test, $K$ should be smaller than $10 * N$.Each node has at least one neighbour.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2<br>1 2<br>2 3 | 2<br>2<br>2 | 123 |
| 5 4<br>1 2<br>2 3<br>3 4<br>3 5 | 6<br>1<br>2<br>3<br>1<br>2<br>3 | 12345 |
| 7 7<br>1 2<br>1 3<br>1 4<br>2 5<br>2 6<br>5 6<br>6 7 | -1 | 1234567 |
