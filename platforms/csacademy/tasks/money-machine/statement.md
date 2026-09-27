# Money Machine

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/money-machine/](https://csacademy.com/contest/archive/task/money-machine/)  

---

You just got as a present a money making machine. At the end of each day you can use the machine to print $X_1$ dollars.

At the beginning of each day, you can pay $U$ dollars to upgrade the machine (you are only allowed to perform at most one upgrade each day). This means that starting with the day of the upgrade, you'll be able to print $X_2$ dollars more than before. Basically, if you upgrade the machine $K$ times, you'll print $X_1 + K*X_2$ dollars.

Initially you have $C$ dollars, your goal is to maximize the total amount of money you have at the end of day $N$, after using the machine.

### Standard input

The first line contains $5$ integers $N$, $C$, $X_1$, $U$, $X_2$.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 100$ $0 \leq C, U \leq 1\,000$ $1 \leq X_1, X_2 \leq 100$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 2 1 3 2 | 10 | In the start of the $1$st day you have $2$ coins, which is not enough to upgrade the machine.In the start of the $2$nd day, you have $2$ coins from the other day plus the coin that was produced by the machine, giving $3$ coins. This coins will be used to upgrade the machine, now producing $3$ coins per day and leaving you with $0$ coins.In the start of the $3$rd day, you have the $3$ coins produced by the machine. This coins will be used to upgrade the machine, now producing $5$ coins per day.In the start of the $4$th day, you have the $5$ coins produced by the machine and you chose not to upgrade the machine. This means that at the end of the $4$th day you'll have $10$ coins.This is the way to achieve the most money. |
| 3 5 1 0 1 | 14 | Since the machine doesn't require any money to upgrade, we'll upgrade it every day.end of the $1$st day: $7$ coins, $2$ coins incomeend of the $2$nd day: $10$ coins, $3$ coins incomeend of the $3$rd day: $14$ coins, $4$ coins income |
| 3 10 1 5 2 | 14 | Upgrading the machine in the $1$st day gives an income of $3$ coins and the remaining $5$ coins.At the end of the $3$rd day, you'll have $3 \times 3 + 5 = 14$ coins. |
| 4 1 1 3 1 | 5 | The best result is obtained by not upgrading the machine at all ($1 \times 4 + 1 = 5)$The earliest you can upgrade the machine is the $3$rd day, which will not yield a bigger profit at the end of the $4$th day. |
