# Metal Examination

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/metal-examination/](https://csacademy.com/contest/archive/task/metal-examination/)  

---

You've just found an object weighing $G$ grams. The object can be made of one of $N$ types of precious metals, with equal probability.

For each type of metal you know its price per gram $p_i$ and the quantity $c_i$ (expressed in grams) needed to test if the object is made of that particular metal. In the testing process the metal used is altered, so that quantity cannot be sold any more.

Find a way of performing the tests such that the expected profit is maximized.

### Standard input

The first line contains a two integers $N$ and $G$.

Each of the next $N$ lines contains two integers $p_i$ and $c_i$.

### Standard output

Print two non-negative integers $A$ and $B$, representing the fact that $\large\frac{A}{B}$ is an irreducible fraction equal to the exptected profit.

### Constraints and notes

$1 \leq G \leq 10^9$ $1 \leq N \leq 10^5$ $1 \leq c_i \leq G$ $\sum c_i \leq G$ $1 \leq p_i \leq 10^9$ $\sum c_i \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 2 5<br>10 2<br>1 1 | 22 1 | We only perform the second test (in case the test is unsuccessful we know the object is made of metal type $1$).We are left with $4$ grams, that have an equal probability to bring a profit $10$ or $1$ per gram. |
| 4 5<br>4 1<br>3 2<br>2 1<br>1 1 | 15 2 | We perform the tests $1\ 3\ 4$, in this order. |
| 3 10<br>10 4<br>3 3<br>2 1 | 32 1 | We test for $3$, and in case of failure for $2$ |
