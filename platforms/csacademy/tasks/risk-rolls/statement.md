# Risk Rolls

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/risk-rolls/](https://csacademy.com/contest/archive/task/risk-rolls/)  

---

Alena and Boris are playing Risk today. We'll call an outcome the sum of values on the faces of $1$ or more rolled dice. Alena has $N$ possible outcomes whilst Boris has $M$. In turns, each one of them will choose their best possible available outcome and play it. If Alena's outcome is strictly greater than Boris's, then Alena wins; otherwise Boris wins. Whenever one of them runs out of outcomes, the game ends.

In how many turns does Alena win? What about Boris?

### Standard input

The first line contains two integers $N$ and $M$.

The second contains $N$ integers, Alena's possible outcomes.

The third line contains $M$ integers, Boris's possible outcomes.

### Standard output

Print two integers $A$ and $B$ on the first line of the output; $A$ represents the number of turns won by Alena and $B$ the number of turns won by Boris.

### Constraints and notes

$1 \leq N, M \leq 10$ $1 \leq v \leq 24$, where $v$ is a possible outcome value

| Input | Output | Explanation |
| --- | --- | --- |
| 1 3<br>24<br>1 2 3 | 1 0 | In the first turn, Alena will play $24$, which will beat Boris's $3$ |
| 3 1<br>2 1 3<br>24 | 0 1 | This is the first sample with reversed outcomes for Alena and Boris. |
| 2 2<br>10 1<br>5 5 | 1 1 |  |
| 4 3<br>3 4 5 24<br>9 9 9 | 1 2 | In the first turn Alena will beat Boris because she will play $24$. |
| 3 3<br>8 9 10<br>10 8 8 | 1 2 | In the first turn they will play $10$ against $10$ and Boris will win. On the second turn they will play $9$ versus $8$ and Alena will win. The third turn is also won by Boris. |
