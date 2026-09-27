# Fashion

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fashion/](https://csacademy.com/contest/archive/task/fashion/)  

---

Managing the world's most famous fashion magazine isn't easy for a programmer, especially when the next big fashion show is happening tomorrow and you've been doing nothing but procastinating for the whole year! There are no outfits for your models, and the company's storage has only last year's collection of clothes, which have clearly become out of fashion! However, there's still some time (and coffee) left, so hope is not lost. Better come up with a plan, buy some clothes and prepare some trendy outfits for your models as quick as possible!

There are $N$ clothing items among your partner brands' stores. Each of them can be one of three types: top, bottom, or shoes, and the store agreed to sell you at the price of $C_{i}$ dollars  ($1 \leq i \leq N$).

You could try mixing up some cheap clothing and make some fancy-looking outfits for the event, but let's be honest; your sponsors want to see class and style during your fashion show, and that might not be easy with your taste in design patterns! Fortunately, you have found your sponsors' list of $M$ outfits. For each outfit $i$ you get a total revenue of $W_{i}$ dollars if you manage to showcase it during the event. Each outfit, naturally, consist in a specific combination of a top, a bottom, and shoes.

Formally, each clothing item is described by two integers $T_{i}$, $C_{i}$ ($1 \leq i \leq N$ and $T_{i} \in \{1, 2, 3\}$) and each outfit is described by four integers, $A_{j}, B_{j}, C_{j}, W_{j}$ ($1 \leq A_{j}, B_{j}, C_{j} \leq N$), representing, in order, the indices of the top, bottom and shoes the $j^{th}$ outfit consist of, as well as the revenue received if it is showcased during the event.

You are requested to find the maximum profit you can obtain by buying some (possibly none) of the clothing pieces and attending the show. Once bought, one piece of clothing can be used for multiple outfits throughout the show.

### Standard input

On the first line of the input file there are two integers, $N, M$.

On each the following $N$ lines there are two integers $T_{i}, C_{i}$, representing the type of the $i^{th}$ clothing piece, as well as its price in dollars. ($T_{i} \in \{1, 2, 3\}, \forall( 1 \leq i \leq N)$)

On each of the following $M$ lines there are four integers $A_{j}, B_{j}, C_{j}, W_{j}$ ($1 \leq A_{j}, B_{j}, C_{j} \leq N$). Also, is is guaranteed that $T_{A_{j}} = 1, T_{B_{j}} = 2, T_{C_{j}} = 3$.

### Standard output

The first line of the output should contain two integers $P, K$, representing the maximum profit you can obtain in dollars, as well as the number of items that you are going to buy.

The following $K$ lines should contain the indices of the items to buy, in increasing order.

If there are multiple solutions, you can output any of them.

### Constraints and notes

$1 \leq N, M \leq 10^3$

$1 \leq C_{i}, W_{j} \leq 10^9, \forall (1 \leq i \leq N, 1 \leq j \leq M)$.

### Subtasks

Test cases will be scored individually.

| Subtask | Percentage of test cases | Additional input constraints |
| --- | --- | --- |
| 1 | $30\%$ | $N \leq 32$<br><br>$M \leq 28$ |
| 2 | $10\%$ | $32 < N \leq 40$<br><br>$28 < M \leq 32$ |
| 3 | $30\%$ | $10^2 \leq N, M \leq 10^3$, there is exactly one pair of shoes (there is exactly one $i$ having $T_{i} = 3$ ) |
| 4 | $30\%$ | none |

### Examples

| Input | Output |
| --- | --- |
| 6 3<br>1 1<br>3 4<br>2 7<br>3 8<br>1 666<br>2 4<br>1 3 2 15<br>1 3 4 10<br>5 6 4 100 | 5 4<br>1 2 3 4 |
