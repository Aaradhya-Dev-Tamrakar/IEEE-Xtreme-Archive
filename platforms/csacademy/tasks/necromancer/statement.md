# Necromancer

**Time Limit:** `500 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/necromancer/](https://csacademy.com/contest/archive/task/necromancer/)  

---

Elections have taken place in city X, and $K$ people ran for office. Each of the $N$ citizens of city X participated in the vote and wrote a permutation $p_1, p_2, ..., p_K$, representing his preferred order of candidates. The winner of the elections is the candidate that is first on most of the $N$ permutations.

The necromancer wishes that Charles, candidate $1$, wins the elections. To achieve this, he managed to find out, for each citizen $i$, an array $A_i$ which is a subsequence of the permutation $i$ voted for. The necromancer can then create, using unknown powers, additional votes for candidate $1$.

Knowing for each of the $N$ permutations a subarray $A_i$, find the minimum number of additional votes the necromancer should create, such that there exists at least one scenario where candidate $1$ wins (helped, of course, by the additional votes).  A set of votes is valid if for each citizen $i$ there is at least one permutation that contains $A_i$ as a subsequence.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the next $N$ lines contains the subsequences of the $N$ permutations. The first number on a line is $L_i$, representing the length of the subsequence, followed by the $L_i$ elements of the subsequence.

### Standard output

Print a single integer representing the minimum number of additional votes such that there is at least one valid set of votes where candidate $1$ wins.

### Constraints and notes

$1 \leq N, K \leq 1000$ Candidate $1$ needs a strictly greater number of votes to win.

| Input | Output | Explanation |
| --- | --- | --- |
| 3 4<br>2 3 1<br>3 2 1 3<br>4 1 2 3 4 | 1 | We can choose the permutations:3 2 1 42 1 3 41 2 3 4In this situation, candidates $1$, $2$ and $3$ each have $1$ vote. The necromancer needs a single additional vote for $1$ to have $2$ votes and win.Notice we could of chosen (inconveniently) the permutations:2 3 4 12 1 3 41 2 3 4In this case, candidate $2$ would have $2$ votes and candidate $1$ only $1$. The necromancer would need $2$ additional votes. |
