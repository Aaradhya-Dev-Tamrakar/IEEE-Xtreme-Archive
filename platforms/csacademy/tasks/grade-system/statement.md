# Grade System

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/grade-system/](https://csacademy.com/contest/archive/task/grade-system/)  

---

Considering a set of $N$ grades, an interesting grading system consists of removing one of the minimum and one of the maximum values, and then finding the arithmetic mean of the rest of the $N-2$ grades.

Given a set of $N$ grades, print the result of the grading system.

### Standard input

The first line contains of a single integer $N$.

The second line contains $N$ integers representing the grades.

### Standard output

Print the greatest integer that is less or equal to the answer given by the grading system.

### Constraints and notes

$3 \leq N \leq 100$ The grades are integers in the interval $[1, 100]$ 

| Input | Output |
| --- | --- |
| 5<br>3 5 7 1 2 | 3 |
| 7<br>2 2 2 3 4 4 4 | 3 |
| 3<br>1 1 1 | 1 |
