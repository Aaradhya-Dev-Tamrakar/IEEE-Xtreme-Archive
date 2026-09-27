# Swap Permutation

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/swap_permutation/](https://csacademy.com/contest/archive/task/swap_permutation/)  

---

You are given the identity permutation of size $N$ (an array containing all the integers between $1$ and $N$ in increasing order).

You are also given a sequence of $M$ swaps that can be applied on the array, in order. Each swap is defined by a pair of indices.

You have to remove exactly one pair from the sequence, such that by applying the remaining $M-1$ swaps, the element $1$ ends up at position $K$.

### Standard input

The first line contains three integers $N$, $M$ and $K$.

Each one of the next $M$ lines contains two integer values, representing the swaps.

### Standard output

The output should contain a single value between $1$ and $M$, representing the index of the swap that should be removed. If the solution is not unique print the smallest index. It is guaranteed that there will always exist at least one solution.

### Constraints and notes

$2 \leq N \leq 10^5$$1 \leq M \leq 10^5$$1 \leq K \leq N$All the indices in the swaps will be distinct numbers between $1$ and $N$

| Input | Output |
| --- | --- |
| 20 9 7<br>1 4<br>4 2<br>2 3<br>2 8<br>3 8<br>3 7<br>7 1<br>1 10<br>10 7 | 3 |
