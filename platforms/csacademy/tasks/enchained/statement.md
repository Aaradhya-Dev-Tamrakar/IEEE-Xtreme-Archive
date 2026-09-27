# Enchained

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/enchained/](https://csacademy.com/contest/archive/task/enchained/)  

---

You have just casually ordered $N$ rectangular chain links of different lengths from your local vendor, in order to build a chain. You have then placed the chain links on a long line on the table. The $i^{th}$ such link has its ends in positions $l_i$ and $r_i$ respectively. ($0 \leq l_i, r_i \leq 10^9$). Such a link has a width of $1$ cm and a length of $r_i - l_i + 1$ cm .

  

A sequence of links $(l_1, r_1), (l_2, r_2), ..., (l_n, r_n)$ form a chain if the following conditions are valid:

All positions among $l_1, r_1, l_2, r_2, ..., l_n, r_n$ are distinct (no two links may share a common end)$l_1 < l_2 < ... < l_n$ $r_1 < r_2 < ... < r_n$ The intersection of $[l_i, r_i]$ and $[l_j, r_j]$ is not empty if and only if $|i - j| \leq 1$ ($i$ and $j$ are adjacent)   

Equivalently, the following relation must hold:

$l_1 < l_2 < r_1 < l_3 < r_2 <... < l_n < r_{n - 1} < r_n$

  

For example, $\{[1, 5], [4, 12], [10, 16], [14, 21], [19, 24]\}$ (see figure below), $\{[1, 5], [4, 9]\}$ and $\{[1, 4]\}$ are valid chains, whereas $\{[1, 3], [3, 4]\}$, $\{[1, 4], [2, 5], [3, 6]\}$ and $\{[1, 5], [2, 4]\}$ are not.

1  ההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההההXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  

You are not allowed to reposition any of the $N$ links; however, you are allowed to:

remove any number of links from the table (possibly none);add a single extra link of length $L$ to the table, once (possibly none) at integer coordinates.   

After performing these operations, what is the maximum length of a chain that you can obtain? Note that, a single link forms a valid chain, so there is at least one valid solution.

  

### Standard input

The first line contains a single integer $N$ and the length $L$ of the link to be added.

Each of the next $N$ lines describes one chain link. The line contains two integers, representing the left and the right endpoints of the $i^{th}$ chain link.

  

### Standard output

Print a single integer representing the maximum number of links of a chain that you can obtain after performing the operations.

  

### Constraints and notes

$1 \leq N \leq 2000$ $0 \leq l_i, r_i \leq 10^9$ $3 \leq L \leq 10^9$ $r_i - l_i + 1 \geq 3$, for all $i$.

| Input | Output |
| --- | --- |
| 4 9<br>1 5<br>10 16<br>19 24<br>14 21 | 5 |
| 4 7<br>1 5<br>10 16<br>19 24<br>14 21 | 4 |
| 3 4<br>1 4<br>2 5<br>3 6 | 3 |
