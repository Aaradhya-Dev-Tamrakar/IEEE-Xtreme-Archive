# Word Permutation

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/word_permutation/](https://csacademy.com/contest/archive/task/word_permutation/)  

---

Alex has a list of $N$ distinct words and a permutation $\sigma$ of size $N$. Initially, the words in the list are sorted lexicographically. Alex changes the order of the words according to the permutation: the new position of the $i$th word is $\sigma(i)$. You are given the permuted list of words and are asked to compute the permutation $\sigma$.

### Standard input

The first line contains a single integer value $N$.

Each of the following $N$ lines contains a single string, representing one of the words.

### Standard output

The output should contain $N$ values representing the permutation $\sigma$.

### Constraints and notes

$1 \leq N \leq 10^5$The sum of lengths of the strings is ≤ $10^5$The strings will contain only lower case letters of the English alphabet.

| Input | Output |
| --- | --- |
| 3<br>xyz<br>abc<br>foo | 2 3 1 |
| 6<br>cloud<br>algorithms<br>complexity<br>development<br>python<br>java | 2 1 3 4 6 5 |
