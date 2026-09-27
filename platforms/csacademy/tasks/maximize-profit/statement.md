# Maximize Profit

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/maximize-profit/](https://csacademy.com/contest/archive/task/maximize-profit/)  

---

You have an initial amount of money $S$. There are $Q$ deals you can make to increase your sum. Each deal $i$ will either add a constant number $K$, or it can increase your current amount by a percentage $P_i$.

You can apply the deals in any order, and for each of them you can choose wether it will add a constant value or a percentage. Maximize the final value of $S$.

### Standard input

The first line contains three integers $S$, $Q$ and $K$.

The second line contains $Q$ integers, the elements of $P$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$0 \le S \leq 10^7$ $1 \le Q \le 50$ $0 \leq K \leq 10^5$ $0 \leq P_i \leq 100$ The answer is guaranteed to be at most $10^9$ and will be evaluated with an absolute or relative precision of $10^{-6}$

| Input | Output | Explanation |
| --- | --- | --- |
| 100 3 20<br>10 50 30 | 234.00000000000 | Use the first deal to increase the sum by $20$ having $120$Use the third deal to increase the sum by $30\%$ having $156$Use the second deal to increase the sum by $50\%$ finishing with $234$ |
| 20 2 30<br>100 100 | 100.00000000000 | First deal, add $30$, resulting $50$Second deal, add $100\%$, resulting $100$ |
| 100 5 100<br>63 17 23 41 29 | 919.32000000000 | Use deals $2, 3$ and $5$ to add $100$, resulting $400$Use the forth deal to add $41\%$ resulting  $564$Use the first deal to add $62\%$ resulting $919,32$ |
