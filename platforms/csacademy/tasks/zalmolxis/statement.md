# Zalmolxis

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/zalmolxis/](https://csacademy.com/contest/archive/task/zalmolxis/)  

---

Tanaka loves beautiful sequences. A sequence is considered beautiful if it is generated through the following procedure:

Tanaka begins with the number $2^{30}$.Tanaka will take an arbitrary even integer $x$ in the sequence and replace it with two copies of $\frac{x}{2}$.  Tanaka will repeat step $2$ as many times as he wants.

Tanaka has built one such sequence that is $N + K$ elements long. Unfortunately, his enemies, have stolen $K$ of the values in the sequence!

Being given $N$, $K$, and the remaining N integers in the sequence, help Tanaka by inserting $K$ values into the sequence such that the result is beautiful.

### Standard Input

On the first line of the input there will be the integers N and K, separated by a space.

On the second line of the input there will be the N integers of Tanaka’s sequence and since all numbers in this sequence are powers of two, we will represent the value $2^{\text{x}}$ by $\text{x}$.

### Standard Output

On the first and only line there will be a beautiful sequence of $N + K$ integers, of which the given sequence is a subsequence ; represent the value $2^\text{x}$ by $\text{x}$ as in the input.

### Constraints and notes

$1 \leq N < 10^6$ $1 \leq K \leq 10^6 - N$ 

| Input | Output |
| --- | --- |
| 9 3<br>27 27 27 27 27 27 26 24 24 | 27 27 27 27 27 27 26 24 24 24 24 27 |
| 6 6<br>28 26 25 25 26 26 | 28 26 25 25 26 26 24 24 25 26 27 28 |
| 11 1<br>24 23 23 24 26 26 25 25 28 28 28 | 24 23 23 24 24 26 26 25 25 28 28 28 |
| 1 11<br>26 | 26 19 19 20 21 22 23 24 25 27 28 29 |
