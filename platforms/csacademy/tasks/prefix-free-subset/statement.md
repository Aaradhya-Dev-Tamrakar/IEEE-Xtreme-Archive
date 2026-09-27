# Prefix Free Subset

**Time Limit:** `1000 ms`  
**Memory Limit:** `1 GB`  
**Source:** [https://csacademy.com/contest/archive/task/prefix-free-subset/](https://csacademy.com/contest/archive/task/prefix-free-subset/)  

---

You are given a list of $N$ words. Find a subset of $K$ words such that:

There are no two strings in the subset such that one of them is a prefix of the other one.The length of longest word is minimum.

### Standard input

The first line contains two integers $N$ and $K$.

Each of the following $N$ lines contains one of the words in the list.

### Standard output

If there is no solution print $-1$ on the first line.

Otherwise, print the length of the longest word in the subset.

### Constraints and notes

$1 \leq K \leq N \leq 10^6$ The sum of lengths of all the words is $\leq 10^6$ The words contain only lowercase letters of the English alphabet

| Input | Output |
| --- | --- |
| 4 2<br>foobar<br>foo<br>tall<br>taller | 4 |
| 4 3<br>abcd<br>ab<br>a<br>zxy | -1 |
| 7 4<br>a<br>caaaaaaa<br>baaaaa<br>baaabaaa<br>baaab<br>baaabaa<br>caaaaaa | 7 |
