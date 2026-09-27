# Particles

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/particles/](https://csacademy.com/contest/archive/task/particles/)  

---

Two linear particle accelerators $A$ and $B$, placed opposite to each other at a distance $L$ apart, are propelling elementary particles. $A$ is shooting $x$-particles, while $B$ is shooting $y$-particles. The two kinds of particles are flying one opposing the other, and when an $x$-particle meets a $y$-particle, they collide and annihilate. One should be aware that an $x$-particle could overtake other $x$-particles, as well as a $y$-particle could overtake other $y$-particles without any consequences for the particles.

Like so, in a given moment of time, which we assume to be zero, a shooting of $N$ $x$-particles and $N$ $y$-particles starts from the two accelerators. Each particle moves with its own constant speed. The particles are numbered in the order of their shooting from $1$ to $N$, this holds true for both the $x$-particles and the $y$-particles.

Remark: For time $t$, a particle with speed $v$ travels distance $s = v*t$.

The shooting time moments for the $x$-particles are $0=tx_1 < tx_2 < tx_3 < .... < tx_N$, and their speeds are $vx_1, vx_2, vx_3, ..., vx_N$.

Correspondingly, for the $y$-particles the moments are denoted by $0=ty_1 < ty_2 < ty_3 < ... < ty_N$, and their speeds by $vy_1, vy_2, vy_3, ..., vy_N$.

The shooting is executed in a way to guarantee the fulfilment of the following conditions:

Each particle will collide a particle of the opposite type;When two particles collide, all other particles will be at a distance greater than or equal to $1$ from the collision point. This is guaranteed for the first $K$ collisions.

### Task

Write a program particles to determine the first $K$ collisions between particles of the two kinds.

### Input

The three space separated positive integers $N$, $L$, and $K$ are read from the first line of the standard input.

The following $N$ lines contain two space separated non-negative integers $tx_i$ and $vx_i$ each: the shooting moment and the speed of the corresponding $x$-particle.

The last $N$ input lines contain, respectively, each the shooting moment $ty_i$ and the speed $vy_i$ of the corresponding $y$-particle in the same format.

### Output

The program must print to the standard output $K$ lines, each containing two space separated positive integers: the numbers of the $x$-particle and $y$-particle, which are involved in the corresponding collision. Lines are output increasingly by the order of collisions – from the first one to the $K^{th}$.

### Constraints

$1 \leq N \leq 50\,000$ In 30% of the tests $N\leq 1\,000$ $1 \leq L \leq 10^9$ $1 \leq K \leq 100, K \leq N$ $0 \leq tx_i,ty_i \leq 10^9$ $1 \leq vx_i,vy_i \leq 10^9$

| Input | Output |
| --- | --- |
| 4 100 2<br>0 1<br>2 3<br>3 2<br>6 10<br>0 5<br>3 10<br>5 1<br>7 20 | 4 2<br>2 4 |
