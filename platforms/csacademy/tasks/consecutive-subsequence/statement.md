# Consecutive Subsequence

**Time Limit:** `1000 ms`  
**Memory Limit:** `512 MB`  
**Source:** [https://csacademy.com/contest/archive/task/consecutive-subsequence/](https://csacademy.com/contest/archive/task/consecutive-subsequence/)  

---

You are given an array of $N$ integers. You are allowed to insert a single integer in this array. You can choose both the position of the inserted element and its value. You should perform this operation in a way that will maximize the length of the longest subsequence that consists of consecutive values in increasing order.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

The output should consist of a single integer representing the maximum length of a valid subsequence you can obtain.

### Constraints and notes

$1 \leq N \leq 10^5$The values of the array are between $1$ and $10^6$

| Input | Output | Explanation |
| --- | --- | --- |
| 4<br>1 1 2 2 | 3 | Insert $3$ on the $4$th poisiton: $1\ 1\ 2\ \underline{3}\ 2$.We get the following subsequence: $\underline{1}\ 1\ \underline{2}\ \underline{3}\ 2$ |
| 5<br>2 3 1 3 5 | 4 | Insert $4$ on the $3$rd poisiton: $2\ 3\ \underline{4}\ 1\ 3\ 5$.We get the following subsequence: $\underline{2}\ \underline{3}\ \underline{4}\ 1\ 3\ \underline{5}$. |
| 6<br>2 1 2 3 5 7 | 5 | Insert $4$ on the $5$th poisiton: $2\ 1\ 2\ 3\ \underline{4}\ 5\ 7$.We get the following subsequence: $2\ \underline{1}\ \underline{2}\ \underline{3}\ \underline{4}\ \underline{5}\ 7$. |
| 4<br>2 1 4 5 | 4 | Insert $3$ on the $3$rd poisiton: $2\ 1\ \underline{3}\ 4\ 5$.We get the following subsequence: $3$ on the $3$rd position: $\underline{2}\ 1\ \underline{3}\ \underline{4}\ \underline{5}$ |
