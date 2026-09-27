# Jolteon

**Time Limit:** `3000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/jolteon/](https://csacademy.com/contest/archive/task/jolteon/)  

---

Spark, the leader of team Instinct, has given his Jolteon as a present an array $V$ of size $N$. Jolteon plays with the array, choosing subarrays and examining them closely. Being a Pokemon who hates neutrality, Jolteon defines a subarray as being electrifying if, for every natural number $x$, one of the following two conditions holds:

$x$ doesn't occur in the subarray$x$ occurs in the subarray an odd number of times

Help Jolteon find the number of electrifying subarrays.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers, the elements of $V$.

### Standard output

Print the number of electrifying subarrays on the first line.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq V_i \leq 10^6$ For 20% of the test cases $N \leq 1000$

| Input | Output |
| --- | --- |
| 4<br>2 2 2 3 | 7 |
