# Plants

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/plants/](https://csacademy.com/contest/archive/task/plants/)  

---

You have $N$ plants and $M$ rooms.

For each room $i$ you know its temperature $T_i$. For each plant $i$ you are given an interval $[A_i, B_i]$, representing the temperatures for which the plant is able to survive.

Determine for each plant in how many rooms you can place it in order for it to survive.

### Standard input

The first line contains two integers $N$ and $M$.

The second line contains $M$ integers representing the elements of $T$.

Each of the next $N$ lines contains two integer $A_i$ and $B_i$.

### Standard output

Print $N$ integers, each on a distinct line, the $i^{th}$ integer representing the number of rooms for the $i^{th}$ plant.

### Constraints and notes

$1 \leq N, M \leq 100$ $0 \leq T_i \leq 100$ $0 \le A_i \le B_i \le 100$

| Input | Output | Explanation |
| --- | --- | --- |
| 4 5<br>5 1 4 4 3<br>2 4<br>1 2<br>3 4<br>0 100 | 3<br>1<br>3<br>5 | $1^{st}$  plant can survive in the rooms: $3, 4, 5$$2^{nd}$ plant: $2$$3^{rd}$ plant: $3, 4, 5$$4^{th}$ plant: $1, 2, 3, 4, 5$ |
| 3 4<br>5 2 2 4<br>6 10<br>1 2<br>4 5 | 0<br>2<br>2 | $1^{st}$  plant can't survive in any room$2^{nd}$ plant: $2, 3$$3^{rd}$ plant: $1, 4$ |
