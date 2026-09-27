# Mathison and the divisors 2

**Time Limit:** `3000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/matdiv2/](https://csacademy.com/contest/archive/task/matdiv2/)  

---

Mathison has become tired of playing with circuits or trains and has decided to solve a maths problem.

You are given a tree with $N$ nodes. Each node contains a key.

Let's define:

$D(n) =$ set of divisors of integer $n$ $Count(D(n)) =$ number of divisors of integer $n$ $Sum(D(n)) =$ sum of divisors of integer $n$ $Prod(u, v) =$ the product of all keys on the unique path between nodes $u$ and $v$, including $u$ and $v$ $Q1(u, v) = Count(D(Prod(u, v)))$ modulo $(10^9 + 9)$ $Q2(u, v) = Sum(D(Prod(u, v)))$ modulo $(10^9 + 9)$ 

For $M$ given pairs of nodes $(u, v)$ you are to find $Q1(u, v)$ and $Q2(u, v)$.

### Standard input

The first line will contain one integer $N$, the number of nodes in the tree.

The second line will contain $N$ space-separated integers, the keys associated with the nodes.

Each of the next $N - 1$ lines will contain a pair of integers $s$ and $t$, denoting an edge between $s$ and $t$. They form a tree.

The next line will contain one integer $M$, the number of queries you need to answer.

Each of the next $M$ lines will contain a pair of integers $u$ and $v$, the parameters of the queries you need to compute.

### Standard output

The output file will contain $M$ lines, each containing two integers representing, in order, $Q1(u, v)$ and $Q2(u, v)$ for every pair $(u, v)$ of nodes given in the input.

### Constraints and notes

$1 \leq N \leq 4 \cdot 10^4$ $1 \leq M \leq 6 \cdot 10^4$ All keys will be integers between $1$ and $10^6$ $1 \leq u, v \leq N$ $1 \leq s, t \leq N$, $s \neq t$ 

### Subtasks

Test cases will be scored individually.

| Subtask | Percentage of test cases | Additional input constraints |
| --- | --- | --- |
| 1 | $20\%$ | $N \leq 100$ |
| 2 | $30\%$ | all keys $\leq 100$ |
| 3 | $50\%$ | none |

For each test you may receive partial scoring.

Value of the test awardedCondition to award the points$70\%$$Q1(u, v)$ must be computed correctly and a wrong value must be supplied for $Q2(u, v)$ for all $M$ pairs of $(u, v)$$30\%$$Q2(u, v)$ must be computed correctly and a wrong value must be supplied for $Q1(u, v)$ for all $M$ pairs of $(u, v)$$100\%$$Q1(u, v)$ and $Q2(u, v)$ must be computed correctly for all $M$ pairs of $(u, v)$

### Examples

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>3 4 5 1 5<br>4 2<br>1 3<br>4 5<br>2 1<br>4<br>4 4<br>2 2<br>1 5<br>3 4 | 1 1<br>3 7<br>12 168<br>12 168 | $Prod(4, 4) = 1$, $D(1) = \{1\}$, $Count(D(1)) = 1$, $Sum(D(1)) = 1$ $Prod(2, 2) = 4$, $D(4) = \{1, 2, 4\}$, $Count(D(4)) = 3$, $Sum(D(4)) = 7$ $Prod(1, 5) = 3 \cdot 4 \cdot 1 \cdot 5 = 60$, $D(60) = \{1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60\}$, $Count(D(60)) = 12$, $Sum(D(60)) = 168$ $Prod(3, 4) = 5 \cdot 3 \cdot 4 \cdot 1 = 60$, $D(60) = \{1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60\}$, $Count(D(60)) = 12$, $Sum(D(60)) = 168$ |
