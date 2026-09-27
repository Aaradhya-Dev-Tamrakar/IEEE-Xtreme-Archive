# Cats

**Time Limit:** `500 ms`  
**Memory Limit:** `16 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cats/](https://csacademy.com/contest/archive/task/cats/)  

---

### Description

Alex has $N$ pets arranged in a straight line. The pets are of three types: cats, dogs and lions. As we all know, cats and dogs do not really like each other, but lions get along with both. Each move, Alex can take one pet and move it somewhere else in the row.

Alex would like to know the minimum number of moves necessary to rearrange the pets such that there are no cats and dogs next to each other.

### Task

Develop a program to calculate the minimum number of moves necessary to rearrange the pets such that there are no cats and dogs next to each other.

### Input

The first line of the standard input contains a single integer $T$ representing the number of independent test cases you need to solve.

Each test is represented on two lines of the standard input:

The first line contains a single integer $N$.The second line contains $N$ integers separated by a space, corresponding to the initial arrangement of the pets. A cat is represented by a $0$, a dog by a $1$, and a lion by a $2$.

### Output

The standard output shall contain a different line for each test case. If there is no way to perform the task print a single integer $-1$. Otherwise, output the minimum number of moves necessary to rearrange the pets.

### Constraints

$1 \leq T \leq 500$ $1 \leq N \leq 5000$ The sum of all N in the standard input of a single test is less than or equal $5000$.

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>5<br>0 1 0 1 2<br>9<br>0 0 0 1 1 2 0 0 2 | 2<br>1 | In the first test case, we move the 2 dogs to the end of the line. In the second test case, we move the last lion before the  first dog |
