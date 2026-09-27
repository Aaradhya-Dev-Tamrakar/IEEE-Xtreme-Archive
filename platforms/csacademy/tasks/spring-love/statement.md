# Spring Love

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/spring-love/](https://csacademy.com/contest/archive/task/spring-love/)  

---

There's an old game called He loves me... he loves me not. The person picks petals from the flower thinking about a special someone. At the end if the number of picked petals is odd the special someone is in love. You're about find out the outcome of the game. You know there's a garden with $N$ flowers, flower $i$ having $P_i$ petals. At the end of the game all petals from all flowers will be picked. Find out is the special someone is in love or not.

### Standard input

The first line contains an integer $N$ the number of flowers in the garden.

The second line contains $N$ integers, the values of array $P$.

### Standard output

The first line should contain the answer to the question. Print $1$ is the special someone is in love or $0$ otherwise.

### Constraints and notes

$1 \leq N \leq 100$ $3 \leq P_i \leq 20$

| Input | Output | Explanation |
| --- | --- | --- |
| 1<br>3 | 1 | It looks like a clovers luck comes in different shapes. |
| 3<br>3 4 5 | 0 |  |
| 1<br>16 | 0 |  |
