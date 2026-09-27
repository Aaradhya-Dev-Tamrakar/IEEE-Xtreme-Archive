# Guess the Number

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/guess-the-number/](https://csacademy.com/contest/archive/task/guess-the-number/)  

---

You should guess a number having exactly $N$ digits. The number has an interesting property: its digits are non-increasing (from most significant to least significant).

In a query you can choose any number with $N$ digits (no leading zeros allowed). The interactor tells you the number of identical digits of your number and the one you have to guess.

Two digits are identical if they have the same index and the same value.

### Interaction

First you should read the number $N$.

Then you can start asking your queries. Each query should consist of the character Q followed be a number of $N$ digits.

After each query read the answer given by the interactor.

When you are done, print the character A followed by the answer.

### Constraints and notes

This task is NOT adaptive$1 \leq N \leq 8$You are allowed to ask at most $10$ queries

Interaction1Q 10Q 20Q 30Q 41Q 50Q 60Q 70Q 80Q 90A 42Q 111Q 221Q 330Q 440Q 550Q 660Q 770Q 880Q 990A 21
