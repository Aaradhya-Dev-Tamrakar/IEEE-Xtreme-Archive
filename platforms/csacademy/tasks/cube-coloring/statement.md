# Cube Coloring

**Time Limit:** `1000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cube-coloring/](https://csacademy.com/contest/archive/task/cube-coloring/)  

---

You have a cube and $N$ types of paint. The paint comes in different quantities. For each type of paint you know the number of faces of the cube that can be painted using that type of paint.

You want to paint the cube such that any two faces that share an edge are painted in different colors. Count the number of distinct colored cubes you can obtain. Two cubes are considered identical if one can be rotated in order to get the other one.

### Standard input

The first line contains a single integer $N$, the number of types of paint.

The second line contains the $N$ values, representing the number of faces of the cube that can be painted using each type of paint.

### Standard output

The output should a single value representing the number of possible cubes that can be obtained.

### Constraints and notes

$1 \leq N \leq 1000$A type of paint can be used to paint between $1$ and $6$ faces of the cube.

| Input | Output |
| --- | --- |
| 8<br>1 1 1 1 1 1 1 2 | 945 |
