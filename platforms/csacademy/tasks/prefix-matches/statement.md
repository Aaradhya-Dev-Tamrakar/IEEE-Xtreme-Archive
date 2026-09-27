# Prefix Matches

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/prefix-matches/](https://csacademy.com/contest/archive/task/prefix-matches/)  

---

For a string $S$ of size $N$, we say $A_i$ is the size of the longest prefix that can be found again in $S$ starting at index $i$. $A_1$ is not defined.

On the other hand, $B_i$ is the size of the longest prefix that can be found again in $S$ ending at index $i$. $B_i$ is strictly less than $i$, $B_1$ is not defined.

For example, if $S=ababacaba$, $A=[-,0, 3, 0,1,0,3,0,1 ]$ and $B=[-,0,1,2, 3,0,1,2,3]$

You don't know $S$, but given $A$, find  $B$.

### Standard input

The first line contains a single integer $N$.

The second line contains $N-1$ integers. The $i^{th}$ number is $A_{i+1}$.

### Standard output

Print $N-1$ value on the first line. The $i^{th}$ number is $B_{i+1}$.

### Constraints and notes

$2 \leq N \leq 10^5$ It is always possible to generate a string $S$ corresponding to $A$ using an alphabet of size at most $10^5$.It is guaranteed the answer is unique.

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>2 1 0 2 1 | 1 2 0 1 2 | A possible string is:$aaabaa$ |
| 5<br>4 3 2 1 | 1 2 3 4 | $aaaaa$ |
| 6<br>0 3 0 1 0 | 0 1 2 3 0 | $ababac$ |
| 11<br>0 1 0 3 0 3 0 2 0 0 | 0 1 0 1 2 3 2 3 2 0 | $abacabababc$ |
