# Previous Divisors

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/previous-divisors/](https://csacademy.com/contest/archive/task/previous-divisors/)  

---

You are given an array of $N$ integers. For each element $x$ you should count the number of elements $y$ such that:

$y$ occurs in the array before $x$$y$ is a divisor of $x$.

We say that an integer $y$ is a divisor of another integer $x$ if we can find another integer $z$ such that $x = y * z$.

### Interaction

First you should read a single integer $N$.

Then you should read the elements of the array one by one. After each element read output the number of previously read elements that are divisors of the current element.

Warning: In order to read the next element of the array you are required to print your answer first.

Warning2: Don't forget to add a newline and then flush the output.

### Constraints and notes

This task is NOT adaptive$1 \leq N \leq 1000$The elements of the array are integers between $0$ and $10^9$.

Interaction6
1021314251635
10214283434
40201043
