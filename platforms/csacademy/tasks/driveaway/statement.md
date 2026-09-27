# Driveaway

**Time Limit:** `1000 ms`  
**Memory Limit:** `549 MB`  
**Source:** [https://csacademy.com/contest/archive/task/driveaway/](https://csacademy.com/contest/archive/task/driveaway/)  

---

You want to visit the city of Iasi. Because the city is very big, you are going to use Uber to go from one touristic attraction to another. You already planned $N$ trips and know that the $i^{th}$ trip costs $A_i\text{ RON}$ (Romanian currency).

You also have several vouchers of value $X$ which you can use in the following way: choose two consecutive trips and reduce the total cost by $X$ (if the total cost is smaller than $X$, then these trips will be free). You can not use multiple vouchers for the same trip.

For example, let's say we have a voucher with a value of $10\text{ RON}$. If there are two consecutive trips with cost $5\text{ RON}$ and $7\text{ RON}$ respectively, then the total amount to pay is $5 + 7 - 10 = 2\text{ RON}$. However, if the trips were to have cost $3\text{ RON}$ and $5\text{ RON}$, then the total amount to pay is $0\text{ RON}$, not $3 + 5 - 10 = -2$.

Your task is to minimize the total amount of money you have to pay for all trips using the vouchers optimally. Because you might want to save some vouchers for future trips, print the minimum amount of money you have to pay if you use exactly $K$ vouchers for each $K$ between $1$ and $\lfloor \frac{N}{2} \rfloor$.

### Standard input

On the first line of the input are given the numbers $N$ and $X$.

On the second line there are $N$ integers $A_1, A_2,..., A_n$, the costs of trips.

### Standard output

The output consists of $\lfloor \frac{N}{2} \rfloor$ lines. In the $i^{th}$ line there should be a single integer representing the minimal amount of money you have to pay if you use exactly $i$ vouchers.

### Constraints and notes

$2 \leq N \leq 2 \cdot 10^5$ $0 \leq X \leq 10^9$ $0 \leq A_i \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 7<br>3 10 2 1 | 9<br>6 | If we use only one voucher, it is optimal to choose the first two trips and reduce the cost by 7.If we use two vouchers, the best solution would be to choose the first two trips for one voucher and the second and third trip for the second voucher, but we are not allowed to use multiple vouchers for the same trip. |
| 6 10<br>1 3 7 7 3 1 | 12<br>2<br>4 |  |
| 12 85<br>28 42 16 30 48 85 38 39 73 63 21 23 | 421<br>336<br>252<br>174<br>104<br>99 |  |
