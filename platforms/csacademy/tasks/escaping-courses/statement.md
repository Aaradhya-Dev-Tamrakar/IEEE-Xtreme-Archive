# Escaping Courses

**Time Limit:** `3000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/escaping-courses/](https://csacademy.com/contest/archive/task/escaping-courses/)  

---

This problem is about a guy which really wants to skip courses.

There is an university with a very weird room plan (no halls - only interconnected classrooms). More specifically, the university has $N \times M$ classrooms arranged in a grid with $N$ rows and $M$ columns. Our hero is at moment $0$ in cell $(1, 1)$ and he wants to reach the only exit which is in cell $(N, M)$. The rows are indexed from top to bottom, while columns are indexed from left to right. He can move only in rooms which share a common wall and this will take him 1 minute.  Otherwise, he can choose to spend 1 minute in the cell he is currently in.

Additionally, there are classrooms which are under renovation and no student is allowed there. Also, there are some courses which are held in specific classrooms in a given interval of time. There can be multiple non-overlapping courses in the same classroom. However, there is always a pause between them which will last at least $1$ minute. The first course in each cell is guaranteed not to start at moment 0.

Our hero should fulfill his task without visiting any classroom under renovation, or being in any classroom in which a course is currently held. Help him determine the minimum number of minutes he has to spend in the university until he can get to the $(N, M)$ cell, or determine that this cannot be done.

### Standard input

The first line contains the numbers $N$ and $M$.

After that, $N$ lines follow, with $M$ characters each, denoting the grid. A . denotes an eligible classroom, while an # an under renovation one.

On the next line there is the number of restrictions, $R$.

After that, we have $R$ lines, each with 4 integers: $x$ and $y$, the cell coordinates, and $s$ and $t$ the beginning and the end of the course.

### Standard output

The first line should contain a single integer representing the minimum number of minutes our hero has to spend traveling to the target cell, or -1 if our hero cannot reach the $(N, M)$ cell without attending any course or entering a classroom that is under renovation

### Constraints and notes

$1 \leq N, M \leq 2000$ $1 \leq R \leq 10^5$ $1 \leq x \leq N, 1 \leq y \leq M$ $1 \leq s \leq t \leq 10^9$ There are no courses in classrooms $(1, 1)$ and $(N, M)$.There are no courses in classrooms under renovation.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>...<br>.#.<br>...<br>1<br>1 3 2 4 | 4 |  |
| 3 3<br>...<br>.##<br>...<br>2<br>2 1 1 2<br>3 1 4 4 | 7 | Our hero starts at time 0 in the cell $(1, 1)$. He must go to the cell $(2, 1)$ at the 3rd minute (as that cell is occupied in the minutes 1 and 2). He can advance to the cell $(3, 1)$ in the 5th minute (the cell $(3, 1)$ is occupied in the 4th minute). After this, he can go straight to the cell $(3, 3)$, as there are no more courses in the way. |
