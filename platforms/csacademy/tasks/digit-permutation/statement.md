# Digit Permutation

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/digit-permutation/](https://csacademy.com/contest/archive/task/digit-permutation/)  

---

In this problem we consider $N$ numbers in base $K$, all having $M$ digits. Each number is represented as an array of length $M$ with values between $0$ and $K-1$, each corresponding to a digit.

You should find any permutation $p$ of size $K$ (0-indexed, containing elements from $0$ to $K-1$), such that after replacing each digit $d$ with $p(d)$, the following restrictions are met:

there are no leading $0$sthe numbers are in strictly increasing order

### Standard input

The first line contains three integers $N$, $K$ and $M$.

Each of the next $N$ lines contains $M$ integers between $0$ and $K-1$, representing the initial numbers. Note that they can contain leading $0$s, even though after applying the permutation they shouldn't.

### Standard output

If there is no solution output $-1$.

Otherwise, print the $K$ elements of $p$ on the first line.

### Constraints and notes

$2 \leq N, M, K \leq 10^5$ $1 \leq N*M \leq 10^5$ Any solution that respects the given constraints is considered correct 

| Input | Output | Explanation |
| --- | --- | --- |
| 4 5 3<br>0 3 4<br>0 4 1<br>2 1 0<br>1 2 2 | 1 4 2 0 3 | After applying $p(d)$, the numbers will become103134241422All numbers are in base 5 |
| 3 2 2<br>0 1<br>1 1<br>1 0 | -1 |  |
