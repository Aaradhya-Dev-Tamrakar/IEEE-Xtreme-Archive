# Lamp

**Time Limit:** `1000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/lamp/](https://csacademy.com/contest/archive/task/lamp/)  

---

The country of ManTeleor consists of an infinite grid where there are $N$ beehives. For each beehive $i$ you are given its integer coordinates $(\text{XS}_i, \text{YS}_i)$. The country is illuminated by a lamp situated at $(\text{XL}, \text{YL})$ (integer coordinates). The lamp illuminates all the points situated at a Manhattan distance $\leq D$.

Aladdin wants to build a house at coordinates $(\text{XC}, \text{YC})$, representing coordinates of a corner or a center of a grid square. The house should be illuminated by the lamp, and in addition the Manhattan distance to the closest beehive should be maximized.

### Standard input

The first line contains $4$ integers $N$, $\text{XL}$, $\text{YL}$ and $D$.

Each of the next $N$ lines contains $2$ integers representing the coordinates of a beehive.

### Standard output

Print on the first line $3$ integers: the Manhattan distance to the closest beehive, followed by the coordinates of the house $\text{XC}$ and $\text{YC}$.

### Constraints and notes

$1 \leq N, D \leq 10^5$ $-10^9 \leq  \text{XL}, \text{YL} \leq 10^9$ $-10^9 \leq  \text{XC}, \text{YC} \leq 10^9$ $-10^9 \leq  \text{XS}_i, \text{YS}_i \leq 10^9$ 

| Input | Output |
| --- | --- |
| 3 6 3 2<br>2 9<br>1 -1<br>-2 1 | 11 8.0 3.0 |
