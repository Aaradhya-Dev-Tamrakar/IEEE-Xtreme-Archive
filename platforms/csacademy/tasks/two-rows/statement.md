# Two Rows

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/two-rows/](https://csacademy.com/contest/archive/task/two-rows/)  

---

Consider a matrix $A$ with $2$ rows and $M$ columns. A valid path starts in cell $(1, 1)$ and ends in cell $(2, M)$, while only moving up, down or right, without visiting the same cell twice.

There are two players that will choose a valid path, making alternate moves. A move consists of choosing the next cell in the path. They stop when the path reaches the final cell $(2, M)$.

The cost of the path is defined as the sum of its cells. The first player wants to maximize the cost, while the second player wants to minimize it. If both of them play optimally, what will be the cost of the path?

### Standard input

The first line contains a single integer $M$.

Each of the next $2$ lines contains $M$ integers, representing the elements of $A$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq M \leq 10^5$ $-10^5 \leq A_{i, j} \leq 10^5$ The game starts with the first player choosing cell $(1, 1)$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>5 7 9 5 12<br>2 1 2 10 4 | 40 | The path is 5 -> 2 -> 1 -> 2 -> 9 -> 5 -> 12 -> 4. |
| 3<br>1 2 -1<br>-5 -3 2 | -5 | The path is 1 -> -5 -> -3 -> 2. |
| 2<br>1 0<br>2 0 | 1 | The path is 1 -> 0 -> 0. |
