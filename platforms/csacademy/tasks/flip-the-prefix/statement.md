# Flip the Prefix

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/flip-the-prefix/](https://csacademy.com/contest/archive/task/flip-the-prefix/)  

---

You are given an array $A$ of $N$ elements. You can take any prefix of $A$ and multiply each element of the prefix with $-1$. Your goal is to maximise the sum of all the elements.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

The first line should contain the maximum sum you can get.

The second line should contain the indices of the chosen prefixes. If the solution is not unique, you can print any of them.

### Constraints and notes

$1 \leq N \leq 10^5$ $-10^4 \leq A_i \leq 10^4$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 -2 -3 4 | 10<br>3 1 | By flipping the prefix $3$, the array becomes-1 2 3 4After flipping the prefix $1$, the array becomes1 2 3 4Giving the sum $10$ |
| 4<br>1 2 3 4 | 10 | No need to flip anything. Just print the sum. |
| 6<br>1 2 0 -4 -5 -6 | 18<br>2 6 | By flipping the prefix $6$, the array becomes-1 -2 0 4 5 6After flipping the prefix $2$, the array becomes1 2 0 4 5 6Giving the sum $18$Note that you can also flip the prefix $3$ instead of $2$ |
