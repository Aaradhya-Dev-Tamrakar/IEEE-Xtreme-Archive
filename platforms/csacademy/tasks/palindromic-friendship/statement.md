# Palindromic Friendship

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/palindromic-friendship/](https://csacademy.com/contest/archive/task/palindromic-friendship/)  

---

Consider a row of $N$ kids, numbered from $1$ to $N$, in order.

There are $M$ known friendship relations of type $(A, B)$ which means that $A$ and $B$ are friends. The friendship relation is symmetrical, meaning that if $A$ is friends with $B$, then $B$ is also friends with $A$.

Find the longest palindromic subarray, meaning that the first and the last kids in the subarray are friends, the second and second last are friends, and so on. If the subarray has odd length, we consider the middle kid to be a friend of himself.

### Standard input

The first line contains two integers $N$ and $M$.

The following $M$ lines contain the friendship relations between the kids.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N, M \leq 2 * 10^{5}$  $A_i \neq B_i$ If $A$ and $B$ are friends and $B$ and $C$ are also friends, that doesn't necessarly mean that $A$ is friends with $C$. 

| Input | Output |
| --- | --- |
| 3 3<br>1 2<br>3 1<br>2 3 | 3 |
| 100 1<br>1 100 | 1 |
