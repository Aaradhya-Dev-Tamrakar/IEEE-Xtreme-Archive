# One Letter

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/one_letter/](https://csacademy.com/contest/archive/task/one_letter/)  

---

You are given a list of $N$ words. From each word you should keep only one letter and discard all the others. Then you should permute the $N$ chosen letters and build a single word by concatenating them. Find the lexicographically smallest word you can obtain.

### Standard input

The first line contains a single integer value $N$.

Each of the following $N$ lines contains a single string, representing one of the words.

### Standard output

The output should contain one string of length $N$.

### Constraints and notes

$1 \leq N \leq 10^5$The sum of lengths of the strings is ≤ $10^5$The strings will contain only lower case letters of the English alphabet.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>cross<br>stop<br>arm | aco | We keep letter c from cross, letter o from stop and letter a from arm. Using these letters we can obtain aco. |
| 9<br>inside<br>socks<br>after<br>wait<br>element<br>start<br>olives<br>mushroom<br>envelope | aaacdeeeh |  |
