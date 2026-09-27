# Colored Forests

**Time Limit:** `4000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/colored-forests/](https://csacademy.com/contest/archive/task/colored-forests/)  

---

You are given two integers $N$ and $M$. We consider labeled trees where each node is colored in one of $M$ distinct colors. We say that a tree is colorful if each color of the $M$ colors occurs at least once. A forest in colorful if each tree is colorful.

Count the number of colorful forests with $i$ nodes, for $1 \leq i \leq N$.

### Standard input

The first line contains two integers $N$ and $M$.

### Standard output

On each line $i$ print a value representing the number of colorful forests with $i$ nodes modulo $924844033$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq M \leq 50$ 

| Input | Output |
| --- | --- |
| 3 1 | 1<br>2<br>7 |
| 4 2 | 0<br>2<br>18<br>236 |
