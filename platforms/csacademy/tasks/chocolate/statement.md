# Chocolate

**Time Limit:** `5000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/chocolate/](https://csacademy.com/contest/archive/task/chocolate/)  

---

Two people play a game on a $5\times 5$ board. Each cell contains a strictly positive number of chocolate candies. A cell is considered blocked if it has exactly $4$ neighbouring  cells that contain a positive number of candies.

The two players make alternate moves. A move consists of choosing a cell that is not blocked and taking all the candies in that cell. After a move it's possible that some cells that were previously blocked become unblocked. The goal of each player is to take as many chocolate candies as possible. They both play optimally.

### Standard input

The first line contains a single integer $T$ representing the number of tests that follow.

Each of the $T$ tests consists of $5$ lines, each containing $5$ integers representing the initial number of candies in the matrix.

### Standard output

Print the number of candies the first player can take in case of an optimal game for each test on a different line.

### Constraints and notes

$1 \leq T \leq 30$ The matrix values are distinct, in the interval $[1, 35\ 000]$

| Input | Output | Explanation |
| --- | --- | --- |
| 1<br>1  2  3  4  5<br>6  7  8  9 10<br>11 12 13 14 15<br>16 17 18 19 20<br>21 22 23 24 25 | 169 | The first player will take all the odd numbers, in decreasing order. The second player will take all the even numbers, in decreasing order. |
