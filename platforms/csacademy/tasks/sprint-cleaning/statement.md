# Spring Cleaning

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/sprint-cleaning/](https://csacademy.com/contest/archive/task/sprint-cleaning/)  

---

A network consisting of $N$ computers has been compromised by a virus. Initially, all computers are infected. Each computer $i$ ($1 \leq i \leq N$) has a direct access to one another computer, $P_i$.

The virus has a glitch that you can use in the following way: if a computer $i$ is infected with a virus, you can use it to clean up the computer $P_i$. Note that computer $P_i$ will no longer contain a virus and therefore cannot clean up other computers.

Print a sequence of moves that cleans as many computers as possible.

### Standard input

The first line contains an integer $N$.

The next line contains $N$ integers, representing $P$.

### Standard output

Print a sequence of moves of type $A\ B$, which means $A$ cleans $B$.

At that point of time, both $A$ and $B$ have to be infected.

Print each move on a separate line.

### Constraints and notes

$2 \leq N \leq 10^5$ $1 \leq A, B \leq N$ $1 \leq P_i \leq N$ $P_i \neq i$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>2 1 2 | 2 1<br>3 2 | 123 |
| 5<br>2 3 1 3 4 | 1 2<br>3 1<br>4 3<br>5 4 | 12345 |
| 7<br>2 3 4 5 6 3 1 | 5 6<br>4 5<br>3 4<br>2 3<br>1 2<br>7 1 | 1234567 |
