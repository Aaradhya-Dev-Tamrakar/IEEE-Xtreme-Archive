# Marble Weights

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/marble-weights/](https://csacademy.com/contest/archive/task/marble-weights/)  

---

There are $N$ marbles having integer weights. You have a weighing scale, but you are only allowed to weigh at least $2$ marbles at the same time. Find the weight of each marble by using the scale at most $N$ times.

### Interaction

First you should read a single integer $N$.

Then you can start asking the queries. If you want to weigh $K$ marbles, you should print the letter Q, followed by $K$ and another $K$ distinct values between $1$ and $N$ (the indices of the marbles).

After each query you should read the answer given by the scale.

When you are done, print the letter A followed by $N$ integers representing the weights of the marbles.

### Constraints and notes

This task is NOT adaptive$3 \leq N \leq 1000$The weights of the marbles are integers between $1$ and $1000$

Interaction3Q 2 1 23Q 2 1 34Q 2 2 35A 1 2 3
