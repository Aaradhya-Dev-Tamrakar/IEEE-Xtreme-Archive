# Two Progressions

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/two_progressions/](https://csacademy.com/contest/archive/task/two_progressions/)  

---

In this problem, we consider arithmetic progressions with positive ratios and at least $2$ elements.

The result of merging two progressions is a sorted array containing all the elements that appear in the progressions. Note that if a value appears in both progressions it should appear in the resulting array twice.

You are given an array of $N$ non-decreasing values. You need to find a pair of arithmetic progressions for which the merging operation is the given array.

An arithmetic progression can be represented by a triplet of the form $(first element, ratio, length)$. You should output the representative triplet for only one of the two progressions, as the other one will be uniquely determined. If there are multiple solutions print the one where the $first element$ is smaller. If there still are multiple solutions, print the one where the $ratio$ is smaller. Finally, if there still are multiple solutions, print the one with smaller $length$.

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consits of two lines:

The first line contains a single integer $N$, the length of the array.The second line contains the $N$ values of the array.

### Standard output

The output should contain the answer for each test case on a different line.

Each answer consists of three integers: the first element, the ratio and the length of the progression. If it's not possible to find an answer for a given test output $-1$.

### Constraints and notes

$1 \leq T \leq 10$$4 \leq N \leq 10^5$The sum of all the values of $N$ in an input file is ≤ $10^5$The values of the array are between $0$ and $10^7$You should only consider solutions where the arithmetic progressions have a strictly positive ratio and at least two elements.

| Input | Output | Explanation |
| --- | --- | --- |
| 5<br>6<br>1 2 3 4 5 6<br>5<br>0 3 6 8 10<br>6<br>0 3 6 8 9 10<br>6<br>1 1 2 2 3 3<br>5<br>2 4 11 12 30 | 1 1 2 <br>0 3 2 <br>0 3 3 <br>1 1 3 <br>-1 | The values in the progressions are:$1, 2$ and $3, 4, 5, 6$$0, 3$ and $6, 8, 10$$0, 3, 6$ and $8, 9, 10$$1, 2, 3$ and $1, 2, 3$no solution |
