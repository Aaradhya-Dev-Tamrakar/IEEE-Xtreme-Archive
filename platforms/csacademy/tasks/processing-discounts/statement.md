# Processing Discounts

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/processing-discounts/](https://csacademy.com/contest/archive/task/processing-discounts/)  

---

You've just placed an order of $X$ USD on an online shopping website. The website has $N$ special discounts: if you make a purchase of at least $A_i$ USD, you get back $B_i$ USD. It may be advantageous to increase your order bill just so you would be eligible of certain discount offers.

What's the minimum amount of USD that you have to pay in the end, after processing the discounts?

### Standard input

The first line contains two integers, $N$ and $X$.

The next $N$ lines contain a pair of integers, $A_i$ and $B_i$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1\leq X, A_i, B_i \leq 10^6$ The online shopping website will never become in debt to you, i.e. the discount offers are chosen in such a way that you'd never reach a negative amount of payment.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 99<br>50 5<br>75 10<br>100 5 | 80 | We're eligible for the first two discount offers, so we get $5 + 10 = 15$ USD back. This means that in the end we'll pay $99 - 15 = 84$ USD.If we increase our order up to $100$ USD, we'll be eligible for the third offer as well and we'll pay only $100 - 5 - 10 - 5 = 80$ USD. |
| 5 50<br>10 1<br>20 2<br>30 3<br>30 3<br>100 10 | 41 | We're eligible for all the discount offers besides the last one. If we were to increase our payment in order to get the last offer, we would end up with $100 - 10 - 3 - 3 - 2 - 1 = 81$ USD. It's better to only consider the first $3$, we end up spending $50 - 3 - 3 - 2 - 1 = 41$ USD. |
| 1 10<br>100 95 | 5 |  |
| 1 200<br>100 95 | 105 |  |
