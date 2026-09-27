# Work Time

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/work-time/](https://csacademy.com/contest/archive/task/work-time/)  

---

One of the not-so-great aspects of your workplace is that you often get tedious assignments that make you wonder if your boss just wants to give you something to do (no matter what that is). This time, you were given two sequences $a$ and $b$ of length $N$, and a positive integer $X$. You are allowed to do two types of operations on sequence $a$:

swap $a_i$ with $a_j$;replace $a_i$ with $a_i \oplus X$, where $\oplus$ denotes the xor operation.  

Using these two types of operations any number of times (possibly zero), you are asked to find out if you can make sequence $a$ equal to $b$.

You have to compute the answer for $T$ independent test cases.

  

### Standard input

  

The first line contains an integer $T$, denoting the number of test cases.

Each test case is composed of three lines: on the first line the numbers $N$ and $X$. On the second line $N$ space-separated integers: $a_1$ $a_2$ ... $a_N$, and on the third line $N$ space-separated integers: $b_1$ $b_2$ ... $b_N$.

  

### Standard output

  

The output should consist of $T$ lines. On each line output "Yes" (without quotes) if it is possible to make sequences $a$ and $b$ equal with the given operations, and "No" (without quotes) otherwise.

  

### Constraints and notes

  
$1 \leq T \leq 10$ $1 \leq N \leq 10^5$ $0 \leq a_i, b_i, X \leq 10^6$  

| Input | Output | Explanation |
| --- | --- | --- |
| 2<br>4 1<br>1 2 3 4<br>1 2 2 5<br>4 1<br>1 2 3 4<br>1 1 3 4 | Yes<br>No | In the first test case, we need to apply the second operation to the third and fourth elements.In the second testcase, there is no sequence of operations that can transform sequence $a$ into sequence $b$ |
