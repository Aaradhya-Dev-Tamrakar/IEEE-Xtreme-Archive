# Sugarel’s Garden

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/Sugarel-s-Garden/](https://csacademy.com/contest/archive/task/Sugarel-s-Garden/)  

---

Years passed by and Sugarel got older, leaving the idea of having a girlfriend behind. Now, he is a changed man and has a completely new passion: gardening !

In his very big yard, he has $N$ available spots at positive integer coordinates and intends to plant $M$ daisies in those. He cares a lot about daisies, so he thought of setting up a fence in the form of a quadrilateral to protect the flowers from his only friend, Barry - The Dog, using some of the spots as its vertices.

We love dogs and we don’t want to cut off too much of Barry’s playground, so Sugarel is asking for your help (as his previous attempts to solve algorithmic problems were not successful).

Your task is to find the minimum area that can be protected by fence which contains exactly $M$ points strictly inside where Sugarel can plant his mesmerizing daisies. Note that points on the border of the quadrilateral do not count.

### Standard input

The first line contains two integers $N$ and $M$.

Each of the following $N$ lines contains two integer values representing the coordinates of the points.

### Standard output

The output  should contain of a single float value with exactly one digit after decimal point representing the minimum area found.

### Constraints and notes

$5 \leq N \leq 300$ $1\leq M\leq N-4$ The  coordinates of the points are integers between  $0$ and  $2*10^5$ All points are distinct and there are no three collinear points.It is guaranteed that there exists at least one quadrilateral to contain M points.The answer should be printed with exaclty one digit after decimal point.

| Input | Output | Explanation |
| --- | --- | --- |
| 10 3<br>3 2<br>7 6<br>10 6<br>7 12<br>4 11<br>12 8<br>14 4<br>15 12<br>13 7<br>15 3 | 27.0 | For the first sample test:0246810121416051015ABCD |
| 5 1<br>0 0<br>4 0<br>4 4<br>0 4<br>2 3 | 16.0 |  |
