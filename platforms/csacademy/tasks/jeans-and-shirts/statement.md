# Jeans and Shirts

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/jeans-and-shirts/](https://csacademy.com/contest/archive/task/jeans-and-shirts/)  

---

You have $N$ pairs of jeans and $M$ shirts. Each pair of jeans as well as each shirt has a color. The colors are represented by integers in the range $[1, 1000]$. Count the number of ways you can choose a pair of jeans and a shirt such that the absolute difference between their colors is at least $K$.

### Standard input

The first line contains three numbers, $N$ $M$ and $K$.

The second line contains $N$ integers representing the colors of the pairs of jeans.

The third line contains $M$ integers representing the colors of the shirts.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq N, M \leq 1\ 000$ $1 \leq K \leq 1000$

| Input | Output | Explanation |
| --- | --- | --- |
| 2 2 5<br>10 20<br>12 15 | 3 | The second shirt can be paired with either jeans, but the first can only be paired with the jeans of color $20$. |
