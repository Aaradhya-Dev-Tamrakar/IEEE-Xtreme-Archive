# Min Swaps

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/min-swaps/](https://csacademy.com/contest/archive/task/min-swaps/)  

---

You are given a permutation $P$ of $N$ integers, $N$ is always even. We define the cost of a permutation as $\sum_{i=1}^{N-1}|P_i - P_{i+1}|$.

You are allowed to perform any number of operations of the type: take two elements of $P$ and swap them. You should find the minimum number of swaps you need in order to achieve the maximum cost of $P$.

### Standard input

The first line contains a single integer $T$ representing the number of tests that follow.

Each test consists of $2$ lines:

The first line contains a single integer $N$.The second line contains $N$ integers representing the elements of $P$.

### Standard output

Print the answer for each test on a distinct line.

### Constraints and notes

$1 \leq T \leq 10^5$ $2 \leq N \leq 10^5$, $N$ is evenThe sum of $N$ for all the $T$ tests is $\leq 10^5$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>4<br>1 2 3 4<br>4<br>3 4 2 1<br>6<br>1 5 3 4 6 2 | 3<br>2<br>3 | First test: $3$ moves, achieving a cost of $7$$1\ 2\ 3\ 4$$\underline{3}\ 2\ \underline{1}\ 4$$\underline{4}\ 2\ 1\ \underline{3}$$\underline{2}\ \underline{4}\ 1\ 3$Second test: $2$ moves, achieving a cost of $7$$3\ 4\ 2\ 1$$\underline{2}\ 4\ \underline{3}\ 1$$2\ 4\ \underline{1}\ \underline{3}$Third test: $3$ moves, achieving a cost of $17$$1\ 5\ 3\ 4\ 6\ 2$$\underline{3}\ 5\ \underline{1}\ 4\ 6\ 2$$3\ 5\ 1\ \underline{6}\ \underline{4}\ 2$$3\ 5\ 1\ 6\ \underline{2}\ \underline{4}$ |
| 1<br>6<br>1 3 2 4 5 6 | 3 |  |
