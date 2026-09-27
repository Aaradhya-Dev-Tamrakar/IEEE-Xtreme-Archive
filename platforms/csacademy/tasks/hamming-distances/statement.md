# Hamming Distances

**Time Limit:** `5000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/hamming-distances/](https://csacademy.com/contest/archive/task/hamming-distances/)  

---

You are given an array $A$ of $N$ non-negative integers and integer $M$. All elements in $A$ are less than $2^M$.

For each $i$ from $1$ to $N$ and $x$ from $0$ to $M$ find the number of indices $j$ such that $1 \le j < i$ and Hamming distance between binary representations of numbers $A_i$ and $A_j$ is equal to $x$.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

For each $i$ from $1$ to $N$ print a separate line containing $M+1$ numbers: answer for $x = 0, 1 \ldots M$.

### Constraints and notes

$1 \le N \le 2\cdot 10^5$ $1 \le M \le 16$ $0 \le A_i < 2^M$ 

| Input | Output |
| --- | --- |
| 4 2<br>0 1 2 3 | 0 0 0 <br>0 1 0 <br>0 1 1 <br>0 2 1 |
| 4 2<br>0 1 1 0 | 0 0 0 <br>0 1 0 <br>1 1 0 <br>1 2 0 |
