# Ultimate Orbs

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/ultimateorbs/](https://csacademy.com/contest/archive/task/ultimateorbs/)  

---

Consider $N$ orbs of pairwise distinct colors arranged in a line, indexed from $1$ to $N$.

Orb $i$ has an initial weight $G_i$. We say a certain orb can eat an adjacent orb if the latter is heavier by at most $D$ units. Once an orb is eaten its color gets lost while the color of the other orb stays the same.  Even more, the weight of the eating orb increases by the weight of the orb being eaten.

After $N - 1$ eatings only one orb will remain. Compute all possible colors of this orb (the color of an orb is equal to its index in the initial sequence of orbs).

### Standard input

The first line contains two integers $N$ and $D$.

The second line contains $N$ integers representing the values of $G$.

### Standard output

On the first line print the indices of the possible final orbs, in ascending order.

### Constraints and notes

$1 \leq N \leq 10^{6}$ $0 \leq D \leq 10^{9}$ $0 \leq G_{i} \leq 10^{9}$ 

| Input | Output |
| --- | --- |
| 13 2<br>2 0 1 6 1 0 3 0 13 2 0 4 6 | 4 5 6 7 9 10 11 12 13 |
