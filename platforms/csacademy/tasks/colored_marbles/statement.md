# Colored Marbles

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/colored_marbles/](https://csacademy.com/contest/archive/task/colored_marbles/)  

---

Alex has a bag of colored marbles. Ben would like to estimate the total number of marbles in the bag. In order to help Ben, Alex agreed to choose $N$ different marbles and say for each one the total number of marbles of the same color in the bag.

Ben cannot see the colors of the chosen marbles, but he knows Alex will lie to him exactly once. Help Ben estimate the minimum possible number of marbles in the bag.

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consits of two lines:

The first line contains a single integer $N$, the number of chosen marbles.The second line contains the $N$ values given by Alex.

### Standard output

The output will contain the answer for each test case on a different line.

### Constraints and notes

$1 \leq T \leq 10$$1 \leq N \leq 10^5$The sum of all the values of $N$ in an input file is  $\leq 10^5$The values given by Alex are be between $1$ and $10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>4<br>2 2 2 2<br>5<br>2 2 2 3 3 | 5<br>5 | Suppose the bag contains 2 red marbles, 2 blue and 1 green. Let's say Alex chooses a red one, a blue one, then again a red one and finally the green one. He lies the last time, saying 2 instead of 1. This is not the only possible solution, but there aren't any others with smaller number of marbles.Suppose the bag contains 2 red marbles and 3 blue ones. Alex chooses red, red, blue, blue and blue, lying the third time. |
