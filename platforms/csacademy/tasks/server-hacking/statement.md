# Server Hacking

**Time Limit:** `3000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/server-hacking/](https://csacademy.com/contest/archive/task/server-hacking/)  

---

You are a hacker that wants to break into a server. Before hacking the server, however, you must get to it. The server is located in a room that, seen from above, can be described as a $N\times M$ matrix. You enter the server room through the ceiling, at position $(r, c)$. Your goal is to reach a point beyond column $M$, where the server is. The problem you face is that there are some moving doors on several columns. The room looks like this:

12345612345678910Server

From position $(r, c)$ you can only move to one of the positions $(r, c+1)$, $(r-1, c+1)$, $(r+1, c+1)$. You cannot move backwards, on the same column or stay in the same place.

The doors move vertically and for each of them you know the initial direction (up or down). When a door hits one of the room's walls, it changes direction.

Both you and the doors move with a speed of one cell a second.

When you get to a column that has a door you are required to be located on a cell where the door is. There is never more than one door on any column.

Can you reach the server under these conditions?

### Standard input

The first line contains $3$ integers $N$, $M$ and $D$, representing the height and width of the room, as well as the size of the doors (all the doors share the same size).

The second line contains a number $K$, representing the number of doors.

Each of the next $K$ lines contains three integers $R\ C\ S$, describing a door. $R$ and $C$ represent the row and the column of the topmost cell of the door. $S$ can be either $-$ or $+$ and it describes the initial direction of the door ($-$ for up and $+$ for down).

The next line contains a number $Q$, representing the number of queries to follow.

Each of the next $Q$ lines contains two integers $r$ and $c$, representing your starting point as the hacker.

### Standard output

Output $Q$ lines, each contains a single integer representing the answer for a query. Print $1$ if you can reach the server, or $0$ otherwise.

### Constraints and notes

$1 \leq D \leq N \leq 500$$2 \leq M \leq 10^8$$1 \leq K \leq 10^5$$K < M$$1 \leq Q \leq 10^5$$1 \leq r \leq N$$1 \leq c \leq M$There is no door on column $M$For each query you start on a column without a door.

You can view the movements of the hacker for the first query in the example below:

12345612345678910ServerH

| Input | Output |
| --- | --- |
| 6 10 2<br>2<br>3 8 -<br>4 3 +<br>6<br>4 2<br>3 2<br>1 1<br>1 7<br>3 8<br>5 6 | 1<br>0<br>0<br>1<br>1<br>0 |
