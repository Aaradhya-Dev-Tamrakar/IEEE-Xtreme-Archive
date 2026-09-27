# Donkey Paradox

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/donkey-paradox/](https://csacademy.com/contest/archive/task/donkey-paradox/)  

---

On a field represented as a matrix of $N$ rows and $M$ columns there is a donkey and two haystacks.

The donkey is really hungry and he wants to get to a haystack as fast as possible. He can walk in four directions: up, down, left or right. The paradox of the donkey is that if the two haystacks are equally close to him he won't be able to decide which one to choose and he will starve to death.

You are given the cells of the haystackes, but you don't know where the donkey is. Compute the number of cells where the donkey will starve if he's there.

### Standard input

The first line contains the two integers $N$ and $M$.

The second line contains two integers representing the row and the column of the first haystack.

The third line contains two integers representing the row and the column of the second haystack.

### Standard output

Output a single number representing the number of cells where the donkey will starve if he's there.

### Constraints and notes

$2 \leq N, M \leq 200$The haystacks and the donkey are situated in three different cells.The donkey takes into consideration only shortest routes to the haystacks.

| Input | Output | Explanation |
| --- | --- | --- |
| 6 6<br>2 5<br>4 4 | 0 | There are no cells equally close to the two haystacks. |
| 5 5<br>2 4<br>5 3 | 5 | The donkey will starve if he is one of these cells:$(3, 1)$$(3, 2)$$(3, 3)$$(4, 4)$$(4, 5)$ |
| 4 4<br>1 3<br>2 4 | 10 | $(1,4)$$(2,1)$$(2,2)$$(2,3)$$(3,1)$$(3,2)$$(3,3)$$(4,1)$$(4,2)$$(4,3)$ |
| 4 4<br>2 1<br>1 2 | 10 | $(1,1)$$(2,2)$$(2,3)$$(2,4)$$(3,2)$$(3,3)$$(3,4)$$(4,2)$$(4,3)$$(4,4)$ |
