# Socks Pairs

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/socks-pairs/](https://csacademy.com/contest/archive/task/socks-pairs/)  

---

In a drawer you have some socks of $N$ colors. For each color $i$ you know the number of socks $A_i$ having that color. You can match two socks of the same color to make a pair, but not two of different colors.

If you pick the socks without looking in the drawer, what's the minimum number of socks you need to be sure you can make at least $K$ pairs?

### Standard input

The first line contains two integers $N$ and $K$.

The second lines contains $N$ integers representing the elements of $A$.

### Standard output

If there is no solution output $-1$. Otherwise print a single integer representing the minimum number of socks needed.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 10^5$ $1 \leq K \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 1 3<br>10 | 6 | The first $6$ socks you take out of the drawer have the same color, so you can make $3$ pairs. |
| 3 2<br>1 3 2 | 6 | You should take all the socks in the worst case. |
