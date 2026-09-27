# Domino Train

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/domino-train/](https://csacademy.com/contest/archive/task/domino-train/)  

---

There are $N$ dominos on the table. Every domino $D_i$ contains two numbers $(a_i, b_i)$. Initially you may flip any domino $D_i$ and consider it as $(b_i, a_i)$.

A domino train is an ordered set of dominos. Every domino $i$ may only be a part of a single domino train. Initially there are $N$ domino trains, the $i^{\text{th}}$ one containing $\{i\}$.

You are given $N - 1$ requests: take the domino train which contains the $v^{\text{th}}$ domino and join it with any other domino train from the table. To encode such operations, suppose $v$ belongs in the domino train $A := \{a_1, a_2, ..., v, ..., a_k\}$ and we want to join it with $B := \{b_1, b_2, ..., b_m\}$, then:

#OperationOutcomeEncoding1Places $B$ after $A$$\{a_1, a_2, ..., v, ..., a_k, b_1, b_2, ..., b_m\}$$a_1 \ \ b_1$2Places $A$ after $B$$\{b_1, b_2, ..., b_m, a_1, a_2, ..., v, ..., a_k\}$$b_1 \ \ a_1$

In the end there will only be a single domino train on the table. Suppose it is $\{i_1, i_2, i_3, ..., i_N\}$.

A match is a position $1 \leq j < N$, for which the second value from $D_{i_j}$ is equal to the first value from $D_{i_{j+1}}$. Note that the initial flips may affect the number of matches in the end.

Perform the joins in such a way that you maximize the number of matches.

### Standard input

The first line contains $N$.

The next $N$ lines contain two integers $a_i$ and $b_i$.

The next line contains $N - 1$ integers, representing the requests.

### Standard output

The first $N - 1$ lines should contain the operations you chose.

On the $N^{\text{th}}$ line, print $N$ binary values separated by spaces: the $i^{\text{th}}$ one is $0$ if you consider $D_i$ as $(a_i, b_i)$ or $1$ if you consider it as $(b_i, a_i)$.

### Constraints and notes

$1 \leq N \leq 10^5$ $1 \leq a_i, b_i \leq N$ $1 \leq v \leq N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 7<br>3 2<br>3 4<br>4 4<br>3 3<br>4 5<br>1 3<br>1 2<br>1 4 4 2 5 6 | 2 1<br>6 4<br>7 6<br>3 2<br>5 3<br>5 7<br>0 1 0 0 1 0 1 | Initially we have the following domino trains: $\{1\}, \{2\}, .., \{7\}$. Operations for every request are as follows: We need will erase $\{1\}$ and $\{2\}$ and insert $\{2, 1\}$.We need will erase $\{6\}$ and $\{4\}$ and insert $\{6, 4\}$.We need will erase $\{7\}$ and $\{6, 4\}$ and insert $\{7, 6, 4\}$. Notice how we've printed $6$ instead of $4$, because $6$ is the first element in $4^{\text{th}}$ train.We will erase $\{3\}$ and $\{2, 1\}$ and insert $\{3, 2, 1\}$. We will erase $\{5\}$ and $\{3, 2, 1\}$ and insert $\{5, 3, 2, 1\}$.We will erase $\{5, 3, 2, 1\}$ and $\{7, 6, 4\}$ and insert $\{5, 3, 2, 1, 7, 6, 4\}$. The final set, after replacing the indices by dominos and applying the flips: $\{(5, 4), (4, 4), (4, 3), (3, 2), (2, 1), (1, 3), (3, 3)\}$. The number of matches is $6$. Notice that $5$ is flipped, so $D_5$ is $(5, 4)$ and not $(4, 5)$ as it was initially. |
