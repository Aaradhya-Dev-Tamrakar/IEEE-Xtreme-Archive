# Circle Kingdom

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/circle-kingdom/](https://csacademy.com/contest/archive/task/circle-kingdom/)  

---

There are N cities in a kingdom, represented by unique integers from 1 to N.

For each $i(1 \leq i < N)$, there is a bidirectional road from city $i$ to city $i+1$, of length $C_i$. Also there is a bidirectional road from city $N$ to city $1$, of length $C_N$.

You need to select a city to become the capital of the kingdom. We define the distance from the capital to a city as the shortest path from the capital to that city. We also define the cost of choosing a capital as the maximum distance from the capital to any of the cities.

Find the city that, if chosen to be the capital, minimizes this cost. If there are multiple solutions, you must consider the city with the smallest assigned number.

### Standard input

The first line contains $N$ the number of cities.

The second lines contains $N$ integers, where the $i$-th integer represents $C_i$.

### Standard output

The first line will contain the number of the city chosen to become the capital of the kingdom.

### Constraints and notes

$3 \leq N \leq 5000$ $1 \leq C_i \leq 10^5$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 2 1 4 | 2 | If we choose the capital to be 2, the maximum distance from the capital to a city is 3. This can also be achieved by choosing city number 3 to be the capital, but 2 is smaller than 3, so you have to output 2. |
