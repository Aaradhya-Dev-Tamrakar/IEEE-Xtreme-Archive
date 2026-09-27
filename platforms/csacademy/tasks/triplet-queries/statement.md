# Triplet Queries

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/triplet-queries/](https://csacademy.com/contest/archive/task/triplet-queries/)  

---

You should find the values of an array of $N$ distinct integers.

In a query you can choose $3$ different indices. The interactor returns the sum of the minimum and the maximum of these $3$ elements.

### Interaction

First you should read a number $N$.

Then you can start asking the queries. Each query should consist of the character Q followed by three distinct indices between $1$ and $N$.

When you are done, print the character A followed by:

$-1$ if you can't find all the values of the array$N$ numbers representing the array values, otherwise

### Constraints and notes

This task is NOT adaptive$3 \leq N \leq 10^4$ You are allowed to ask at most $min(2*N, N + 50)$ queriesThe elements of the array are integers between $1$ and $10^9$ 

Interaction3Q 1 2 34A -17Q 1 2 311Q 3 4 56Q 2 3 75A 10 2 1 5 3 7 4
