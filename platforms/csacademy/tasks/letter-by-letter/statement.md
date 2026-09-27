# Letter by Letter

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/letter-by-letter/](https://csacademy.com/contest/archive/task/letter-by-letter/)  

---

You are given a dictionary with $N$ words of length $K$. One of these words is special. You should find the special word.

Your queries consist of single characters. Initially you try to guess the first letter. When the interactor answers that you found the first letter, your next query will be interpreted as trying to guess the second letter, and so on.

### Interaction

First you should read two integers $N$ and $K$.

Then you should read the $N$ words, each on a different line.

After reading the dictionary you can start asking the queries:

Each query consists of a single character.

After each query you should read the answer: $1$ if you found the current letter of the special word, $0$ otherwise.

Your program should stop after getting $K$ answers of $1$.

### Constraints and notes

This task is adaptive$1 \leq N * K \leq 10^5$The dictionary words consist of lowercase letters of the English alphabetThe interactor tries to force you to ask as many queries as possible. You have to ask the optimal number of queries to pass the tests.

Interaction5 5
money
honey
hodor
moooo
monthm0h1o1n0d1o1r16 4
aabb
abbb
baaa
bbaa
baba
babbb0a1b0a1b1b110 4
aaaa
abaa
abba
baaa
bbaa
bbba
bbca
bbda
caaa
daaab0a0d0c1a1a1a1
