# Palindrome Centers

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/palindrome-centers/](https://csacademy.com/contest/archive/task/palindrome-centers/)  

---

For a string $S$ of length $N$ you are given the length of the longest palindrome that ends at each index $i$ ($1 \leq i \leq N$). Find the length of the longest palindrome centered at each index $i$ ($1 \leq i \leq N$).

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the lengths of the longest palindromes ending at each index $i$.

### Standard output

On the first line print $N$ values representing the lengths of the longest palindromes centered at each index $i$.

### Constraints and notes

$1 \leq N \leq 10^5$ The size of the alphabet is $N$ 

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>1 2 1 3 5 | 1 1 5 1 1 | One string could beaabaa |
| 7<br>1 1 3 3 5 5 7 | 1 3 5 7 5 3 1 | One string could beabababa |
| 6<br>1 1 1 2 4 6 | 1 1 1 1 1 1 | One string could beabccba |
| 8<br>1 1 1 1 3 2 4 6 | 1 1 1 3 1 1 3 1 | One string could beabcaccac |
| 6<br>1 1 2 4 2 3 | 1 1 1 1 3 1 | One string could bebaabbb |
