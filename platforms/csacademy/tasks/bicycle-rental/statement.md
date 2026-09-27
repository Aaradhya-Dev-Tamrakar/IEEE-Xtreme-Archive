# Bicycle Rental

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/bicycle-rental/](https://csacademy.com/contest/archive/task/bicycle-rental/)  

---

You are at work and want to get back home as soon as possible. You should choose one of $N$ available bicycles for rent. For each of them you know 3 values:

The amount of time you need to walk to the rental placeThe time when the bicycle becomes availableThe amount of time it takes you to pedal back home

Initially, consider it's moment $0$ in time.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains $3$ integers representing the values corresponding to a bicycle.

### Standard output

Print the minimum moment in time when you can get back home.

### Constraints and notes

$1 \leq N \leq 1000$ All the other numbers in the input are integers between $1$ and $10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>2 4 2<br>3 2 4<br>1 9 1 | 6 | Although you can reach the first bicycle's rental place in 2 units of time, it only becomes available at moment 4, so you can get home with it at moment 6.For the second bicycle, it becomes available at moment 2, but you can only get there at moment 3, so you can only arrive home at moment 7. |
