# Checkroom Hooks

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/checkroom-hooks/](https://csacademy.com/contest/archive/task/checkroom-hooks/)  

---

A certain checkroom has a single rack with $N + 2$ hooks in a single row; the hooks on the left and right ends are permanently occupied by the coats of the checkroom keepers. The other $N$ hooks are for users.

Whenever someone enters the checkroom, they try to choose a hook that is as far from other coats as possible. For each empty hook $H$, they compute two values $L_H$ and $R_H$, each of which is the number of empty hooks between $H$ and the closest occupied hook to the left or right, respectively. Then they consider the set of hooks with the farthest closest neighbor, that is, those $H$ for which $min(L_H, R_H)$ is maximal. Then they choose a hook from this set uniformly at random and hang their coat on it.

$N$ people are about to enter the checkroom; each one will choose their hook before the next arrives. Nobody will ever leave.

Let's number the entering people from $1$ to $N$ in chronological order, and the hooks for users from $1$ to $N$ from left to right. For each person $i$ and hook $j$, what is the probability that this person occupies this hook?

### Standard input

The only line contains a single integer $N$.

### Standard output

Print $N$ lines containing $N$ real values each, with the $j$-th value in the $i$-th line representing the probability that the $i$-th person occupies the $j$-th hook.

Each of your values is considered correct if its absolute error doesn't exceed $10^{-6}$.

### Constraints and notes

$1 \le N \le 300$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 | 0.000000 1.000000 0.000000<br>0.500000 0.000000 0.500000<br>0.500000 0.000000 0.500000 | The first person always takes the center hook. Out of the two remaining hooks, the second person takes one at random, and the third person takes the other one. |
| 4 | 0.000000 0.500000 0.500000 0.000000<br>0.333333 0.166667 0.166667 0.333333<br>0.333333 0.166667 0.166667 0.333333<br>0.333333 0.166667 0.166667 0.333333 |  |
