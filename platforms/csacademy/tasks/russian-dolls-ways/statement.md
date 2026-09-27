# Russian Dolls Ways

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/russian-dolls-ways/](https://csacademy.com/contest/archive/task/russian-dolls-ways/)  

---

You have $N$ Russian dolls, for the $i^{th}$ doll you know its size $A_i$.

A doll of size $j$ can be put inside a doll of size $i$ if $j < i$. In addition, a doll of size $i$ can nest only one smaller doll $j$. But that doll $j$, can nest another smaller doll, in a recursive manner.

For example, if you have three dolls of sizes $3$, $10$ and $7$, you can put the first doll inside the third, and then the third inside the second.

Your goal is to count the number of nestings that minimizes the number of dolls at the end.

Consider the array $P$ of size $N$ where $P_i$ is index of the doll in which the doll $i$ is nested into. If doll $i$ is not nested into any other doll, $P_i = 0$. Two ways are considered distinct if there is a $1 \leq i \leq N$ such that $P1_i \neq P2_i$.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$, the sizes of the dolls.

### Standard output

Output a single number representing the number of ways to nest the dolls in order to achieve the minimum number of dolls at the end, modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 2 3 | 1 | The minimum number of dolls at the end is $1$ |
| 4<br>1 2 2 3 | 4 | The minimum number of dolls at the end is $2$.The $P$ array from the input is$[2, 4, 0, 0]$$[2, 0, 4, 0]$$[3, 4, 0, 0]$$[3, 0, 4, 0]$ |
| 6<br>1 1 2 2 3 3 | 4 | The minimum number of dolls at the end is $2$.The $P$ array from the input is$[3, 4, 5, 6, 0, 0]$$[4, 3, 5, 6, 0, 0]$$[3, 4, 6, 5, 0, 0]$$[4, 3, 6, 5, 0, 0]$ |
