# Ricocheting Balls

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/ricocheting-balls/](https://csacademy.com/contest/archive/task/ricocheting-balls/)  

---

There are $N$ falling balls situated at some height levels; more specifically the $i^{\text{th}}$ ball is $H_i$ meters above the ground. The balls are supposed to be falling at $1$ meter per second, but they're not; they're stuck in time, hovering.

You can repeat the following process as many times as you want (possibly $0$ times): you will unfreeze the time for $1$ second and then freeze it back up.

If a ball hits the ground, which is situated at the height level $0$, it will ricohet and start ascending instead; therefore, the next time it is unfrozen, it will actually go upwards to the height level $1$, then $2$, $3$, $4$ and so on...

You want to find the moment of time that minimizes the sum of heights of all the balls. Print the value of the sum obtained at this moment of time.

### Standard input

The first line contains an integer $N$.

The next line contains $N$ integers, representing $H$.

### Standard output

Print an integer, the minimum sum of heights of all balls that can be obtained by the above-described process.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq H_i \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 4 5 2 | 6 | Moment of time $0$: $[1, 4, 5, 2]$, summing to $12$.Moment of time $1$: $[0, 3, 4, 1]$, summing to $8$. Moment of time $2$: $[1, 2, 3, 0]$, summing to $6$. We can notice how the first ball starts ascending, after it hit the ground.Moment of time $3$: $[2, 1, 2, 1]$, summing to $6$. |
| 9<br>1 7 1 1 1 5 3 6 3 | 17 |  |
