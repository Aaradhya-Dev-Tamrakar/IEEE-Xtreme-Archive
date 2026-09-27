# K-consecutive

**Time Limit:** `2000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/k-consecutive/](https://csacademy.com/contest/archive/task/k-consecutive/)  

---

Count the number of permutations of size $N$ respecting the following property:

Every subarray consisting of consecutive elements in increasing order has length at most $K$.

### Standard input

The first line contains the two integers $N$ and $K$.

### Standard output

Output a single number representing the number of valid permutations modulo $10^9+7$.

### Constraints and notes

$1 \leq N \leq 5000$$1 \leq K \leq N$For 15% of the test cases $N \leq 10$For 25% of the test cases $N \leq 100$ and $K=1$For 50% of the test cases $N \leq 200$For 35% of the test cases $N \leq 1000$ and $K=1$For 70% of the test cases $N \leq 1000$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 1 | 11 | The 11 valid permutations are:$1\ 3\ 2\ 4$$1\ 4\ 3\ 2$$2\ 1\ 4\ 3$$2\ 4\ 1\ 3$$2\ 4\ 3\ 1$$3\ 1\ 4\ 2$$3\ 2\ 1\ 4$$3\ 2\ 4\ 1$$4\ 1\ 3\ 2$$4\ 2\ 1\ 3$$4\ 3\ 2\ 1$ |
| 4 2 | 21 | The the total of $24$ permutations only $3$ are invalid:$1\ 2\ 3\ 4$$4\ 1\ 2\ 3$ $2\ 3\ 4\ 1$ |
| 20 10 | 113303983 | The result should be printed mod $10^9+7$. |
| 20 20 | 146326063 | All $20!$ permutations are valid. |
| 40 15 | 699582586 | The result should be printed mod $10^9+7$. |
