# Cookie Clicker

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cookie-clicker/](https://csacademy.com/contest/archive/task/cookie-clicker/)  

---

You're playing the famous cookie clicker game with a single goal in mind: to obtain at least $C$ cookies. The game has a simple concept. You start with $0$ cookies and gain $S$ cookies every second. You can also buy some of the $N (1 \leq N \leq 5)$ available cookie factories. The $i_{th}$ cookie factory costs $A_i$ cookies and it'll increase the number of cookies you produce every second by $B_i$ cookies.

You can buy a factory at most once and all the purchases need to be done at integer moments of time. You are allowed to buy more than a factory at a given time.

You should find a strategy that minimizes the moment in time $T$ when you will have $C$ cookies. Find the minimum value of $T$.

### Standard input

The first line contains three integers $N$, $C$ and $S$ representing the number of factories which can be bought, the number of desired cookies and the initial number of cookies per second.

Each of the following $N$ lines contain two integers, $A_i$ and $B_i$ representing the cost of a factory and the bonus cookies per second it'll produce if purchased.

### Standard output

The first line should contain the value $T$.

### Constraints and notes

$1 \leq N \leq 5$ $1 \leq C \leq 10^5$ $1 \leq S \leq 10^5$ $1 \leq A_i \leq 10^5, 1 \leq B_i \leq 10^5$ for each $1 \leq i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2 18 1<br>6 2<br>5 1 | 12 | wait $6$ seconds until you have $6$ cookies and buy the first factory.when you receive the $7_{th}$ batch of cookies, you should receive $3$ (the initial $1$ and the extra $2$ produced by the factory).wait an extra $6$ second to obtain $18$ cookies. |
| 2 20 2<br>1 10<br>1 10 | 2 | after receiving the first $2$ cookies, buy the $2$ factories. wait another second to get $22$ cookies, obtaining more than enough cookies.Note that you can buy $2$ factories at once. |
| 3 30 3<br>7 1<br>5 1<br>9 2 | 9 | Wait $2$ seconds and buy the $2_{nd}$ factory. After the purchase, you still have $1$ cookie.wait another $2$ second to get $9$ cookies. After buy the last factory.to obtain $30$ cookies, wait for another $5$ seconds. |
| 3 30 2<br>9 4<br>1 1<br>25 5 | 9 |  |
