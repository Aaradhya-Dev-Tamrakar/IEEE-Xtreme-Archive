# Global Warming

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/global-warming/](https://csacademy.com/contest/archive/task/global-warming/)  

---

Global warming is an important issue and Johnny knows about it. He decided to make an analysis of historical temperatures and find a subsequence of days (not necessarily consecutive) where the temperature was strictly increasing. It will convince the non-believers!

Johnny has found historical data from $n$ consecutive days. The temperature on the $i$-th day was $t_i$.

Formally, we are interested in finding the length of the longest increasing subsequence (LIS) of $(t_1, t_2, ..., t_n)$, that is, the largest possible $k$ for which it is possible to choose an increasing sequence of indices $1 \le a_1 < a_2 < ...< a_k \le n$ such that $t_{a_1} < t_{a_2} < ...< t_{a_k}$.

Johnny wants to find a really long subsequence and that is why he decided to cheat a bit. He will first choose a non-empty interval of days and an integer $d$($-x \le d \le x$) and he will increase the temperature in each of those days by $d$. A small change like that probably will not be noticed by the community, while at the same time it should make the LIS longer. It is allowed to choose $d = 0$.

What is the largest possible length of the LIS after a change?

### Standard input

The first line contains two space-separated integers $n$ and $x$, the number of days and the limit for the absolute value of $d$.

The second line contains $n$ integers $t_1, t_2, ..., t_n$ separated by spaces, the sequence of historical temperatures.

### Standard output

Print one integer, the largest possible length of the LIS after a single change.

### Constraints and notes

$1 \le n \le 200\,000$, $0 \le x \le 10^9$ $1 \le t_i \le 10^9$  

### Subtasks

SubtaskAdditional constraintsNumber of points1$n, x \le 10$$5$2$n, x \le 50$$10$3$n \le 1000$$13$4$x = 0$$10$5$x \le 5$, $n \le 50\,000$$20$6$x = 10^9$$17$7no additional constraints$25$

| Input | Output | Explanation |
| --- | --- | --- |
| 8 10<br>7 3 5 12 2 7 3 4 | 5 | Johnny can choose an interval $[2, 3]$ and $d = -5$, which means decreasing $t_2$ and $t_3$ by $5$. In this case the new sequence is $(7, -2, 0, 12, 2, 7, 3, 4)$, where he can find a LIS $(-2, 0, 2, 3, 4)$.The length of the LIS is $5$ |
