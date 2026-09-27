# Soldiers

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/soldiers/](https://csacademy.com/contest/archive/task/soldiers/)  

---

In this task you are dealing with a group of $N$ soldiers. You know their heights are pairwise distinct, but you can't tell the difference. You also know the soldiers are from two different battalions.

You would like to establish the composition of the battalions. In order to help you achieve your goal, each soldier is willing to tell you two things: the number of solders taller than him from his battalion and the number of soldiers shorter than him from the other battalion.

A solution can be represented as a binary array of size $N$, where the $i$-th value tells if soldier $i$ is from the first or the second battalion. Compute the total number of solutions, and also output the lexicographically smallest one.

### Standard input

The first line contains an integer T representing the number of test cases that will follow.

Each test case respects the following format:

The first line contains a single integer value $N$Each of the following $N$ lines contains two integers between $0$ and $N-1$. The first integer represents the number of soldiers taller than soldier $i$ from his battalion, while the second integer represents the number of soldiers shorter than soldier $i$ from the other battalion.

### Standard output

For each test case output two lines:

The first line of the output should contain a single integer representing the number of possible solutions. As this number can be very large, output its value modulo $10^9+7$.The second line should contain a binary array of $N$ elements representing the lexicographically smallest solution.

### Constraints and notes

$1 \leq T \leq 20\ 000$The sum of $N$ in the file is between $1$ and $10^5$The soldiers always tell the truth, so there will be at least one solution.You should also count solutions where all the soldiers are from the same battalion, if it's the case.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1<br>0 0<br>2<br>0 1<br>0 0<br>8<br>5 0<br>4 1<br>3 1<br>2 1<br>1 1<br>1 1<br>0 6<br>0 1 | 2<br>0<br>2<br>01<br>4<br>00000110 | For the first test case the soldier can be in either battalion $0$ or $1$.For the second test case the solutions are $01$ and $10$.For the third case the solutions are:$00000110$$00001010$$11111001$$11110101$ |
