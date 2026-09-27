# Anagram Sort

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/anagram-sort/](https://csacademy.com/contest/archive/task/anagram-sort/)  

---

The judge has an array $A$ of size $N$.

Given its elements sorted non-decreasingly by their value, find their order with respect to $A$.

### Interaction

The judge will provide an integer $N$, followed by the elements in non-decreasing order.

In order to find $A$, you may provide $B$, an array containing the elements of $A$ in an order you've chosen and the judge will return a cost equal to the minimum number of swaps between consecutive positions which may be applied on $B$ to obtain $A$. When the cost is $0$, you must end all interactions.

You are allowed to make at most $N+1$ queries.

### Constraints and notes

$1 \leq N \leq 500$ $1 \leq A_i \leq N$ for $1 \leq i \leq N$ It is guaranteed that every integer from $1$ to $\text{max}(A)$ appears at least once in $A$. The query which ends the interaction (i.e. the one with answer $0$) adds up to the total count of queries you've made. 

Interaction4
1 2 3 41 2 3 434 3 2 133 2 1 406
1 1 2 2 3 31 2 3 1 2 333 2 1 1 2 306
1 2 2 3 3 31 2 3 2 3 30
