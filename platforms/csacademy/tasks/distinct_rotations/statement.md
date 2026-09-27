# Distinct Rotations

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/distinct_rotations/](https://csacademy.com/contest/archive/task/distinct_rotations/)  

---

You are given a string where each element is either 0, 1 or ?. Replace all the ? with 0 or 1 in a way that minimises  the number of the distinct circular permutations of the string.

## Standard input

The first line contains the string.

## Standard output

The output should contain the resulting string. If the solution is not unique, print the smallest lexicographical one.

## Constraints and notes

The length of the string is between $1$ and $10^5$

| Input | Output | Explanation |
| --- | --- | --- |
| 01?1 | 0101 | The number of distinct rotations is $2$$0101$$1010$ |
| 0??? | 0000 | The number of distinct rotations is $1$$0000$ |
| 0??1 | 0101 | The number of distinct rotations is $2$$0101$$1010$ |
| 01???0 | 010010 | The number of distinct rotations is $3$$010010$$100100$$001001$ |
