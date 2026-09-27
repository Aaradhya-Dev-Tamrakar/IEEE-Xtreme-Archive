# Game of Chance

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/game-of-chance/](https://csacademy.com/contest/archive/task/game-of-chance/)  

---

Alex and Ben are investors in the stock market. Initially Alex has $A$ dollars and Ben has $B$ dollars. Every second each of the two either wins or loses $1$ dollar. Decide who has more money after $N$ seconds.

### Standard input

The first line contains three integers $N$, $A$ and $B$.

The second line contains $N$ integers representing the wins and losses of Alex. The integers are either $1$, in case of win, or $-1$, in case of a loss.

The third line contains $N$ integers representing the wins and losses of Ben. The integers are either $1$, in case of win, or $-1$, in case of a loss.

### Standard output

If Alex has more money in the end print $1$. If Ben has more money print $2$. If they have the same amount print $0$.

### Constraints and notes

$0 \leq A, B \leq 1000$ $1 \leq N \leq 1000$ It is guaranteed neither of them will ever have a negative amount of money

| Input | Output | Explanation |
| --- | --- | --- |
| 5 2 3<br>1 -1 1 1 -1<br>-1 1 -1 -1 -1 | 1 | $\small 2+1-1+1+1-1=3$$\small 3-1+1-1-1-1=0$ |
| 4 1 3<br>1 1 -1 -1<br>1 -1 -1 -1 | 0 | $\small 1+1+1-1-1=1$$\small 3+1-1-1-1=1$ |
