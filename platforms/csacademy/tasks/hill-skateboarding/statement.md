# Hill Skateboarding

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/hill-skateboarding/](https://csacademy.com/contest/archive/task/hill-skateboarding/)  

---

You just bought a new skateboard and you want to travel as much as possible. In order to do this you chose a local hill. Now the only thing left to do is to chose a starting position for the journey. The hill is split into $N$ parts, each part being one of the $3$ types:

downhill, coded with a $-1$ flat coded with a $0$ uphill coded with a $1$ 

When you go downhill you gain $2$ points of velocity. If you go uphill you lose $2$ points of velocity and if you travel a flat part you lose $1$ point of velocity.

Note that you are only allowed to travel from left to right.

You stop when you have reached the end of the hill or when you have $0$ velocity and you're on a flat or uphill part of the hill. Check the second example for more explanations.

Considering that you start with $0$ points of velocity and you don't want to make any effort skating, chose a starting position such that the number of traveled parts is maximised. Find out the number of traveled parts.

### Standard input

The first line contains the integer $N$.

The second line contains $N$ integers representing the codification of the hill. Each element is one of ${-1, 0, 1}$.

### Standard output

The first line should contain one number, the maximum number of parts that can be traveled.

### Constraints and notes

$1 \leq N \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>-1 0 1 | 2.5 | The points represents the skaters's start and finish position.00.511.522.533.5401234startfinish |
| 6<br>-1 1 -1 1 -1 1 | 6 | 01234567801234startfinish |
| 12<br>0 -1 -1 1 0 -1 0 1 1 1 -1 -1 | 7 | 0246810120123456startfinish |
