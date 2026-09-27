# Amusement Park

**Time Limit:** `1500 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/amusement-park/](https://csacademy.com/contest/archive/task/amusement-park/)  

---

You are visiting an amusement park with $A$ attractions. The access to the attractions is done using an electronic card that holds the access tokens. You have bought $T$ tokens.

Normally, every time you visit an attraction the number of tokens decreases by $1$. But today, the card readers are not working properly.

You are given a matrix $P$ of size $T \times A$, where $P_{i,j}$ represents the probability that if you have $i$ tokens, the card reader of the $j^{th}$ attraction will not work. When the card reader doesn't work, you are still granted access to the attraction, but the number of tokens is not decreased.

You start visiting the attractions in order, from $1$ to $A$. If you still have tokens left on your card, you start again from attraction $1$. You stop when there are no tokens left the card. What's the expected number of attractions you'll visit?

### Standard input

The first line contains two integers $T$ and $A$.

Each of the next $T$ lines contains $A$ numbers representing the elements of $P$. Each number is an integer between $0$ and $100$, representing the probabilities as percentages.

### Standard output

Print the answer on the first line.

### Constraints and notes

$1 \leq T, A \leq 1\,000$ $0 \leq P_{i, j} \leq 100$ There will be at least one value strictly less than $100$ on each of the $T$ rows of $P$.Your result will be checked with an absolute or relative error of $10^{-6}$. 

| Input | Output | Explanation |
| --- | --- | --- |
| 3 3<br>0 0 0<br>0 0 0<br>0 0 0 | 3.00000000 | Note that the card reader will always work. This means that you'll ride each ride once. |
| 3 3<br>100 100 0<br>100 0 100<br>0 100 100 | 3.00000000 | You start on ride $1$ with $3$ tokens. That means that there's a $0\%$ chance that the card reader will fail. The same applies for ride $2$ with $2$ tokens and ride $3$ with $1$ token. |
| 2 3<br>30 30 30<br>30 30 30 | 2.85714286 |  |
| 3 3<br>95 90 70<br>70 100 100<br>80 70 100 | 21.11955168 |  |
