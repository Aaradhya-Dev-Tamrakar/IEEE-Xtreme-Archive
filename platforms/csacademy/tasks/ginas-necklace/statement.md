# Gina's Necklace

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/ginas-necklace/](https://csacademy.com/contest/archive/task/ginas-necklace/)  

---

Gina, Gică's little sister, has just received a very pretty (and expensive) gift: a necklace in the form of a circle of length $M$, with $N$ shiny pebbles on it! However, the necklace is not quite ordinary, in the sense that the pebbles are stuck in place and hard to move, and at the moment they're in a huge mess!

Fortunately, Gina can ask Gică to move some of the pebbles on it, in order to make it prettier. The cost of moving one pebble one position to its left or its right is 1. Gina wants the pebbles to be at consecutive positions in the necklace in the end, and doesn't want to bother her brother too much, so she is wondering what would be the minimum cost to do so.

Formally, the necklace is good if the pebbles form a contiguous strip of neighboring positions, where two positions are neighbors if they differ by $1$. Also, because the necklace is circular, positions $1$ and $M$ are neighbors.

### Standard input

The first line contains $N$ the number of pebbles on the necklace and $M$, the length of the necklace.

On each of the following $N$ lines there is a number $x_i$ ($1 \leq x_i \leq M$), denoting the position of each of the pebbles.

### Standard output

The first line should contain a single number $c$, denoting the total cost of moving the pebbles on consecutive positions within the ring.

### Constraints and notes

$1 \leq N \leq M \leq 3 \cdot 10^3$All pebbles in the input are at distinct positions.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 10<br>4 <br>6 <br>8 | 2 | We move the first pebble one position to the right, and the last pebble one position to the left. Therefore, the pebbles would end up in positions $5, 6, 7$, which is a solution to our problem. |
| 2 20<br>18<br>2 | 3 | We move the first pebble two positions to the right, and the second one position to the left, and we obtain the sequence $20, 1$ which is valid. Another possible solution would be to move the first pebble one position to the right, and the second pebble two positions to the left, ending up in a different configuration: $19, 20$ |
