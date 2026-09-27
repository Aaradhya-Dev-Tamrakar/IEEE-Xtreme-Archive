# Water Tower

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/water-tower/](https://csacademy.com/contest/archive/task/water-tower/)  

---

You just finished the construction of a new water tower of height $H$ which is holding $H$ units of water. Because of bad design, you figured out that there will appear $Q$ leaks in the tower. Each leak is characterised by two integers, $h$ and $t$, meaning that a leak will appear at time $t$ and it'll be situated $h$ units above the towers bottom. Each leak will lower the towers water volume by $1$ unit of water per second as long as the waters level is strictly above the leak point.

Given $H$ and the $Q$ leaks determine the real number $T$, the time when the water will be completely dried out or print $-1$ if this will never happen.

### Standard input

The first line contains two integers $H$ and $Q$.

Each of the following $Q$ lines contains two integers $t$ and $h$ describing a leak.

### Standard output

The first line should contain the real number $R$, the moment when the tower will be completely dried out or $-1$ if this will never happen.

### Constraints and notes

$1 \leq H \leq 10^9$ $1 \leq Q \leq 10^5$ $0 \leq t_i \leq 10^9, 0 \leq h_i \leq H$ for each $1 \leq i \leq Q$ Your result will be checked with an absolute or relative error of $10^{-6}$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 10 3<br>5 0<br>8 6<br>9 1 | 12.2500000 | $t = 5$, water level $= 10$, a new leak starts at $h = 0$ $t = 8$, water level $= 7$, a new leak starts at $h = 6$ $t = 8.5$, water level $= 6$, the leak at $h = 6$ stops because the water level is lower than the leak's height$t = 9$, water level $= 5.5$, a new leak starts at $h = 1$ $t = 11,25$, water level $= 1$, the leak at $h = 1$ stops$t = 12,25$, water reaches $h = 0$ and all the leaks stop - the water tower is dried out |
| 20 3<br>2 18<br>5 10<br>15 0 | 25.0000000 | $t = 2$, water level $= 20$, a new leak starts at $h = 18$ $t = 4$, water level $= 18$, the leak at $h = 18$ stops$t = 5$, water level $= 18$, a new leak starts at $h = 10$ $t = 13$, water level $= 10$, the leak at $h = 10$ stops$t = 15$, water level $= 10$, a new leak starts at $h = 0$ $t = 25$, water reaches $h = 0$ and all the leaks stop - the water tower is dried out |
| 11 2<br>3 5<br>4 11 | -1 | Note that you can print -1 or -1.0. Both results are correct. |
| 7 3<br>2 0<br>2 0<br>2 0 | 4.3333333 | Note that there can be multiple leaks starting at the same time, even at the same height. |
