# Expected Dice

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/expected-dice/](https://csacademy.com/contest/archive/task/expected-dice/)  

---

You have two special dice with $6$ faces, each. For each dice you know the numbers written on each face.

You roll the two dices at the same time, and you add up the numbers showing on the upper faces. What is the most probable sum value you'll get?

### Standard input

The first line contains $6$ integers representing the numbers on the first dice.

The second line contains $6$ integers representing the numbers on the second dice.

### Standard output

Print the answer on the first line. If the solution is not unique, print the smallest one.

### Constraints and notes

The numbers on the dice are integers between $1$ and $50$

| Input | Output | Explanation |
| --- | --- | --- |
| 1 2 3 4 5 6<br>1 2 3 4 5 6 | 7 | There are $6$ ways to roll the dices to make the sum $7$. $\{1, 6\}$, $\{2, 5\}$, $\{3, 4\}$, $\{4, 3\}$, $\{5, 1\}$ and $\{6, 1\}$The other sums have a smaller change to appear. For example, the only way to make $2$ is $\{1, 1\}$ |
| 1 1 1 1 1 1<br>1 1 2 2 3 3 | 2 | The first dice will always roll $1$, and the second one will roll with the same probability $1, 2\ \text{and}\ 3$. All the sums ($2,\ 3,\ 4$)  have the same chanche to be rolled, so the answer is the lowest one ($2$) |
| 1 1 1 1 1 1<br>1 1 2 3 3 3 | 4 | The first dice will always roll $1$ but for the second dice, number $3$ is more encountered. This makes sum $4$ the most common sum (appearing in $50\%$  or the cases). |
