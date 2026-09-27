# Diesel Train

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/diesel-train/](https://csacademy.com/contest/archive/task/diesel-train/)  

---

A diesel train travels between two cities in a straight line. We can represent the route as a segment on the x-axis, where the starting city is the origin and the destination is a point at coordinate $D$. The length of the train is $L$. Initially, the locomotive is in the starting city and the journey ends when the locomotive reaches the destination (the total distance traveled is $D$).

There are $N$ gas stations on the route, for each of them you know its x coordinate. There are also $2$ extra gas stations, in the starting and the destination cities.

If the train runs out of gas, it will have to be pushed to the nearest gas station. The refueling system is built in such a way that it's enough if the gas station is next to any part of the train, not necessarily the locomotive. This means in many cases the train won't have to be pushed at all. Note that in some cases the train will have to be pushed backward (the opposite direction of its route to the destination).

If the train runs out of gas when the locomotive is at a uniformly distributed random coordinate (real) between $0$ and $D$, what is the expected distance it will have to be pushed?

### Standard input

The first line contains three integer $D$, $L$ and $N$.

The second line contains the coordinates of the gas stations.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq D \leq 10^9$ $1 \leq L \leq D$ $0 \leq N \leq 10^5$ The coordinates of the gas stations will be distinct integers between $1$ and $D-1$ The result is checked with a precision of $10^{-6}$

| Input | Output |
| --- | --- |
| 9 2 3<br>8 3 4 | 0.1388889 |
| 7 3 1<br>3 | 0.0357143 |
| 10 3 3<br>3 1 6 | 0.0250000 |
| 5 3 0 | 0.2000000 |
