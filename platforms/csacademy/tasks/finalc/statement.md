# Final C

**Time Limit:** `1000 ms`  
**Memory Limit:** `256 MB`  
**Source:** [https://csacademy.com/contest/archive/task/finalc/](https://csacademy.com/contest/archive/task/finalc/)  

---

### Statement

Alex loves playing the guitar, but unfortunately his last one broke from an unknown event. Thus, he wants to buy an outstanding guitar, that no one has ever seen on this planet.

First of all, he would like a guitar that has at most $N$ strings. Now, he needs to create a combination of strings that would please him. Strings are very different and can make lots and lots of distinct sounds. Each string can produce exactly one sound. We'll encode, for simplicity, each sound with an integer on $32$ bits. He's got at this disposal an infinite amount of strings of each of the $2^{32}$ possible sounds.

Alex needs to choose a combination of strings such that any $2$ adjacent strings make harmonic sounds. Two sounds are considered harmonic if the bitwise AND of their corresponding integers is equal to $0$.

Help Alex compute the number of combinations of strings that would please him. Since this number may be huge, you are asked to output it modulo $10^9 + 7$.

### Standard input

There is a single line with a single positive integer $N$, denoting the maximum number of strings Alex would like to have.

### Standard output

Output one number, the number of combinations of guitar strings that would please Alex, modulo $10^9 + 7$.

### Constraints and notes

$1 \le N \le 10^5$ 

| Input | Output |
| --- | --- |
| 2 | 470847969 |
