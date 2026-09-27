# Minimum by Xor

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/minimum-by-xor/](https://csacademy.com/contest/archive/task/minimum-by-xor/)  

---

There is an array of $N$ positive integers, namely $V$. The judge has an integer $R$, initially equal to $0$.

You can perform multiple operations in which you choose a subset of indices $\{i_1, i_2, .., i_K\}$ and the judge will compute $M = \max\{V_{i_1}, V_{i_2}, ..., V_{i_K}\}$ and perform $R := R \bigoplus M$, where $\bigoplus$ is the bitwise-xor operator.

When you are done, $R$ must be equal to $\min\{V_1, V_2, ..., V_N\}$, independent of which values $V$ contained. Use the minimum number of operations to do so.

### Standard input

The first line contains an integer $N$.

### Standard output

The first line contains $T$, the number of operations that you make.

The next $T$ lines as encoded as follows:

The first integer will be $K$, the number of indices in your subsetThe next $K$ integers will be $i_1, i_2, ..., i_k$ 

### Constraints and notes

$1 \leq N \leq 15$ $1 \leq K \leq N$ $1 \leq i_1, i_2, ..., i_K \leq N$ $i_a \neq i_b$ for all $1 \leq a < b \leq K$ The judge is fictive, there will be no interactions whatsoever

| Input | Output | Explanation |
| --- | --- | --- |
| 2 | 3<br>2 1 2<br>1 1<br>1 2 | Let's say $V = [5, 7]$. After the first operation, $R := \max\{7, 5\} = 7$.After the second operation, $R := 7 \bigoplus 5 = 2$.After the third operation, $R := 2 \bigoplus 7 = 5$. In the end, $R := \min\{5, 7\} = 5$. |
