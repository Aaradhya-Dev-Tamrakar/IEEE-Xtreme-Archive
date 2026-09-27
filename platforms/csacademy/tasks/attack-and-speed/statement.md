# Attack and Speed

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/attack-and-speed/](https://csacademy.com/contest/archive/task/attack-and-speed/)  

---

You are playing a game where your character has two main characteristics : attack and speed. Your current attack level is $A$ and the current speed level is $S$.

You also have $K$ dollars. Each dollar can be used to either increase the attack by $X$, or the speed by $Y$. Your goal is to spend all the dollars and bring the attack and speed at the same level.

### Standard input

The first line contains $5$ integers $A$, $S$, $K$, $X$, $Y$.

### Standard output

If you can achieve the goal, print a single integer representing the number of dollars you spend to increase the attack level.

If there is no solution, output $-1$.

### Constraints and notes

$1 \leq A, S, K, X, Y \leq 10^9$ You are required to spend all the money

| Input | Output | Explanation |
| --- | --- | --- |
| 14 12 6 3 2 | 2 | For Attack, using $2$ dollars $14 + 2 * 3 = 20$For Speed, using the remaining $4$ dollars $12 + 4 * 2 = 20$ |
| 12 46 17 11 6 | 8 | For Attack, using $8$ dollars $12 + 8 * 11 = 100$For Speed, using the remaining $9$ dollars $46 + 9 * 6 = 100$ |
| 46 12 17 9 8 | 6 | For Attack, using $6$ dollars $46 + 6 * 9 = 100$For Speed, using the remaining $11$ dollars $12 + 11 * 8 = 100$ |
| 53 31 17 9 8 | -1 | You need to spend all $K$ dollars.It's possible to make Attack and Speed equal using $7$ dollars, but you can't do that with $17$ dollars. |
