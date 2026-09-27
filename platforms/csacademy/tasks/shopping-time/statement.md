# Shopping Time

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/shopping-time/](https://csacademy.com/contest/archive/task/shopping-time/)  

---

You have just received an e-mail telling you that a distant relative of yours has made you the brand owner of a tech shop! (that's what happens when you actually check your spam folder)

  

The tech shop owns a total of $N + M$ different smartphones, indexed by positive integers from $1$ to $N + M$. Each of these smartphones are characterized by three positive integers. In particular, the $i$-th phone ($1 \leq i \leq N + M$) has the following characteristics:

$m_i$ (the memory capacity of the phone); $c_i$ (the quality of the camera); $p_i$ (its price).

Out of these $N + M$ phones, only the first $N$ are initially available for sale; the other $M$ phones are securely kept in the shop warehouse.

  

During each of the next $M$ days, a single customer would visit your shop and pick one of the $N$ available smartphones for purchase. The customers don't want to spend all their earnings on smartphones, so they would choose a phone that has a price as low as possible. However, the customers don't settle for less quality, therefore they would never choose a phone $i$ if there is some other phone $j$ for sale that is objectively better than $i$.

Formally, each customer would pick the phone $i$ with the lowest price $p_i$, for which there is no $j$ such that $c_j > c_i$ and $m_j > m_i$.

  

After each sale, the sold phone would be replaced by the next phone in the warehouse. More specifically, after the first day, the sold phone is replaced by the $N + 1$-th phone, after the second day the sold phone is replaced by the $N + 2$-th phone, and so on.

  

Given the specifications of the smartphones, which would be the phones that would be sold to each of the $M$ customers?

  

### Standard input

  

The first line of the standard input contains two space-separated integers $N$ and $M$. Each of the following $N + M$ lines contains three space-separated integers $m_i$, $c_i$, and $p_i$, denoting the memory capacity, the camera quality, and the price of the $i$-th smartphone. The first $N$ smartphones are initially in the store, whereas the rest of them would be added after each day.

  

### Standard output

  

The standard output should contain $M$ lines. On the $i$-th line there should be a number $z_i$ ($1 \leq z_i \leq N + M$), denoting the index of the smartphone that would be sold on day $i$.

  

### Constraints and notes

  
$1 \leq N, M \leq 10^5$ $1 \leq m_i, c_i, p_i \leq 10^9$ It is guaranteed that all $m_i$ are distinct (the same applies to $c_i$ and $p_i$)  

| Input | Output |
| --- | --- |
| 3 3<br>2 3 3<br>4 5 10<br>6 2 8<br>3 1 4<br>1 6 9<br>8 4 1 | 3<br>2<br>1 |
| 4 2<br>1 3 5<br>4 6 2<br>2 7 9<br>3 5 3<br>6 9 10<br>10 10 1 | 2<br>5 |
