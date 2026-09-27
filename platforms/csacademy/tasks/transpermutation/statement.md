# Transpermutation

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/transpermutation/](https://csacademy.com/contest/archive/task/transpermutation/)  

---

We want to transform permutation $P$ to $S$ with length $N$ and make a sequence of integers representing the tranformations $A_1, A_2,...,A_l$ .

The $i$-th transformation is shown as $1 \le A_i \le N-K+1$ and it will change $P_{A_i},...,P_{A_i+K-1}$ to $P_{A_i+K-1},P_{A_i},P_{A_i+1},...,P_{A_i+K-2}$.

Determine if we can transform them and if we can, output any sequence that does it.

### Standard input

The first line contains a two numbers $N$ and $K$.

The second line contains a sequence of $n$ numbers from $1$ to $N$ representing permutation $P$. Each number from $1$ to $N$ occurs exactly once in this line.

The thrid line contains a sequence of $N$ numbers from $1$ to $N$ representing permutation $S$. Each number from $1$ to $N$ occurs exactly once in this line.

### Standard output

If the transformation cant be done, output -1

Otherwise print $L$, the number of transformations and on the next line $L$ numbers, with the $i$-th number being the type of the $i$-th transformation (they are numbered from $1$ to $N-K+1$). If there are multiple solutions print any of them.

### Constraints and notes

 $2 \le K \le N \le 60$ $0 \le L \le 6 \cdot 10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 4<br>3 5 2 1 4<br>2 3 4 5 1 | 2<br>2 1 | The transformation: $[3 \ 5 \ 2 \ 1\ 4]$ > $[ 3\ 4\ 5\ 2\ 1]$ > $[2\ 3\ 4\ 5\ 1]$ |
| 6 4<br>2 5 6 3 1 4<br>3 2 5 6 1 4 | 1<br>1 | The transformation: $[2 \ 5 \ 6 \ 3 \ 1\  4]$ > $[ 3 \ 2 \ 5  \ 6 \ 1 \ 4]$ |
