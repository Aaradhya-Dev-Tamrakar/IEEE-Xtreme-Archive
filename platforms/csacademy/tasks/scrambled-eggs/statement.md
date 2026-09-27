# Scrambled Eggs

**Time Limit:** `2000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/scrambled-eggs/](https://csacademy.com/contest/archive/task/scrambled-eggs/)  

---

Ajerora the Thief lives in the Math City and he is a big fan of Number Theory. He just broke the Number Bank, and there he found a brand new sequence $a$ of $n$ positive integers. Unfortunately, Ajerora can only steal $k$ numbers from $a$, because of the limited capacity of its knapsack. Let them be $b_1, b_2, \ldots, b_k$.

After he gets home, Ajerora will check if $b$ is a good sequence. For that, he will choose for each $b_i$ a prime factor of it, $c_i$. He wants to do that in such a way that the most frequent element in $c$ occurs exactly $x$ times. Your task is to determine if Ajerora can choose a good sequence of $k$ elements from $a$.

### Standard input

The first line contains the numbers $n$, $k$, and $x$.

The second line contains $n$ positive integers, representing the sequence $a$.

### Standard output

If there is no solution, you must print IMPOSSIBLE. Otherwise, the output will contain $n$ numbers, describing a valid solution to the problem. Namely, if the $i$-th number is among the $k$ numbers chosen by Ajerora, print the chosen prime factor for the particular number. Otherwise, print $-1$.

If there are multiple solutions, you can output any of them.

### Constraints and notes

  
$1 \leq k \leq n \leq 100\,000$ $1 \leq a_i \leq 10^7$, for all $1 \leq i \leq n$ $1 \leq x \leq \min (k, 5)$   

| Input | Output |
| --- | --- |
| 5 3 2<br>2 3 5 6 7 | 2 -1 -1 2 7 |
