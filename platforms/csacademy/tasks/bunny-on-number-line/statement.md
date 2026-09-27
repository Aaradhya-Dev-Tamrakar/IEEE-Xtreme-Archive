# Bunny on Number Line

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bunny-on-number-line/](https://csacademy.com/contest/archive/task/bunny-on-number-line/)  

---

A bunny is hopping on a number line. It starts at the number $0$. Every second, it can either hop $1$ unit to the right or hop to the number $1$. The numbers $x_{1}, x_{2}, ..., x_{K}$ are called bad. It is guaranteed that the number $1$ is not bad. A valid sequence of hops is a sequence of hops which

visits bad numbers exactly $N$ times.visits bad numbers at least once every $M$ hops.the last visited number in the sequence of hops is bad.

Two valid sequence of hops $S_{1}$ and $S_{2}$ are considered distinct if there exist a moment where the bunny is on a bad number in $S_{1}$ and not on a bad number in $S_{2}$. Find the sum of total number of hops made by the bunny over all valid sequences of hops, modulo $10^{9} + 7$.

### Standard input

The first line contains three space-separated integers, denoting $K, M, N$ respectively.

The next line contains $K$ space-separated integers, denoting the values of $x_{1}, x_{2}, ..., x_{K}$.

### Standard output

Output a single integer, the sum of  total number of hops made by the bunny over all valid sequences of hops, modulo $10^{9} + 7$.

### Constraints and notes

$1 \le K \le 100$ $1 \le M, N \le 10^{9}$ $2 \le x_{1} < x_{2} < ... < x_{K} \le 10^{9}$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 5 3<br>4 6 9 13 15 | 215 | Let's denote a valid sequence of hops by the moments it visit bad numbers. Here are the possible valid sequence of hops :$(4, 6, 9)$, achieved by the sequence $1,2,3,4,5,6,7,8,9$.$(5, 7, 10)$ achieved by the sequence $1,1,2,3,4,5,6,7,8,9$.$(4, 6, 10)$ achieved by the sequence $1,2,3,4,5,6,1,2,3,4$.$(5, 7, 11)$ achieved by the sequence $1,1,2,3,4,5,6,1,2,3,4$.$(5,7,12)$ achieved by the sequence $1,1,2,3,4,5,6,7,1,2,3,4$.$(4,6,11)$ achieved by the sequence $1,2,3,4,5,6,7,1,2,3,4$.$(4,8,12)$ achieved by the sequence $1,2,3,4,1,2,3,4,1,2,3,4$.$(5,9,13)$ achieved by the sequence $1,1,2,3,4,1,2,3,4,1,2,3,4$.$(4,9,13)$ achieved by the sequence $1,2,3,4,5,1,2,3,4,1,2,3,4$.$(4,8,13)$ achieved by the sequence $1,2,3,4,1,2,3,4,1,1,2,3,4$.$(5,10,14)$ achieved by the sequence $1,1,2,3,4,5,1,2,3,4,1,2,3,4$.$(4,9,14)$ achieved by the sequence $1,2,3,4,5,1,2,3,4,5,1,2,3,4$.$(5,10,15)$ achieved by the sequence $1,1,2,3,4,5,1,2,3,4,5,1,2,3,4$.$(4,8,10)$ achieved by the sequence $1,2,3,4,1,2,3,4,5,6$.$(5,9,11)$ achieved by the sequence $1,1,2,3,4,1,2,3,4,5,6$.$(5,10,12)$ achieved by the sequence $1,1,2,3,4,5,1,2,3,4,5,6$.$(4,9,11)$ achieved by the sequence $1,2,3,4,5,1,2,3,4,5,6$.$(5,9,14)$ achieved by the sequence $1,1,2,3,4,1,2,3,4,5,1,2,3,4$.Note that $(5,11,15)$ would not denote a valid sequence of hops because on the bunny did not visit any bad squares during the $5$ hops from time $6$ to $10$ inclusive.Also note that while there are multiple ways to reach some of the sequences, for example the sequence $1,1,2,3,4,1,1,2,3,4,1,1,2,3,4$ also corresponds to the sequence $(5, 10, 15)$, but the sequence $(5, 10, 15)$ will only be counted once.Thus, the answer to this sample is the sum of total number of hops travelled over all possible valid sequence of hops, which is $9+10+10+11+12+11+12+13+13+13+14+14+15+10+11+12+11+14=215$. |
| 3 5 6<br>2 6 7 | 105744 |  |
| 5 6 3<br>6 11 15 18 20 | 67 |  |
