# Six

**Time Limit:** `650 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/six/](https://csacademy.com/contest/archive/task/six/)  

---

Elly studies the properties of some given integer $N$. So far she has discovered that it has no more than six distinct prime divisors. A prime number (or a prime) is a natural number greater than $1$ that has no positive divisors other than $1$ and itself.

Now the girl spends her time in the following way. Starting with an empty list, she writes divisors of $N$, greater than $1$ (some divisors she may repeat several times). When adding a new number to the list, she makes sure that it has common divisors greater than $1$ with at most one of the already written numbers.

For example, if the number $N$ is $12156144$, some of the many possible valid sequences the girl can generate are $(42)$, $(616, 6, 91, 23)$, $(91, 616, 6, 23)$, $(66, 7)$, $(66, 7, 7, 23, 299, 66)$, $(143, 13, 66)$, and $(42, 12156144)$. Examples for invalid sequences would be $(5, 11)$, since $5$ is not a divisor of $12156144$, or $(66, 13, 143)$, since $143$ has common divisors with both $13$ and $66$.

Now Elly is wondering how many different valid sequences of divisors of $N$ exist. We consider two sequences different if they have different length or there is a position, in which they have different numbers.

### Task

Write a program that helps Elly to find the number of valid sequences of divisors of $N$.

### Input

From the first line of the standard input your program has to read one integer $N$.

### Output

On the standard output your program has to print one integer – the number of different sequences of divisors of $N$, which could have been written by Elly. Since this number can be rather large, you are required to print only its remainder when divided by $10^9+7$.

### Constraints

$1 \leq N \leq 10^{15}$ In around 30% of the tests $N$ will have at most $2$ distinct prime divisors.In around 60% of the tests $N$ will have at most $4$ distinct prime divisors.In 100% of the tests $N$ will have at most $6$ distinct prime divisors.

| Input | Output | Explanation |
| --- | --- | --- |
| 6 | 28 | All $28$ valid sequences are: {(2), (2, 2), (2, 2, 3), (2, 2, 3, 3), (2, 3), (2, 3, 2), (2, 3, 2, 3), (2, 3, 3), (2, 3, 3, 2), (2, 6), (2, 6, 3), (3), (3, 2), (3, 2, 2), (3, 2, 2, 3), (3, 2, 3), (3, 2, 3, 2), (3, 3), (3, 3, 2), (3, 3, 2, 2), (3, 6), (3, 6, 2), (6), (6, 2), (6, 2, 3), (6, 3), (6, 3, 2), (6, 6)} |
| 203021 | 33628 |  |
| 60357056536 | 907882 |  |
| 12156144 | 104757552 | The answer is $14104757650$, but since you are required to print it modulo $10^9+7$, the actual result is $14104757650$ % $1000000007$ = $104757552$ |
