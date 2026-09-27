# Popcorn

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/popcorn/](https://csacademy.com/contest/archive/task/popcorn/)  

---

We all know that popcorn is a culinary delicacy. While you were preparing for this year's selection camp (and the after parties), you ordered $N$ types of microwave popcorn. For each different type you know $3$ values:

$A_i =$ the time (in seconds) when the popcorn of type $i$ pops$B_i =$ the time (in seconds) then the popcorn of type $i$ gets burned$C_i =$ the quantity of popcorn of type $i$

You also have $M$ disposable popcorn bags of large capacity (practically, infinite) and a microwave oven. As, of course, no one likes burned or unpopped popcorn, you wish to partition it in the $M$ bags and then put those in the oven, setting a certain cooking time $prep_i$, such that in the end you'll have as much edible popcorn as possible.

Formally, the popcorn of type $i$ used in bag $j$, which was cooked in the oven $prep_j$ seconds, is edible if and only if $A_i \leq prep_j < B_i$.

Given $N$ types of popcorn and the number of available bags, you have to find a convenient partition and the cooking times for each bag, such that in the end you'll have as much edible popcorn as possible. Output the quantity of edible popcorn. Too simple!

### Standard input

The first line contains two integers $N$ and $M$.

Each of the next $N$ lines contains $3$ integers $A_i$, $B_i$, $C_i$, corresponding to each popcorn type.

### Standard output

Output a single integer representing the maximum quantity of edible popcorn you can get.

### Constraints and notes

$1 \leq M \leq N \leq 200\ 000$ $1 \leq A_i \leq B_i \leq 200\ 000$ The total quantity of popcorn doesn't exceed $10^9$ Some bags can be left empty!Let $X = max\{N, B[1], B[2], ..., B[N]\}$For 10 points: $X \leq 550$, $M \leq 100$For another 10 points: $X \leq 3 000$, $M \leq 50$For another 10 points: $M \leq X \leq 3 000$For another 10 points: $X \leq 50 000$, $M = 3$For another 20 points: $X \leq 50 000$, $M \leq 20$

| Input | Output |
| --- | --- |
| 5 2<br>2 4 3<br>1 5 6<br>4 8 10<br>7 8 2<br>10 11 2 | 21 |
| 3 3<br>1 2 2<br>2 3 3<br>1 3 5 | 10 |
