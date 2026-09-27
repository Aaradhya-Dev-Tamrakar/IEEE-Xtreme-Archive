# Robot in a Labyrinth

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/robot-in-a-labyrinth/](https://csacademy.com/contest/archive/task/robot-in-a-labyrinth/)  

---

Consider a rectangular field divided into $R$ rows and $C$ columns of square cells. Some of these cells are free, other contain walls.

A robot starts in a free cell $S$ and has to reach another free cell $T$. The robot's program is a single string of commands. This string can only contain characters $U$, $D$, $L$ and $R$, meaning "move up", "move down", "move left", "move right" one cell.

The robot can either execute the whole string character by character, which costs $0$ gold, or any subsequence of this string, which costs $1$ gold. It is not allowed to execute a string if at some point during the execution robot will either try to go into a cell containing a wall or will move outside the field.

What is the minimum amount of gold required to reach cell $T$?

### Standard input

The first line contains three integers $R$, $C$ and $N$, representing number of rows and columns in the field, and the length of string of commands respectively.

Next $R$ lines contain $C$ characters each, representing the field. Empty cells are denoted as ., walls are denoted as #. Starting and finishing locations are denoted as S and T, respectively.

The next line contains the string of commands consisting of letters $U$, $D$, $L$ and $R$.

### Standard output

Print a single integer, representing the minimum amount of gold required to reach cell $T$.

If it is impossible to reach $T$, print $-1$.

### Constraints and notes

$1 \le R, C \le 500$ $2 \leq R * C$ $1 \le N \le 10^6$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 4 4<br>.S..<br>##..<br>...#<br>#T##<br>RRDL | 2 | We can apply RRDL for 0 gold, then DL for 1 gold, then D for 1 gold. |
| 2 1 3<br>S<br>T<br>RUL | -1 |  |
| 1 10 6<br>S........T<br>LLRRRR | 1 |  |
