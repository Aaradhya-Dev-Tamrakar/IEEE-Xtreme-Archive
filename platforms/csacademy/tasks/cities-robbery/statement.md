# Cities Robbery

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/cities-robbery/](https://csacademy.com/contest/archive/task/cities-robbery/)  

---

There are $N$ cities placed in a line. For each city $i$ you know its coodinate $x_i$ and the amount of money $w_i$ its citizens have.

You are a robber and you have a car intially placed at coordinate $X$. The car has enough gas to last you for $K$ kilometers (each kilometer is represented as a unit on the axis). When you pass through a city you steal all the money of its citizens.

What is the maximum total amount you can steal? You can change direction as you wish, but you can't rob the same city twice.

### Standard input

The first line contains three integers $N$, $X$, and $K$.

Each of the next $N$ lines contains two integers $x$ and $w$ representing the coordinate of a city and the amount of money its citizens have.

### Standard output

Print a single integer representing the total amount you can steal.

### Constraints and notes

$1 \leq N \leq 10^5$ $-10^6 \leq x_i, X\leq 10^6$$0 \leq K \leq 10^9$ $1 \leq w_i \leq 10^9$The coordinates of the cities are distinct.There is no city at your starting point $X$.

| Input | Output |
| --- | --- |
| 4 0 3<br>-4 10<br>-1 1<br>1 1<br>4 10 | 2 |
| 4 0 4<br>-4 10<br>-1 1<br>1 1<br>4 10 | 11 |
| 4 3 7<br>0 9<br>4 1<br>5 5<br>7 8 | 15 |
