# Anagrams

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/anagrams/](https://csacademy.com/contest/archive/task/anagrams/)  

---

You are given a  list of $N$ words (strings containing only lower case letters of the English alphabet). We consider two words to be equivalent if they contain the same letters, i.e. we can rearrange the letters of one word in order to obtain the other word.

Compute the size of the largest subset of equivalent words.

### Desired solution

You should assume the input is quite large (there are about $10^5$ letters in total).

### Standard input

The first line contains a single integer value $N$.

Each of the following $N$ lines contains a single string, representing one of the words.

### Standard output

The output should contain a single integer representing the size of the largest subset of equivalent words.

### Constraints and notes

$1 \leq N \leq 10^5$ The sum of lengths of all the words is a number between $1$ and $10^5$.The strings contain only lower case letters of the English alphabet.

| Input | Output | Explanation |
| --- | --- | --- |
| 6<br>cats<br>caller<br>dogs<br>cellar<br>parrots<br>recall | 3 | caller, cellar and recall are (the only) equivalent words. |
| 8<br>disease<br>burned<br>viewer<br>praised<br>despair<br>burden<br>diapers<br>review | 3 | praised, despair and diapers form the largest set of equivalent words. |
