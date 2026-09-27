# Dacian Array

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/dacian-array/](https://csacademy.com/contest/archive/task/dacian-array/)  

---

In the time of the Free Dacians it was said that a sequence of numbers $A$ was $K$-free if the absolute difference between any $2$ consecutive numbers in the sequence was not divisible by $K$.

The leader of the Free Dacians, Decebal, will give you a sequence $A$ and a number $K$. In order for the Dacian's to win the war against the army led by Traian, you must compute for Decebal in how many distinct ways we can rearrange the elements of $A$ such that the resulting sequence is $K$-free.

If you managed to find the correct answer the war will be won, but since this number could be quite large you are required instead to output its remainder modulo $10^9+7$.

### Standard input

The first line will contain two space separated integers $N$ and $K$.

The second line will contain $N$ numbers describing the sequence $A$.

### Standard output

The first line should contain the output to Decebal's question.

### Constraints and notes

$2 \leq K \leq 1\ 000\ 000$ $0\leq A[I] \leq 1\ 000\ 000\ 000$

#PointsRestrictions16$N \leq 10$220$N \leq 50$325$N \leq 200$449$N \leq 2500$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 5<br>1 1 6 2 3 | 6 | Long live Free Dacia!!! |
