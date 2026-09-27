# K-subsets Removal

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/k-subsets-removal/](https://csacademy.com/contest/archive/task/k-subsets-removal/)  

---

You are given an array of $N$ integers. On this array you should perform the following type of operation: choose $K$ equal elements and remove them from the array. You have to perform operations as long as it is possible. In the end you are asked to find the most frequent element.

### Standard input

The first line contains two integers $N$ and $K$.

The second line contains $N$ integers representing the elements of the array.

### Standard output

Output a single integer representing the highest frequency of an element in the final array.

### Constraints and notes

$1 \leq K \leq N \leq 1000$The elements of the array are integers between $1$ and $1000$

| Input | Output | Explanation |
| --- | --- | --- |
| 5 2<br>3 3 3 1 2 | 1 | We can perform only one operation: remove two elements equal to $3$. So in the end each distinct value has a frequency of $1$. |
| 6 3<br>2 3 2 3 3 2 | 0 | The array becomes empty, so the answer is $0$. |
| 12 3<br>4 3 4 3 4 4 4 3 3 4 4 3 | 2 | We remove two subsets of $4$s and one subset of $3$s. |
