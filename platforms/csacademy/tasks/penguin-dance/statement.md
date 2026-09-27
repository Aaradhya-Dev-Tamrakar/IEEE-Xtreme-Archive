# Penguin Dance

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/penguin-dance/](https://csacademy.com/contest/archive/task/penguin-dance/)  

---

The penguin dance is a simple dance which follows $9$ repetitive moves. $N$ people sit in a line, all performing the dance steps at once. The moves are :

right foot outsideright foot outsideleft foot outsideleft foot outsidejump forwardjump backwardsjump forwardjump forwardjump forward

Considering $N$ people sitting in a line which have already performed $T$ dance moves, you need to find out what person is located in the spot marked with $P$. Before the dance starts, the first person, numbered with $1$, is located at the back of the line, in the spot market with $1$.

If a person is sitting in $X$th spot and he needs to perform a $\text{jump forward}$ move, he'll advance into spot $(X + 1)$. If he needs to perform a $\text{jump backwards}$ move, he'll move to spot $(X - 1)$. For the $\text{right foot outside}$ and $\text{right foot outside}$ he won't change the spot he is located into.

### Standard input

The first line contains three integers $N$, $P$ and $T$.

### Standard output

The first line should contain one integer, the answer to the problem. If the $P$th spot is occupied by a person, print that person's number. If the spot is not occupied by anyone, print $-1$.

### Constraints and notes

$1 \leq N \leq 1000$ $1 \leq P \leq 5000$ $1 \leq T \leq 1000$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 1 4 | 1 | Each of the following test cases describe how the dancers will occupy their spots during the dance.A 1 represents the spot taken by the first dancer and a . represents an empty spot.123.... |
| 3 2 5 | 1 | .123... |
| 3 1 6 | 1 | 123.... |
| 3 2 7 | 1 | .123... |
| 3 3 8 | 1 | ..123.. |
| 3 4 9 | 1 | ...123. |
| 3 3 9 | -1 | ...123. |
| 3 7 9 | -1 | ...123. |
