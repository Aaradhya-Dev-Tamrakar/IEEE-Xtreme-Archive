# Combinatorix

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/combinatorix/](https://csacademy.com/contest/archive/task/combinatorix/)  

---

Legendary Petre is faced with a brand new challenge.

Consider a binary matrix $A$ of size $N \times M$. Petre starts in cell $(R_1, 1)$ and wants to reach cell $(R_2, M)$ by following a very specific procedure. More exactly, suppose Petre is currently standing in cell $(r, c)$, then his next visited cell will be:

$(r - 1, c)$ if $A_{r - 1,\ c} = 0$ and $(r - 1, c)$ has never been visited before$(r, c + 1)$ if $A_{r,\ c + 1} = 0$ and $(r, c + 1)$ has never been visited before and 1. doesn't apply$(r + 1, c)$ if $A_{r + 1,\ c} = 0$ and $(r + 1, c)$ has never been visited before and 1. and 2. don't apply.

Basically, at each step Petre tries to move up, then to the right, then down, always making sure not to move into a cell he has already visited before. If he cannot move in any of these $3$ cells, then he will stop and call his journey through the matrix unsuccessful. However, if he reaches the cell $(R_2, M)$ his journey will immediately end as successful.

Petre is old and his memory doesn't serve him as it used to, so it may be the case that $A_{l, c} =\ ?$ for some cells of $A$.

Your task is to find for how many assignments of elements from the set $\{0, 1\}$ to every $?$ element of $A$ Petre's journey would be successful. As the answer can be rather large, print it modulo $10^{9}+7$.

### Standard input

The first line contains $4$ integers $N$, $M$, $R_1$ and $R_2$.

Each of the following $N$ lines contains a string of $M$ characters, representing the matrix $A$.

### Standard output

Print on the first line the answer modulo $10^{9}+7$.

### Constraints

$1 \leq N, M \leq 1\ 000$ 

| Input | Output |
| --- | --- |
| 2 3 2 2<br>???<br>?0? | 5 |
| 3 3 1 2<br>0??<br>1??<br>?1? | 12 |
| 3 3 1 1<br>???<br>01?<br>??0 | 9 |
| 4 4 1 3<br>????<br>????<br>????<br>???? | 3492 |
