# Ball Sampling

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/ball-sampling/](https://csacademy.com/contest/archive/task/ball-sampling/)  

---

You have a box with balls of $N$ colors. For each color $i$ you know the number $A_i$ of balls having that color. You randomly pick a ball from the box using a uniform distribution, and then you put it back in the box.

What's the expected number of picks in order to choose a ball of each color at least once?

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array $A$.

### Standard output

Print a single number representing the expected number of picks.

### Constraints and notes

$1 \leq N \leq 20$ $1 \leq A_i \leq 100$ An answer is considered correct if the absolute difference between it and the official answer is less than $10^{-6}$. 

| Input | Output |
| --- | --- |
| 3<br>1 2 3 | 7.3000000000 |
