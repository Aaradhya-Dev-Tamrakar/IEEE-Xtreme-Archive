# Crypto

**Time Limit:** `300 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/crypto/](https://csacademy.com/contest/archive/task/crypto/)  

---

Pesho is crypting a sequence of $N$ numbers where each integer from $1$ to $N$ appears exactly once. He is using the following algorithm:

Replace each initial number $X$ with the $X^{th}$ prime number.Choose a random positive integer $K$, not greater than $N$.Consider all subsequences with consecutive elements. For each subsequence with at least $K$ elements write down the product of the smallest $K$ numbers.Let $P$ be the number of unique products written in the previous step.The code is “$N K P$”.

Let us see how Pesho should crypt the sequence $\{4, 1, 3, 2\}$:

The first $4$ prime numbers are $2$, $3$, $5$ and $7$. In the initial sequence he replaces$4$ with the fourth prime number which is $7$;$1$ with the first prime number which is $2$;$3$ with the third prime number which is $5$;$2$ with the second prime number which is $3$.

Pesho obtains the new sequence $\{7, 2, 5, 3\}$.

He chooses a random number $K$. Say $K=2$.All contiguous subsequences are:  $\{7\}$, $\{2\}$, $\{5\}$, $\{3\}$, $\{7, 2\}$, $\{2, 5\}$, $\{5, 3\}$, $\{7, 2, 5\}$, $\{2, 5, 3\}$, $\{7, 2, 5 ,3\}$

Pesho removes all subsequences with less than $K=2$ elements and for each of the rest he computes the product of the smallest $K=2$ elements.

$\{7, 2\}\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 2 * 7 = 14$ $\{2, 5\}\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 2 * 5 = 10$ $\{5, 3\}\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ 3 * 5 = 15$ $\{7, 2, 5\}	\ \ \ \ \ \ \ \ \ \ \ \ \ 2 * 5 = 10$ $\{2, 5, 3\}	\ \ \ \ \ \ \ \ \ \ \ \ \ 2 * 3 = 6$ $\{7, 2, 5 ,3\}\ \ \ \ \ \ \ \ \ 2 * 3 = 6$ 

He writes the numbers $\{14, 10, 15, 10, 6, 6\}$

There are four unique numbers $\{6, 10, 14, 15\}$, thus $P = 4$.The code is “$4\ 2\ 4$”.

Pesho quickly figured out that the algorithm is much better than he expected. He cannot always decrypt the code unambiguously.

Write a program which given a code calculates the number of possible initial sequences. Find the answer modulo $10^9+7$.

### Standard input

The first line contains the positive integers $N$, $K$ and $P$.

### Standard output

Print the number of possible initial sequences with code “$N K P$”. Print the answer moduo $10^9+7$.

### Constraints and notes

$1 \le K \le N \le 400$ $1 \le P \le 10^9$ In 20% of the test cases $N \le 10$ In 60% of the test cases $N*K \le 30\,000$

| Input | Output | Explanation |
| --- | --- | --- |
| 3 2 3 | 2 | The sequences $\{1, 3, 2\}$ and $\{2, 3, 1\}$ will be crypted as “$3\ 2\ 3$”. |
| 4 2 4 | 12 | The sequences are $\{1, 2, 4, 3\}$, $\{1, 3, 2, 4\}$, $\{1, 4, 2, 3\}$, $\{2, 1, 4, 3\}$, $\{2, 3, 1, 4\}$, $\{2, 4, 1, 3\}$, $\{3, 1, 4, 2\}$, $\{3, 2, 4, 1\}$, $\{3, 4, 1, 2\}$, $\{3, 4, 2, 1\}$, $\{4, 1, 3, 2\}$, $\{4, 2, 3, 1\}$. |
