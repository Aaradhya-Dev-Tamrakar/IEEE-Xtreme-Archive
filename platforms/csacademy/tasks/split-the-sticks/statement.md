# Split the Sticks

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/split-the-sticks/](https://csacademy.com/contest/archive/task/split-the-sticks/)  

---

You have $N$ sticks of various lengths. An operation consists of taking a stick of length $L$, choosing an integer value $X$, $1 \leq X < L$, and spliting the stick in two smaller sticks of lengths $X$ and $L-X$. The goal is to be able to pair up all the sticks in pairs of equal length, while performing at most $N$ operations.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the initial lengths of the sticks.

### Standard output

If there is no solution output $-1$.

Otherwise, on the first line print a single number $M$, $0 \leq M \leq N$ representing the number of operations.

Each of the next $M$ lines should contain two integers: $L$, the length of an existing stick, and $X$.

### Constraints and notes

$1 \leq N \leq 10^5$ The initial lengths of the sticks are integers between $1$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>2 6 8 | 1<br>8 6 | The sticks are as following:2 6 82 6 2 6 |
| 4<br>1 1 6 8 | 2<br>8 1<br>7 1 | 1 1 6 81 1 6 1 71 1 6 1 1 6 |
| 2<br>2 2 | 2<br>2 1<br>2 1 | Note that you can make at most $N$ operations.Note that you can have equal elements. |
| 2<br>1 2 | -1 | There are no valid operations to form pairs of sticks. |
| 6<br>1 2 3 4 4 8 | 2<br>8 4<br>3 2 | 1 2 3 4 4 81 2 3 4 4 4 41 2 1 2 4 4 4 4 |
