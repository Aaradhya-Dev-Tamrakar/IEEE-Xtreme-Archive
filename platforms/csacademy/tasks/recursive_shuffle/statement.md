# Recursive Shuffle

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/recursive_shuffle/](https://csacademy.com/contest/archive/task/recursive_shuffle/)  

---

We can perform the following algorithm on an array of size greater than $1$: take the elements on even positions and move them at the beginning of the array. After this step call the algorithm recursively for the prefix determined by the elements which were initially on even positions and the suffix determined by the elements which were initially on odd positions.

For example, let's consider the array $a\ b\ c\ d$. After the first step the array becomes $b\ d\ a\ c$. We make a recursive call on the first two elements and get $d\ b\ a\ c$. Next we make another call on the last two elements and get $d\ b\ c\ a$.

Let's take an array $v$ of size $N$ such that $v[i] = i$, for all $i$ and apply this algorithm on it. You are given another array $u$ of size $M$. Check if $v$ contains a subarray equal to $u$.

### Standard input

The first line contains two integer values $N$ and $M$.

The second line contains $M$ integers representing the array $u$.

### Standard output

The output should contain a single integer: $1$ if $u$ can be found as a subarray of $v$, or $0$ otherwise.

### Constraints and notes

$1 \leq N \leq 10^9$$1 \leq M \leq 10^5$The elements of $u$ are between $1$ and $N$

| Input | Output |
| --- | --- |
| 5 3<br>3 5 1 | 1 |
| 5 3<br>3 4 1 | 0 |
