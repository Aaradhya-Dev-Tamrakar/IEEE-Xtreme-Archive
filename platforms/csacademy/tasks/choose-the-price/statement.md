# Choose the Price

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/choose-the-price/](https://csacademy.com/contest/archive/task/choose-the-price/)  

---

You are selling homemade cookies. There are $N$ potential clients, for each client $i$ you know the maximum amount of money $V_i$ he's willing to pay for one cookie (each of them will either buy one cookie, or none). Choose the  selling price of the cookies in a way the maximizes your income.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers, representing the values of $V$.

### Standard output

Print a single integer representing the maximum possible income.

### Constraints and notes

$1 \leq N \leq 1000$ $1 \leq V_i \leq 10^6$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>2 10 6 3 | 12 | The most income can be achieved by selling the cookies for $6$. In this way, $2$ clients will buy one cookie, resulting an income of $12$ |
| 3<br>6 3 2 | 6 | $6$ can be obtained by selling cookies for either $2$, $3$ or $6$ |
