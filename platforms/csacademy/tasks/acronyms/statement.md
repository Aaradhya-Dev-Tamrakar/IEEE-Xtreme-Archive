# Acronyms

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/acronyms/](https://csacademy.com/contest/archive/task/acronyms/)  

---

You are given $N$ strings consisting of lowercase letters of the English alphabet. For each of the $N$ strings you should decide whether it can be an acronym for some subset of the other $N-1$ strings.

For a subset of strings, we can choose to order them in any way, and then concatenate the first letter of each of them. For example, $csa$ is an acronym for the subset $\{computer, academy, science\}$, but so is $acs$.

### Standard input

The first line contains a single integer $N$.

Each of the next $N$ lines contains a string.

### Standard output

Print on the first line the number of strings that can be an acronym of some other strings.

### Constraints and notes

$1 \leq N \leq 10^5$ The sum of lengths of the $N$ words is $\leq 10^6$ The strings contain only lowercase letters of the English alphabetThe strings are distinct.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>abc<br>bcad<br>cabd<br>cba<br>dzzz | 2 | cabd is an acronym for {cba, abc,  bcad, dzzz}cba is an acronym for {cabd, bcad, abc}Note that abc is not a valid acronym. |
| 3<br>gnu<br>not<br>unix | 0 | Note that gnu is not an acronym for {gnu, not, unix} |
| 4<br>a<br>aa<br>aaaa<br>aaaaa | 2 |  |
| 2<br>ab<br>ba | 0 |  |
