# Money Savings

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/money-savings/](https://csacademy.com/contest/archive/task/money-savings/)  

---

You start with an initial budget of $X$ dollars. Over the course of the next $12$ months, $Q$ offers are available; the $i^{\text{th}}$ one of them proposes an investment of $A_i$ dollars this month with a return of $B_i$ dollars by the next month.

You may choose at most one offer each month. You may take offer $i$ only if $A_i \leq X$, where $X$ is your current budget, meaning that you may not remain in debt. Check the sample explanations to get a better idea!

Print the maximum profit.

### Standard input

The first line contains two integers, $Q$ and $X$.

The next $Q$ lines contain two integers $A$ and $B$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq Q, A, B \leq 100$ $1 \leq X \leq 1\ 000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 1 10<br>10 20 | 130 | You start with $10$ dollars. In every month you will make an investment of $10$ dollars which will give you a reward of $10$ dollars. After doing this for all the $12$ months, you'll have $130$ dollars. |
| 1 10<br>20 50 | 10 | You don't have enough money to make any investment, so at the end of the $12$th month you will still have the initial $10$ dollars. |
| 2 5<br>1 2<br>7 10 | 37 | In the first $2$ months make an investment of the first type. After $2$ months you'll have $7$ dollars. For the next $10$ months make an investment of type $2$, which will give in the end $7 + 10 * (10 - 7) = 37$ dollarsthe $7$ dollars are made after the first $2$ investmenteach investment of type $2$ gives a reward of $(10 - 7) = 3)$ dollars |
