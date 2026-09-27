# Stargazing

**Time Limit:** `500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/stargazing/](https://csacademy.com/contest/archive/task/stargazing/)  

---

Gică just stumbled upon $Q$ star observations in an old attic which were done in a span of $N$ days numbered from $1$ to $N$. Quickly he realised that some of them contain a bright light and without hesitation he concluded that the aliens visited earth in the past. His theory goes as following: the aliens first visited Earth on day $s$ and they had $n$ visits in total, each of them being $k$ days after the last one.

More formally, the aliens visited earth on days

$s$ $s + k$ $s + 2 \cdot k$ $...$ $s + (n - 1) \cdot k$ 

You are given the $Q$ observations, the $i^{th}$ one being characterised by the pair $(t_i, d_i)$ where $d_i$ represents the day when the observation was done and $t_i$ represents if there was a bright light or not. If $t_i = 1$ it means there was one while if $t_i = 0$ there was no such bright light.

You want to find out the possible number of tuples $(s, n, k)$ characterising the alien visit such that the observations do not contradict this values. More formally:

If there was a bright light spotted at time $d_i$ the aliens must have visited the earth at day $d_i$.If no bright light  was spotted at time $d_i$ the aliens must not have visited the earth at day $d_i$.

Note that using some good deduction Gică has some more interesting findings:

each alien's visit was between days $1$ and $N$, meaning $1 \leq s$ and $s + (n - 1) \cdot k \leq N$ (the last day when the aliens visited the earth).there are at least $2$ times when the bright light was spotted in the $Q$ observations. In other words, it is guaranteed that there are at least $2$ observations in input data with $t_i = 1$.

### Standard input

The first line contains $2$ integers $N$ and $Q$.

Each of the next $Q$ lines contains $2$ integers $t_i$ and $d_i$.

If $t_i = 1$ a bright light  was seen on day $d_i$, while if $t_i = 0$ there was no bright light on day $d_i$.

### Standard output

The first line should contain the number of tuples of form $(s, n, k)$ modulo $10^9+7$.

### Constraints and notes

$2 \leq N \leq 10^{12}$ $2 \leq Q \leq 10^5$ $1 \leq d_i \leq N$ for each $1 \leq i \leq Q$ All values of $d_i$ are pairwise distinct.There are at least $2$ times when the bright light was spotted.

| Input | Output | Explanation |
| --- | --- | --- |
| 10 2<br>1 4<br>1 10 | 9 | The $9$ possible ways are as following (showing the days in which the aliens visited earth):$[4, 10]$ $[4, 7, 10]$ $[4, 6, 8, 10]$ $[2, 4, 6, 8, 10]$ $[1, 4, 7, 10]$ $[4, 5, 6, 7, 8, 9, 10]$ $[3, 4, 5, 6, 7, 8, 9, 10]$ $[2, 3, 4, 5, 6, 7, 8, 9, 10]$ $[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]$ |
| 14 2<br>1 4<br>1 10 | 31 |  |
| 14 3<br>0 14<br>1 10<br>1 4 | 25 |  |
| 30 8<br>1 10<br>1 28<br>1 22<br>0 4<br>0 2<br>0 1<br>0 7<br>0 23 | 8 | The $8$ possible ways are as following (showing the days in which the aliens visited earth):$[10, 16, 22, 28]$ $[10, 13, 16, 19, 22, 25, 28]$ $[10, 12, 14, 16, 18, 20, 22, 24, 26, 28]$ $[8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28]$ $[6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28]$ $[10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30]$ $[8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30]$ $[6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30]$ Note that the solution $[10..28]$ is not valid because we did not observe a bright light on day $23$ |
