# Fill the Glasses

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/fill-the-glasses/](https://csacademy.com/contest/archive/task/fill-the-glasses/)  

---

You have $N$ glasses, for each of them you know their capacity, expressed as an integer. You buy water in bottles of capacity $100$. What's the minimum number of bottles you need in order to fill at least $K$ glasses?

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the capacities of the glasses.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq K \leq N \leq 100$ The capacities of the glasses are integers between $1$ and $1\,000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5 4<br>1 2 3 2 1 | 1 | Filling the glasses with capacities $2, 3, 2, 1$ requires $8$ units. This way, it's enough to open just $1$ bottle. |
| 4 3<br>200 150 140 300 | 5 | $200 + 150 + 140 = 490$, hence the $5$ bottles of water required. |
| 3 1<br>1000 1000 1000 | 10 | To fill any glass of water are required $10$ bottles of water. |
