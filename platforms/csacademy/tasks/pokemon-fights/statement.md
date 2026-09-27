# Pokemon Fights

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/pokemon-fights/](https://csacademy.com/contest/archive/task/pokemon-fights/)  

---

There are $N$ Pokemon standing in a straight line. For the $i^{th}$ Pokemon you know a coefficient $A_i$, representing its strength. If two Pokemon $i$ and $j$ fight, the one with greater coefficient wins. It is guaranteed all the $N$ coefficients are distinct.

The Pokemon start fighting from left to right. Initially the first two fight. The winner of this first fight will go on to fight the third Pokemon. The winner of this second fight will go on to fight the fourth Pokemon. To generalise, the winner of the $i^{th}$ fight will go on to fight the $(i+2)^{th}$ Pokemon.

Your task is to find out for each Pokemon how many fights it'll win.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers, the elements of $A$.

### Standard output

Print $N$ values representing the number of fights each Pokemon will win.

### Constraints and notes

$2 \leq N \leq 100$ $0 \leq A_i \leq 1000$ The elements of $A$ are distinct

| Input | Output |
| --- | --- |
| 5<br>1 5 2 3 10 | 0 3 0 0 1 |
| 4<br>1 3 5 7 | 0 1 1 1 |
| 3<br>3 2 1 | 2 0 0 |
