# Addition Time

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/addition-time/](https://csacademy.com/contest/archive/task/addition-time/)  

---

You have been given a set $a$ of numbers and a number $X$. You know that this set is special: more specifically, for any possible integer $s$, there is at most one subset of numbers from $a$ which sums up to $s$.

  

You are asked to find the subset of numbers from this set which sums up to $X$, or report that there aren't any. Note that, due to the restrictions imposed on the set $a$, the answer must be unique.

  

### Standard input

  

The first line contains two integers $N$ and $X$, the number of elements in his set and the required sum of the subset respectively.

The second line contains $N$ integers, the elements of the set $a$, in strictly increasing order.

  

### Standard output

  

The first line should contain the number of elements of the subset which sums up to $X$. The second line should contain the elements of this subset, in strictly increasing order. If there is no such subset, output a single line with "-1" (without quotes).

  

### Constraints and notes

  
$1\leq N\leq 10^3$ $1\leq a_i\leq 10^{12}$ $1 \leq X \leq \sum_{i = 1}^N a_i$

| Input | Output |
| --- | --- |
| 5 26<br>1 2 4 8 20 | 3<br>2 4 20 |
| 3 39<br>2 35 38 | -1 |
