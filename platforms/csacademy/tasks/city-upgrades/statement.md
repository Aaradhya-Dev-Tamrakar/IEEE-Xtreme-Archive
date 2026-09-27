# City Upgrades

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/city-upgrades/](https://csacademy.com/contest/archive/task/city-upgrades/)  

---

There are $N$ cities placed in a line. For each city $i$ you know its coodinate $x_i$. You can upgrade exactly $K$ of these cities. Your goal is to choose what cities to upgrade in a way the minimizes the maximum distance between a regular city and the closest upgraded one.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the coordinates of the cities.

### Standard output

Print a single integer representing the smallest maximum distance between a regular city and the closest upgraded one.

### Constraints and notes

$1 \leq K < N \leq 10^5$ $0 \leq x_i \leq 10^9$

| Input | Output |
| --- | --- |
| 3 1<br>0 3 4 | 3 |
| 5 2<br>1 2 4 5 10 | 3 |
| 5 3<br>6 4 2 8 12 | 2 |
