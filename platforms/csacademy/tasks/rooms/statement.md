# Rooms

**Time Limit:** `3500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/rooms/](https://csacademy.com/contest/archive/task/rooms/)  

---

You are given a matrix with $N$ rows and $M$ colums which contains lowercase letters of the English alphabet.

A room is a maximal component of cells which share the same letter and which are connected in $4$ directions: up, down, left, right.

You have to answer queries of the type: "How many rooms are completely or partly included in a given rectangular submatrix?".

### Standard input

The first line contains two integers $N$ and $M$.

Each of the following $N$ lines contains $M$ lowercase letters.

On the following line there is an integer $Q$ indicating the number of queries.

The next $Q$ lines contain $4$ integers $x_1$, $y_2$, $x_2$, $y_2$, denoting a rectangle formed by the diagonally opposite points of coordinates $(x_1, y_1)$ and $(x_2, y_2)$.

### Standard output

You should output $Q$ lines, each containing the answer for a query.

### Constraints and notes

$1 \leq N, M \leq 2\ 000$ $1 \leq Q \leq 5\ 000$  $1 \leq x_1, x_2 \leq N$ $1 \leq y_1, y_2 \leq M$ For $50$ points, it is guaranteed that every room can be completely included in every query submatrix (every room can be translated in such a way that it's inside the submatrix). 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 6<br>aabbcc<br>abbbcc<br>cbeaed<br>adeeed<br>affttz<br>3<br>1 1 5 6<br>2 1 4 5<br>3 3 5 6 | 12<br>8<br>6 | There are $3$ queries.The 1 1 5 6 query refers to the whole matrix, which has $12$ rooms.The 2 1 4 5 rectangle contains $8$ rooms, $4$ of which are complete.The 3 3 5 6 rectangle contains $6$ rooms, $5$ of which are complete. |
