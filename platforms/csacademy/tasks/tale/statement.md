# Tale

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/tale/](https://csacademy.com/contest/archive/task/tale/)  

---

### Description

Every year, in the middle of summer, a short-stature king, called Statu Palmă Barbă Cot, gives a feast in his castle at which all the knights from the Balkan countries are invited. Făt Frumos is one of the guests, and, like a true knight, he rides to the feast on his fairy horse, named Flămânzilă. Horses are forbidden inside the castle, therefore Făt Frumos intends to tie up Flămânzilă to one of the trees nearby, outside the castle. Flămânzilă is very quiet as long as it has something to eat (its favourite grass grows everywhere), but, after it grazes all the reachable grass, it becomes nervous and begins to blow  fire, like a dragon. At such a point, Făt Frumos has to leave the feast in order to calm his quadruped companion.

In order to prevent Flămânzilă from causing a fire, Făt Frumos needs to know the area of the figure within which it can move. The figure is shaped by:

the tree to which the horse is tied up (a point of integer coordinates $X_c, Y_c$);the length of the rope $L$ (a positive integer);the wall of the castle that the horse cannot jump over (the wall forms a convex polygon with $N$ edges).

### Task

Write a program to calculate the area of the  gure within which Flămânzilă can move.

### Input

The standard input contains, on the first line, three integers $X_c$, $Y_c$, and $L$, separated by a space - the coordinates of the tree to which the horse will be tied up and the length of the rope.

The second line contains the positive integer $N$ - the number of vertexes in the polygon.

$N$ lines follow, each of them containing two integers $X_i, Y_i\ (i = 1, ..., N)$, separated by a space - the vertexes of the polygon, given clockwise.

### Output

The standard output will contain a real number with five decimals - the area of the figure within which Flămânzilă can move.

### Constraints

$-10000 \leq X_i, Y_i \leq 10000\ (i = 1, ..., N)$ $-10000 \leq X_c, Y_c \leq 10000$ $3 \leq N \leq 300$ $1 \leq L \leq 10^5$ 

### Subtasks

For 10 points: The length of the rope does not exceed the distance from the tree to the wallFor 60 points: The length of the rope does not exceed the half-perimeter of the wallFor 30 points: The length of the rope allows reach all the points on the polygon edges, making a combined cover in two directions: clockwise and anticlockwise. However, each of the invisible vertices of the polygon (a vertex is invisible if the segment joining it with the tree intersects the polygon in an interior point) can be reached from no more than one direction.

### Note

Results will be evaluated with a precision $\varepsilon = 1.0$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3 1<br>4<br>3 5<br>6 7<br>8 5<br>7 2 | 3.14159 |  |
| 5 5 4<br>4<br>4 7<br>7 9<br>9 7<br>8 4 | 36.71737 |  |
