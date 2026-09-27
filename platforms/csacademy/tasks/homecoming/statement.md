# Homecoming

**Time Limit:** `2000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/homecoming/](https://csacademy.com/contest/archive/task/homecoming/)  

---

At a school where $N$ subjects are being taught, academic performance bursary is given based on the subjects you passed. All learning is done through $N$ certified textbooks.

If you pass the $i^{\text{th}} \ (0 \leq i \leq N - 1)$ subject, then you will receive $A_i$ more dollars in your bursary. To pass it, you will need to study from textbooks $i$, $(i + 1) \text{ mod } N$, $(i + 2) \text { mod } N$, $...$, $(i + K - 1) \text{ mod } N$, where $K$ is a constant independent of $i$.

The textbooks are not provided by the school; the $i^{\text{th}} \ (0 \leq i \leq N - 1)$ one costs $B_i$ dollars.

Find the maximum profit that you can make if you study optimally.

### Standard input

The first line contains $T$, the number of test cases.

Each test is described as follows:

The first line contains two integers, $N$ and $K$.The second line contains $N$ integers, $A_0$, $A_1$, $\ldots$, $A_{N-1}$.The third line also contains $N$ integers, $B_0$, $B_1$, $\ldots$, $B_{N-1}$.

### Standard output

For each test print the answer on a separate line.

### Constraints and notes

$1 \leq K \leq N \leq 2 * 10^6$ $\sum N \leq 2 * 10^6$ over all tests in a run $0 \leq A_i$, $B_i \leq 10^9$ You don't have to buy the same textbook multiple times 

| Input | Output |
| --- | --- |
| 1<br>3 2<br>40 80 100<br>140 0 20 | 60 |
