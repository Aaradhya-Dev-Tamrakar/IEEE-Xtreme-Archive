# K Consequal

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/k-consequal/](https://csacademy.com/contest/archive/task/k-consequal/)  

---

You are given a string of $N$ lowercase letters of the English alphabet. An operation consists of choosing a group of $K$ consecutive equal characters and removing them. If you perform operations as long as it's possible, what is the final string you get?

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains the string of length $N$.

### Standard output

Output a single line containing the final string.

### Constraints and notes

$1 \leq K \leq N \leq 10^5$It can be proven that the final string is unique.

| Input | Output |
| --- | --- |
| 4 2<br>baac | bc |
| 7 3<br>qddxxxd | q |
