# Shoe Pairs

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/shoe-pairs/](https://csacademy.com/contest/archive/task/shoe-pairs/)  

---

You have $N$ shoes, for each of them you know its size and whether it's a left or a right shoe.

Any left shoe can be paired with any right shoe of the same size. What's the maximum number of pairs you can make?

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines describes one shoe. The line contains an integer, representing the size of the shoe, followed by a character: L in the case of a left shoe, or R in the case of a right shoe.

### Standard output

Print a single integer representing the maximum number of shoe pairs.

### Constraints and notes

$1 \leq N \leq 1000$ The shoe sizes are integers between $1$ and $100$

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 L<br>1 L<br>3 R<br>3 L<br>1 R | 2 | We can make one pair of size $1$ and one of size $3$ |
| 4<br>2 L<br>2 L<br>2 L<br>3 R | 0 | We cannot make a pair using two left shoes. |
| 6<br>1 L<br>2 R<br>2 L<br>2 L<br>1 L<br>1 R | 2 | We can make one pair of size $1$ and one of size $2$ |
