# Shampoo Exchange

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/shampoo-exchange/](https://csacademy.com/contest/archive/task/shampoo-exchange/)  

---

You have $N$ shampoo bottles, each of capacity $X$. You've just realised that opening $N$ bottles and using them alternatively is kind of redundant so you want to store all your remaining shampoo in as few bottles as possible. For this, you may take one bottle and pour $1$ unit of shampoo into another, as long as it doesn't exceed its capacity. This operation takes one second.

No two bottles can be poured simultaneously in a third bottle. You may not pour simultaneously in multiple bottles. Also, you may not simultaneously pour into a bottle which is already being poured on another one.

What's the minimum bottles you need to store all the shampoo you have? What's the minimum necessary time to move it?

### Standard input

The first line contains $N$ and $X$.

The next line contains $N$ integers representing the quantity of shampoo from each bottle, $Q_i$.

### Standard output

Print the values on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq X \leq 10^9$ $1 \leq Q_i \leq X$ for all $1 \leq i \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 6<br>4 4 4 4 | 3 4 | We need to keep the first $3$ bottles. To pour the remaining $4$ quantities we need to pour $2$ times in the first bottle and $2$ times in the second. Notice that we cannot pour simultaneously in multiple bottles. |
| 4 8<br>4 4 4 4 | 2 4 | We can keep the first $2$ bottles. In the next $4$ units of time you will pour from $3$ to $1$ and from $4$ to $2$. |
| 4 10<br>7 1 1 1 | 1 3 |  |
| 5 10<br>4 3 2 1 1 | 2 2 | Keep the first two bottles, can simultaneously pour from the 3rd to the second and the last two on the first. Notice that this process doesn't break any condition from the statement, so it's valid. |
