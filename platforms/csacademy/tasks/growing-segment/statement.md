# Growing Segment

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/growing-segment/](https://csacademy.com/contest/archive/task/growing-segment/)  

---

You are given a segment of length $L$ on the $OX$ axis having it's left corner in point $0$. There are $N$ tasks that need to be done in order. Each of them is characterised by an integer $X_i$, the coordinate on the $OX$ axis. A task is considered completed if the segment touches the tasks point or if the tasks point is inside the segment. You can move the segment left or right on the $OX$ axis. What is the minimum distance that the segment needs to be moved in order to complete all $N$ tasks, in order?

Consider the following $Q$ independent scenarios. For the given set of tasks, what is the minimum distance that the segment needs to be moved if the segment has a length of $L_i$?

### Standard input

The first line contains two integers $N$ and $Q$.

The second line contains $N$ integers, the coordinates of the tasks, in order.

The third line contains $Q$ integers, the values $L_i$ of the scenarios.

### Standard output

You should print $Q$ lines, the $i_{th}$ line containing the minimum distance that the segments needs to be moved if it's length would be $L_i$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq Q \leq 10^5$ $-10^9 \leq X_i \leq 10^9$ for each $1 \leq i \leq N$ $0 \leq L_i \leq 10^9$ for each $1 \leq i \leq Q$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 9 6<br>2 -3 -1 1 2 3 5 3 7<br>0 1 2 3 4 5 | 21<br>16<br>11<br>10<br>9<br>8 | A visual representation for $L = 3$ can be found below.For simplicity, the $i_{th}$ task is represented at coordinate $y = i$.For each task, the positions of the segment is represented.Summing up the distance that the segment was moved, we obtain:$0+3+0+1+1+1+2+0+2 = 10$Note that for tasks $1$, $3$ and $8$ the segment doesn't need to move, since the task is already covered by the segment.-4-2024680246810123456789 |
| 8 8<br>5 0 5 15 0 -10 0 -20<br>20 15 14 11 10 5 1 0 | 20<br>20<br>22<br>28<br>30<br>50<br>74<br>80 |  |
