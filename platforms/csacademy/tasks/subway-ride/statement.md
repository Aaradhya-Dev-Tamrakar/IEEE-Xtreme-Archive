# Subway Ride

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/subway-ride/](https://csacademy.com/contest/archive/task/subway-ride/)  

---

A new subway route was build containing $N$ stations. There is a direct route from station $i$ to station $i+1$, $1 \leq i < N$ and from station $N$ to station $1$.

You want to plan in advance the purchase of a new train. You are aware that each time the train reaches station $i$ there will be $A_{i,j}$ people wanting to go from station $i$ to station $j$.

The train will start the new endless journey at station $1$ with no passengers in it and it'll will continue the route until the end of time.

Find the minimum capacity of the train such that at any moment of time the train can accommodate all its passengers.

### Standard input

The first line contains one integer $N$.

Each of the next $N$ lines contain $N$ integers representing the elements of matrix $A$.

### Standard output

Print the minimum capacity of the train

### Constraints and notes

$2 \leq N \leq 300$ $A_{i,i} = 0, 1 \leq i \leq N$ The sum of the elements in matrix $A$ will be at least $1$ and at most $10^9$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>0 1 1<br>1 0 1<br>1 1 0 | 3 |  |
| 3<br>0 0 0<br>0 0 0<br>2 0 0 | 2 | There are $2$ people traveling from city $N$ to city $1$ |
| 3<br>0 3 0<br>0 0 4<br>2 0 0 | 4 | Note that when the train reaches a station people get off before anyone from that station is entering the train. |
