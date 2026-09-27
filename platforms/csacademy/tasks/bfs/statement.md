# Bfs

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bfs/](https://csacademy.com/contest/archive/task/bfs/)  

---

The kids from 402 heard the bell and quickly went outside to play. Seeing a big pole in the middle of the field they thought of the following game. Initially they split in groups of girls and boys (there are $m$ girls and $n$ boys) and then they position themselves somewhere on the field.

Initially the pole is completely vertical (has tilt $0$). Each player has certain force ($B_i$ is the force of the $i^{th}$ boy, $F_i$ is the force of the $i^{th}$ girl). The game goes like this: at each step, either the boy or the girl closest to the pole (with the smallest index) throws a ball to the pole, after which he/she leaves the game. A boy's throw tilts the pole to the right, while a girl's throw tilts the pole to the left. The tilt of the pole changes with a value equal to the player's force.

In order to make sure the game doesn't end disastrously, the pole is not allowed to be tilted (in either direction) more than $S$. The kids are wondering if they can find an order of throws such that this condition is respected.

To make things more interesting, their teacher chooses $Q$ moments when she swaps the order of two consecutive boys or girls. All the swaps are persistent.

You should help the kids decide if there is a valid order of throws after each swap.

### Standard input

The first line contains three integers $n$, $m$ and $S$.

The second line contains $n$ integers representing the force values of the boys.

The third line contains $m$ integers representing the force values of the girls.

The fourth line contains a single integer $Q$.

Each of the next $Q$ lines is of the form $[B|F]\ x\ y$, where $[B|F]$ represents the group of the swap ($B$ stands for the boys' group, $F$ for the girls' group), while $x$ and $y$ are the swapped positions.

### Standard output

Output $Q$ lines, each containing $1$ if the game can be successful, or $0$ otherwise.

### Constraints and notes

$1 \leq n, m, Q \leq 10^5$ $1 \leq S \leq 10^9$ $0 \leq B_i, F_i \leq 10^9$ For every swap $|x-y| = 1$ It is guaranteed that before the first swap the game is successfulFor 10 points $n,m \leq 100$ and  $Q \leq 250$ For another 20 points $n,m \leq 2500$ and  $Q \leq 6000$

| Input | Output |
| --- | --- |
| 6 3 30000<br>15000 15000 60000 30000 29805 56555<br>60000 60000 57187<br>14<br>B 2 3<br>B 2 3<br>B 2 3<br>B 2 3<br>F 2 3<br>F 2 3<br>B 2 3<br>B 2 3<br>B 3 4<br>B 3 4<br>B 2 3<br>B 2 3<br>F 2 3<br>F 2 3 | 0<br>1<br>0<br>1<br>0<br>1<br>0<br>1<br>0<br>1<br>0<br>1<br>0<br>1 |
