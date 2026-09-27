# Heroes

**Time Limit:** `400 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/heroes/](https://csacademy.com/contest/archive/task/heroes/)  

---

— Billy, you are wasting your life on computer games!

— That's OK, Mom, I have three lives left!

In the Great Battle to save everything good in this world, $H$ heroes are fighting a horde of $M$ monsters. The combatants are standing in a circle, in a given order. The $i$-th hero is followed on the circle by $m_i$ monsters (such that $m_1 + m_2 + \dots + m_H = M$).

Beginning with the first hero, combatants take turns striking with their swords. A hero may strike any monster, while a monster may strike any hero (anywhere on the circle). A monster that takes $K$ strikes is destroyed. Heroes are invincible.

The heroes are fighting for glory and wish to receive as few strikes as possible. What is the least number of strikes that the heroes must receive before destroying all the monsters?

### Standard input

The first line of input will contain the integers $H$ and $K$, separated by a space.

The second line will contain $H$ space-separated integers, $m_1, m_2, \dots, m_H$.

### Standard output

Output a single integer, the minimum number of strikes that the heroes can receive.

### Constraints and notes

$1\leq H \leq  3\ 000$;$1\leq M \leq 1\ 000\ 000\ 000$;$1\leq K \leq 1\ 000$;$0\leq m_i \leq M$ for $1 \leq i \leq H$;The answer is guaranteed not to exceed $10^{18}$.

#PointsRestrictions17$H \leq 10$, $M \leq 4$, $K \leq 4$211$H \leq 20$, $M \leq 10$, $K \leq 30$315$M \leq 150\ 000$417$M \leq 5\ 000\ 000$519$M \leq 30\ 000\ 000$631No further constraints.

| Input | Output |
| --- | --- |
| 3 1<br>0 3 3 | 3 |
| 3 2<br>0 3 3 | 10 |

### Explanations

In the first example there are $H = 3$ heroes and $M = 6$ monsters with $K = 1$ life each. The initial order is HHMMMHMMM (where H = hero, M = monster). The first two heroes destroy the first two monsters. The third monster strikes. The third hero destroys the fourth monster. The last two monsters strike. The circle is now HHMHMM. The second time around, every hero destroys one monster and the heroes receive no further strikes.
