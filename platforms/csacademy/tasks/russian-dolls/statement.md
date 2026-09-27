# Russian Dolls

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/russian-dolls/](https://csacademy.com/contest/archive/task/russian-dolls/)  

---

You have $N$ Russian dolls, for the $i^{th}$ doll you know its size $A_i$.

A doll of size $j$ can be put inside a doll of size $i$ if $j < i$. In addition, a doll of size $i$ can nest only one smaller doll $j$. But that doll $j$, can nest another smaller doll, in a recursive manner.

For example, if you have three dolls of sizes $3$, $10$ and $7$, you can put the first doll inside the third, and then the third inside the second.

Your goal is to find a nesting of the dolls such that all the dolls that are not nested inside another doll have the same size. Of course, this might not be possible, so you are allowed to take any doll of size $i > 1$, and exchange it for two dolls of size $i-1$. Find the minimum number of exchange operations in order to reach your goal.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$, the sizes of the dolls.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq A_i \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>3 10 7 | 0 | The solution that doesn't use any exchange  is the following:put the first doll inside the thirdput the third inside the second |
| 7<br>1 1 2 2 3 3 4 | 1 | Exchange the doll of size $4$ for $2$ dolls of size $3$In the end there are: $2$ dolls of size $1$ $2$ dolls of size $2$ $4$ dolls of size $3$ It's possible to nest the dolls in the manner described in the input. |
| 5<br>2 2 2 3 3 | 1 | Exchange one doll of size $2$ for $2$ dolls of size $1$In the end there are: $2$ dolls of size $1$ $2$ dolls of size $2$ $2$ dolls of size $3$ It's possible to nest the dolls in the manner described in the input. |
| 5<br>1 1 1 3 3 | 2 | Note that it's not possible to exchange a doll of size $1$Exchange $2$ doll of size $3$ for $4$ dolls of size $2$In the end there are: $3$ dolls of size $1$ $4$ dolls of size $2$ It's possible to nest the dolls in the manner described in the input. |
