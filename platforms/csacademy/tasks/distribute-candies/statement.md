# Distribute Candies

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/distribute-candies/](https://csacademy.com/contest/archive/task/distribute-candies/)  

---

You should distribute $N$ candies in $K$ boxes such that the difference between the maximum and the minimum number of candies in a box is minimized. In addition, every pair of consecutive boxes should have a different number of candies.

### Standard input

The first line contains two integers $N$ and $K$.

### Standard output

If there is no solution output $-1$.

Otherwise, print $K$ numbers on the first line, representing the number of candies in each box.

### Constraints and notes

$1 \leq N \leq 10^{18}$ $1 \leq K \leq 10^5$ Each box has to have a strictly positive amount of candiesIf the solution is not unique you can print any of them

| Input | Output |
| --- | --- |
| 15 2 | 8 7 |
| 16 4 | 3 5 3 5 |
| 100 80 | -1 |
