# Cosmological Nightmare

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cosmological-nightmare/](https://csacademy.com/contest/archive/task/cosmological-nightmare/)  

---

Alex likes astronomy: every night he looks at the sky and tries to see how the position of the stars differs. He is certain that every night all the stars move with a vector $(u, v)$ compared to the previous position (the same vector for every star). To prove this he drew the position of the stars in two different nights.  However, he accidentally spilled water over the two sheets he had drawn and the two drawings merged in a weird way.

Now, a point is present in the final drawing if and only if it belonged to exactly one of the two initial drawings.

He gives you the list of the $N$ points from the final drawing along with a set of $M$ translation vectors and asks you which of these vectors can represent the vector with which the stars were translated.

In other words, you should output "YES" if there is an initial set of points which, after translation with the vector given in query and merging the two sets, it results the points from input.

  

### Standard input

The first line contains a single integer $N$. Each of the next $N$ lines describe one point $(x, y)$. The line contains two integers $x$ and $y$.

The next line contains a single integer $M$. Each of the next $M$ lines contains two integers $u$ and $v$ which represents the translation vector $(u, v)$.

  

### Standard output

You have to print $M$ lines, the $i$-th line contains either "YES" (without quotes) if the answer for the $i$-th query is yes, or "NO" (without quotes) otherwise.

  

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq M \leq 10$ $-10^9 \leq x,y,u,v \leq 10^9$ All points are distinct. 

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>0 0<br>5 0<br>0 5<br>10 5<br>10 10<br>5 10<br>3<br>5 5<br>-5 -5<br>10 10 | YES<br>YES<br>NO | For the query 5 5, the first drawing can be [(0,0) (5,0) (5,5) (0,5)] and this translated with the vector (5,5) is [(5,5) (10,5) (10,10) (5,10)]. The merged drawing for this two sets is [(0, 0) (5, 0) (0, 5) (10, 5) (10, 10) (5, 10)]. |
| 6<br>0 0<br>6 0<br>12 0<br>0 4<br>6 4<br>12 4<br>4<br>0 4<br>6 0<br>3 0<br>0 2 | YES<br>NO<br>NO<br>YES | For the query 0 2, the first drawing is [(0, 0) (6, 0) (12, 0) (0, 2) (6, 2) (12, 2)] and this translated with the vector (0, 2) is [(0, 2) (6, 2) (12, 2) (0, 4) (6, 4) (12, 4)]. The merged drawing for this two sets is [(0, 0) (6, 0) (12, 0) (0, 4) (6, 4) (12, 4)]. |
| 2<br>0 0<br>4 -2<br>2<br>-4 2<br>-4 -2 | YES<br>NO |  |
