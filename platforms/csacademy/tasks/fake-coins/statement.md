# Fake Coins

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fake-coins/](https://csacademy.com/contest/archive/task/fake-coins/)  

---

You have $N$ coins that look identical. You know one coin weighs $10$ grams, another coin weighs $30$ grams, and all the other $N-2$ coins weigh $20$ grams.

You have a scale you can use to compare the total weight of any two disjoint subsets of coins. Find the coins that weigh $10$ and $30$ grams.

### Interaction

First you should read a single integer $N$.

Then you can start asking the queries. Each of them consists of the character Q followed by two numbers $K_1$ and $K_2$, and then by $K_1 + K_2$ distinct values between $1$ and $N$:

$K_1$ is the size of the first subset$K_2$ is the size of the second subsetThe next $K_1$ values represent the indices of the coins in the first subsetThe last $K_2$ values represent the indices of the coins in the second subset

After each query you should read the answer given by the scale:

$-1$ if the first subset is lighter$0$ if the two subset have the same total weight$1$ if the second subset is lighter

When you are done, print the character A followed by $2$ integers representing the indices of the coins weighing $10$ grams, and $30$ grams respectively.

### Constraints and notes

This task is NOT adaptive$3 \leq N \leq 1000$You are allowed to use the scale at most $25$ times.

Interaction4Q 2 2 4 1 2 3-1Q 1 1 4 11Q 1 1 2 3-1A 1 36Q 3 3 4 5 2 6 1 3-1Q 1 1 4 5-1Q 1 1 6 10A 4 3
