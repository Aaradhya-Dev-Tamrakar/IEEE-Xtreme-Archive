# Final D

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/final-d/](https://csacademy.com/contest/archive/task/final-d/)  

---

### Statement

Alex plays a dungeon game that he enjoys very much. This game has a lot of rooms and the map looks like a matrix with $N \times M$ cells. His final objective is to beat the boss, but, in order to do that, Alex needs to craft a sword with a specific length to kill him.

In every room, Alex can find a fragment for his sword. More precisely, the fragment that can be found in the room placed at the $i$-th row and $j$-th column is of size $i \times M+j$. Note that the rooms start at position $(0,0)$.

Alex knows how big the sword must be, but he is looking to travel as quickly as possible, meaning that he is looking to find a sub-rectangle of rooms from which he can craft the sword with the specific size. When he finds fragments, the sword would increase in length with that fragment's size.

Your task is to help Alex determine the smallest possible area of a sub-rectangle of rooms from which he can craft the sword to beat the boss. If there's no such sub-rectangle, you should output $-1$.

### Standard input

There is a single line that contains three integers, $N$, $M$ and $L$, denoting the number of rows, columns, and the length of the sword that needs to be crafted.

### Standard output

Output one integer, the smallest area of the sub-rectangle, or $-1$ if there is no such sub-rectangle.

### Constraints and notes

$1 \le N,M \le 10^6$ $1 \le L \le 10^{12}$ $0 \le i \le N-1$ $0 \le j \le M-1$ 

| Input | Output |
| --- | --- |
| 42 18468 6335026501 | -1 |
| 32663 32758 20038012860 | 20 |
