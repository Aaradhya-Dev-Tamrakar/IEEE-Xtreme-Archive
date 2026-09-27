# Add and Subtract

**Time Limit:** `2000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/add-and-subtract/](https://csacademy.com/contest/archive/task/add-and-subtract/)  

---

You are given an array $A$ of $N$ integers.

Considering a subsequence of $A$ of length $K$ consisting of the elements having indices $1\leq i_1<i_2<i_3<...<i_K\leq N$, we define the score of the subsequence to be $A_{i_1}-A_{i_2}+A_{i_3}-A_{i_4}...\pm A_{i_K}$.

Find the maximum score of a subsequence of length $K$, for every $1 \leq K \leq N$.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of $A$.

### Standard output

Print $N$ integers on the first line, where the $K^{th}$ value represents the maximum score of a subsequence of length $K$.

### Constraints and notes

$1\leq N \leq 10^5$ $-10^9\leq A_i \leq 10^9$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>6 7 3 8 2 | 8 6 12 10 -4 | $K=1: 8$$K=2: 8 - 2=6$$K=3: 7 - 3 + 8 = 12$$K=4: 7-3+8-2=10$$K=5: 6-7+3-8+2=-4$ |
| 5<br>5 1 6 3 2 | 6 4 10 8 9 | $K=1: 6$$K=2: 5 - 1=4$$K=3: 5 - 1 + 6 = 10$$K=4: 5 - 1 + 6 - 2=8$$K=5: 5 - 1 + 6 - 3 + 2=9$ |
