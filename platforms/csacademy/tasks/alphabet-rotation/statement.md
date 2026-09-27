# Alphabet Rotation

**Time Limit:** `1000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/alphabet-rotation/](https://csacademy.com/contest/archive/task/alphabet-rotation/)  

---

You are given an array of $N$ words. Each of them contains only lower case letters of the English alphabet. Two words $A$ and $B$ are considered equivalent if $A$ can be changed into $B$ by applying a circular permutation over the alphabet.

Applying a circular permutation means choosing a value $K$ ($0 \leq K \leq 25$) and replacing every character $\alpha$ with the $(\alpha + K) \% 26$th character (0-indexed). For example if $K = 10$ we should replace $a$ with $k$ and $t$ with $d$.

You should find out for every word if there is at least one other word in the set equivalent to it.

### Standard input

The first line contains a single integer $N$.

Each of the following $N$ lines contains a single string, representing one of the words.

### Standard output

The output should consist of $N$ lines. Line $i$ should contain a single value: $1$ if for $i$th word in the input exists at least another equivalent word, otherwise the line should contain $0$.

### Constraints and notes

$1 \leq N \leq 10^5$The sum of lengths of the strings is ≤ $10^5$The strings will contain only lower case letters of the English alphabet.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>a<br>ab<br>cd | 0<br>1<br>1 | It's possible to rotate $(ab)$ into $(cd)$ using a circular permutation with $K=2$. In this way $a$ becomes $c$ and $b$ becomes $d$.It's also possible to rotate $(cd)$ into $(ab)$ using a circular permutation with $K=24$. |
| 4<br>bbc<br>xyz<br>abc<br>bbc | 1<br>1<br>1<br>1 | $(bbc)$ is already equal to $(bbc)$ and we can rotate $(xyz)$ with $K=3$ obtaining $(abc)$.The letter $x$ has index $23$ and $(x + 3) \% 26 = (23 + 3) \% 26 = 0 = a$. |
| 5<br>a<br>b<br>ab<br>ba<br>bc | 1<br>1<br>1<br>0<br>1 | $(b)$ can be obtained from $(a)$ and $(bc)$ from $(ab)$. There's no way to obtain $(ba)$ from the other words. |
