# Flip Game

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flip-game/](https://csacademy.com/contest/archive/task/flip-game/)  

---

You are given a binary matrix of $N$ rows and $M$ columns. You can perform the following type of operations:

Choose a row/column and change the state of each element. If the elment is $0$ change it to $1$, and if it's $1$ change it to $0$.

You are allowed to perform an unlimited number of operations. In the end you interpret each row as the binary representation of a number, where the first column is associated with the most significant bit. You should maximize the sum of all the $N$ numbers.

### Standard input

The first line contains the two integers $N$ and $M$.

Each of the following $N$ lines contains an array of $M$ integers, each integer is either $0$ or $1$.

### Standard output

Output a single number representing the maximum sum you can get.

### Constraints and notes

$1 \leq N, M \leq 50$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>1 0 0<br>1 0 0<br>0 1 1 | 21 | Flip the first column:0 0 0<br>0 0 0<br>1 1 1Flip the first and second row:1 1 1<br>1 1 1<br>1 1 1We get a sum of $3 * (4 + 2 + 1) = 21$ |
| 3 3<br>1 1 0<br>0 1 1<br>1 0 1 | 18 | Flip the second column:1 0 0<br>0 0 1<br>1 1 1Flip the third column:1 0 1<br>0 0 0<br>1 1 0Flip the second row:1 0 1<br>1 1 1<br>1 1 0We get a sum of $(4 + 1) + (4 + 2 + 1) + (4 + 2) = 18$ |
| 4 2<br>0 1<br>0 0<br>0 1<br>0 0 | 10 | Just flip the first column:11<br>1 0<br>1 1<br>1 0We get $(2 + 1) + (2) + (2 + 1) + (2) = 10$ |
| 3 4<br>0 1 1 1 <br>1 1 0 0 <br>0 1 1 1 | 41 | Flip the first column:1 1 1 1<br>0 1 0 0<br>1 1 1 1Flip the second row:1 1 1 1<br>1 0 1 1<br>1 1 1 1We get $(8 + 4 + 2 + 1) + (8 + 2 + 1) + (8 + 4 + 2 + 1) = 41$ |
