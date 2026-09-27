# Card Collecting Game

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/card-collecting-game/](https://csacademy.com/contest/archive/task/card-collecting-game/)  

---

Two players are playing a game with a set of cards. There are $T$ types of cards. Every $a_{i}$ copies of type $i$ cards will earn you $v_{i}$ points. There are $q_{i}$ copies of type $i$ cards in total. Each player knows the total number of cards of each type. The game proceed as follows :

Player $1$ splits the $N = q_{1} + q_{2} + ... + q_{T}$ cards into $2$ piles of $\frac{N}{2}$ cards. Call the piles Pile $1$ and Pile $2$ (Player $1$ gets to decide which is Pile $1$ and which is Pile $2$)Player $1$ and Player $2$ takes turns taking cards from Pile $1$. Player $1$ starts first. After finishing, the players count the total score they can form using the cards they picked and add it to their total score.Player $1$ and Player $2$ takes turns taking cards from Pile $2$. Player $2$ starts first. After finishing, the players count the total score they can form using the cards they picked (note that the cards from Pile $1$ aren't counted here) and add it to their total score.

Player $1$'s goal is to maximize his score while Player $2$ wants to minimize Player $1$'s score. Find the maximum score Player $1$ can achieve if they both play optimally.

### Standard input

The first line of input contains a single integer $T$, denoting the number of types of cards.

The next $T$ lines of input contains $3$ space-separated integers, where the $i$-th line contains the integers $a_{i}, q_{i}, v_{i}$.

### Standard output

Output a single integer, the maximum score that can be achieved by Player $1$ if both players play optimally.

### Constraints and notes

$1 \le T \le 2000$ $1 \le a_{i} \le a_{1} + a_{2} + ... + a_{T} \le 2000$ for all $i$. $1 \le v_{i} \le 3000$ for all $i$.$1 \le q_{i} \le q_{1} + q_{2} + ... + q_{T} \le 500000$ for all $i$.$q_{1} + q_{2} + ... + q_{T}$ is even.

| Input | Output | Explanation |
| --- | --- | --- |
| 1<br>7 26 2261 | 2261 | For this sample, there is only one way to partition all the cards into two equal piles, which is giving $13$ cards to each pile.It is clear that no matter how the players choose the cards they take each turn, the result is the same. Namely,For pile $1$, Player $1$ will get $7$ cards of type $1$ and Player $2$ gets $6$ cards of type $1$. Player $1$ gets $\lfloor\frac{7}{7}\rfloor \cdot 2261 = 2261$ points.For pile $2$, Player $1$ will get $6$ cards of type $1$ and Player $2$ gets $7$ cards of type $1$. Player $1$ gets $\lfloor\frac{6}{7}\rfloor \cdot 2261 = 0$ points.The total score for player $1$ is $2261 + 0 = 2261$. |
| 2<br>3 6 7<br>2 4 8 | 15 | Player $1$ should partition the set into two piles, where the first pile contains $5$ cards of type $1$ and the second pile contains $1$ card of type $1$ and $4$ cards of type $2$. For the first pile, Player $1$ gets $3$ cards of type $1$ and will get $\lfloor\frac{3}{3}\rfloor \cdot 7 = 7$ points here.For the second pile, Player $1$ gets $2$ cards of type $2$ only if Player $2$ plays optimally. Thus, he will get $\lfloor\frac{2}{2}\rfloor \cdot 8 = 8$ points here.The total number of points he can get is $15$ points. |
