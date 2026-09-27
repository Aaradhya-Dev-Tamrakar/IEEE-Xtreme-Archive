# Voting

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/voting/](https://csacademy.com/contest/archive/task/voting/)  

---

The performance of a singer in a singing contest has just ended. Soon the voting process of the judges will start.

There are $N$ judges in total. Each of them has its own subjective assessment of the performance, a number from $0$ to $N$. Judges vote consistently, and each of them can award $0$ or $1$ points.

They vote one after the other, as follows: let $k$ be the number of judges that voted before the current judge, and let $c$ be the number of points already awarded by them. Then the current judge believes that the expected final score is $\large\frac{c * N}{k}$. If the judge's subjective score is strictly higher than this expected score, he awards 1 point, otherwise 0. The first judge always gives 0 points.

You are the chief judge. You don't vote, but you determine the order in which the other judges vote. You also have your own assessment $X$ of the performance. Determine the order in which the judges vote such that the result will be as close as possible (in absolute value) to your assessment.

### Standard input

The first line contains two integers $N$ and $X$.

The second line contains $N$ integers representing the assessments of the other judges.

### Standard output

On the first line, print $N$ integers representing the assessments of the judges in an optimal order. If the answer is not unique, you can output any of them.

### Constraints and notes

$1 \le N \leq 10^5$ $X$ and the other judges' assessments are integers between $0$ and $N$

| Input | Output |
| --- | --- |
| 3 1<br>0 1 2 | 2 1 0 |
| 3 3<br>0 1 2 | 0 1 2 |
| 5 0<br>4 3 2 1 0 | 4 3 2 1 0 |
