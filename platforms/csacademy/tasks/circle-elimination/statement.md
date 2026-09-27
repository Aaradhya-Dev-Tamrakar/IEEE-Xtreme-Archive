# Circle Elimination

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/circle-elimination/](https://csacademy.com/contest/archive/task/circle-elimination/)  

---

There are $N$ distinct integers arranged on a circle. The distance between any two adjacent numbers is $1$. You travel on this circle, starting in the smallest number, then moving to the second smallest, third smallest, and so on until you reach the largest number. What's the minimum travel distance?

### Standard input

The first line contains a single integer $N$.

The second line contains the $N$ integers on the circle, in order.

### Standard output

Print the answer on the first line.

### Constraints and notes

$2 \leq N \leq 10^5$ The numbers on the circle are integers between $0$ and $10^9$ 

| Input | Output |
| --- | --- |
| 6<br>3 6 5 1 2 4 | 8 |
| 10<br>14 16 8 17 12 10 4 13 11 20 | 27 |
