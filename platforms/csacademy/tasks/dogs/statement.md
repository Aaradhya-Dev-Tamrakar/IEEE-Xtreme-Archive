# Diamond Dogs

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dogs/](https://csacademy.com/contest/archive/task/dogs/)  

---

There are $N$ diamonds in a row, numbered from $1$ to $N$, which all have distinct integer sizes. The size of diamond $i$ is $T_i$.

Bigger diamonds are exponentially more expensive. Diamond of size $a$ has a value of $2^a$ won (Won is a currency of Korea).

Also, there are $M$ dogs, numbered from $1$ to $M$, each claiming a certain consecutive interval of diamonds.

Your task is to sort the dogs in ascending order, compared by total value of diamonds they claim. If there are ties, you can print the tied dogs in any order.

### Standard input

The first line contains a single integer $N$, the number of diamonds.

The second line contains $N$ integers, representing the array $T$ of sizes.

The third line contains a single integer $M$, the number of dogs.

The next $M$ lines each contain two integers $L_i, R_i$. Dog number $i$ claims diamonds from $L_i$ to $R_i$, inclusive.

### Standard output

In the first line print $M$ integers, denoting the dogs in the order of ascending value of diamonds they claim.

### Constraints and notes

$1\le N, M \le 10^5$ $1 \le T_i \le 10^9$ $1 \le L_i \le R_i \le N$

| Input | Output |
| --- | --- |
| 5<br>3 4 2 6 7<br>5<br>1 4<br>5 5<br>5 5<br>1 5<br>1 2 | 5 1 2 3 4 |
