# Water Bottles

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/water-bottles/](https://csacademy.com/contest/archive/task/water-bottles/)  

---

You have $N$ bottles in which you want to pour a total of $L$ litres of water. For each bottle $i$ you know two values $a_i$ and $b_i$, $a_i \leq b_i$. These values represent the minimum and the maximum volume of water you are can pour in bottle $i$.

Your goal is to minimize the difference between the maximum and the minimum volumes of water you pour in individual bottles.

### Standard input

The first line contains two integers $N$ and $L$.

Each of the next $N$ lines contains two integers $a_i$ and $b_i$.

### Standard output

Print a single number representing the minimum difference between the maximum and minimum volumes of water poured in the bottles.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq L \leq 10^{18}$ $0 \leq a_i \leq b_i \leq 10^9$ It is guaranteed there's always at least one valid solutionIn each bottle you have to pour an integer number of litres

| Input | Output | Explanation |
| --- | --- | --- |
| 3 9<br>1 5<br>3 4<br>2 4 | 0 | All water bottles can be filled with 3 litres of water |
| 5 16<br>1 1<br>2 2<br>3 5<br>2 6<br>5 5 | 4 | The bottles can be filled this way in the following way: $[1,2,5,3,5]$	The difference is $5-1=4$ and it's the best one that can be achieved. |
