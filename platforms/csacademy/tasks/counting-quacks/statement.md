# Counting Quacks

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/counting-quacks/](https://csacademy.com/contest/archive/task/counting-quacks/)  

---

There are $N$ ducks on a lake. Every duck $i$ quacks periodically, once every $X_i$ moments of time; i.e. it quacks for the first time at the $X_i^{\text{th}}$ moment of time, it quacks for the second time at the ${2 * X_i}^{\text{th}}$ moment and so on...

Alex is sitting near this lake and he asks himself:

What's the maximum number of quacks i'll hear at the same moment of time? How many times i'll hear this many quacks throughout my staying at the lake?

Alex isn't feeling so contemplative today, so he's leaving the lake after $T$ moments of time. After he leaves he won't be able to hear any more quacks.

### Standard input

The first line contains two integers, $N$ and $T$.

The next line contains $N$ integers representing $X$.

### Standard output

The first line contains two integers separated by space, as described in the statement.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq T \leq 10^6$ $1 \leq X_i \leq 10^6$ for each $1 \leq i \leq N$ Alex comes at the lake at the moment of time $1$. 

| Input | Output |
| --- | --- |
| 3 6<br>2 2 3 | 3 1 |
| 3 5<br>2 2 3 | 2 2 |
| 6 10<br>1 2 3 4 5 6 | 4 1 |
