# Empowering Software

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fiicode-2022-e2/](https://csacademy.com/contest/archive/task/fiicode-2022-e2/)  

---

The Empire wants to conquer another far far away galaxy. The galaxy is made out of $n$ planets. To travel inside the galaxy, the Empire fleet can use the $m$ interplanetary two-way portals. The use of any portal is happening instantly.

At first, the Commandant found a “perfect” plan which satisfies Emperor's constraints:

Each year, a new planet should be conquered until the whole galaxy is conquered.  This way the plan is balanced enough.If a planet $i$ is conquered in the $y$-th year, then each neighbouring planet of $i$ should be either already conquered (before year $y$) or going to be conquered in the next $20$ years (at most in the $y + 20$ year). Otherwise, the plan is considered risky as some neighboring planets will have enough time to prepare defence.

The “perfect” plan is provided as a permutation of the $n$ planets: the $i$-th planet is conquered in the $i$-th year. It is guaranteed that the plan satisfies the constraints. Further, we can presume that a “conquered portal” is a portal which has its both planet ends conquered.

Finally, the Emperor also wants to remove all unnecessary portals at some point. You should provide, after each year, the number of ways to remove zero or more of the “conquered portals” such that:

There should be exactly one path (a sequence of conquered portals) between any two conquered planets.

### Input

The first line of the input has two integers: $n$ – the number of planets in the galaxy and $m$ – the number of interplanetary portals.

The next $m$ lines describe the end-planets of each portal. The $i$-th line has two integers, the planets linked by the $i$-th portal.

The last line of the input has $n$ integers representing a permutation of the $n$ planets.

### Output

The output should have $n$ lines. The $i$-th line should have only one integer, the answer for the $i$-th year. Since each answer can be very large, it is required to provide it modulo $10^9 + 7$.

### Constraints

$1 \le n \le 1000$ $0 \le m \le n \times (n - 1) / 2$ The permutation provided is a “perfect” plan.

| Input | Output |
| --- | --- |
| 4 5<br>1 2<br>1 3<br>2 3<br>3 4<br>2 4<br>2 1 3 4 | 1<br>1<br>3<br>8 |
| 4 4<br>1 2<br>2 3<br>3 4<br>4 1<br>1 3 2 4 | 1<br>0<br>1<br>4 |
