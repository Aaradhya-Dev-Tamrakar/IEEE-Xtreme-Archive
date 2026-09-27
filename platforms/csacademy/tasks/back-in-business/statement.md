# Back in Business

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/back-in-business/](https://csacademy.com/contest/archive/task/back-in-business/)  

---

Before the start of the contest, the judges were very busy playing games, consuming pizza, and making jokes about each other. However, at some point, they realized that they have a problem.  They will, at some point, have to get from their house to the university, where the contest will take place, in order to do some actual work. And now, the city is crowded with contestants!

The big problem with Romanian programming contests is that judges are usually acclaimed by contestants, with slogans that we will not reproduce here. And having that before the start of the contest might bring bad luck. As our judges do not like taking such risks, they would want to pass as far away from any contestant as possible. Fortunately, their good friend and accomplice Georgel accepted to scout the surrounding area, and managed to draw a map of where the contestants will be during the "mission".

Having the map written by Georgel, your task is to find a path such that over the whole track, the distance to the contestants is as big as possible. Formally, you want to maximize the minimum distance between the judges and each of the contestants at each moment in time.

The distance between two cells $(x_1, y_1)$ and $(x_2, y_2)$ is defined as $|x_1-x_2| + |y_1 - y_2|$, where $|x|$ denotes the absolute value of $x$. The judges can only move from a point $(x, y)$ to one of the four neighbouring cells: $(x - 1, y)$, $(x + 1, y)$, $(x, y - 1)$, $(x, y + 1)$, and they are not allowed to bump into other contestants along their route.

### Standard input

The first line of input contains two positive integers $N$ and $M$ - the dimensions of the map.

On each of the next $N$ lines there are $M$ characters, that represent the type of each of the cells:

 . means that the cell is empty. P means that the cell is occupied by a contestant. F means that in that cell is the university (the cell in which the judges need to get to). S means that in that cell is the judges' house. 

### Standard output

You must print a single integer, the answer to the problem: the maximal minimum distance possible. If it is not possible to reach the university without bumping into contestants, output impossible.

### Constraints and notes

$2 \leq N, M \leq 1000$ It is guaranteed that there is at least one contestant on the map.It is guaranteed that there are exactly one S cell and exactly one F cell on the map.

| Input | Output | Explanation |
| --- | --- | --- |
| 5 7<br>S...PPP<br>.......<br>.......<br>......F<br>P...... | 3 | One possible way is the following:1  ההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |
| 2 6<br>S..P..<br>..P..F | impossible |  |
