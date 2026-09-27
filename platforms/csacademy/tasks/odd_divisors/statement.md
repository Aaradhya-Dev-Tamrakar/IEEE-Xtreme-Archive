# Odd Divisors

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/odd_divisors/](https://csacademy.com/contest/archive/task/odd_divisors/)  

---

You are given an interval of integers $[A, B]$. For each number in this interval compute its greatest odd divisor. Output the sum of these divisors.

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consists of one line containing two integer values $A$ and $B$.

### Standard output

The output should contain the answer for each test case on a different line.

Each answer consists of a single integer value.

### Constraints and notes

$1 \leq T \leq 10^5$$1 \leq A \leq B \leq 10^9$

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>1 3<br>1 4<br>3 9 | 5<br>6<br>29 | $1 + 1 + 3 = 5$$1 + 1 + 3 + 1 = 6$$3 + 1 + 5 + 3 + 7 + 1 + 9 = 29$ |
| 3<br>14 67<br>62 129<br>75 168 | 1468<br>4320<br>7576 |  |
