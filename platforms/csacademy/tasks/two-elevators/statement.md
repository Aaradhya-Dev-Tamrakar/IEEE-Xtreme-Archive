# Two Elevators

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/two-elevators/](https://csacademy.com/contest/archive/task/two-elevators/)  

---

A building has $N$ floors numbered from $1$ to $N$ and two elevators. There are $N$ people waiting for the elevators. For the $i^{th}$ person you know two values $A_i$ and $B_i$, representing the current floor and the floor where that person wants to get to.

For each elevator you know its initial floor and you can choose whether it will go down to the $1^{st}$ floor or up to the $N^{th}$ one. The $i^{th}$ person can take an elevator if it passes through $A_i$ and later goes through $B_i$.

What is the maximum number of people that can take at least one of the elevators?

### Standard input

The first line contains three integers $N$, $E_1$ and $E_2$. The last two values represent the initial floors of the elevators.

Each of the next $N$ lines contains two integers $A_i$ and $B_i$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq E_1, E_2 \leq N$ $1 \leq A_i, B_i \leq N$ $A_i \neq B_i$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1 4<br>2 3<br>4 1<br>1 2<br>3 2 | 4 | The first elevator will go up and the second one will go down, so every person can take one elevator. |
| 6 5 3<br>2 3<br>4 6<br>6 2<br>6 5<br>1 4<br>4 6 | 2 | If the second elevator will go up, the second and sixth people can take it. There is no way to have more people that can take at least one elevator. |
