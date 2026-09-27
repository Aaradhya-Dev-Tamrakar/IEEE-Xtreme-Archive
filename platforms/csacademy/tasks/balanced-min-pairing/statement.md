# Balanced Min Pairing

**Time Limit:** `1500 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/balanced-min-pairing/](https://csacademy.com/contest/archive/task/balanced-min-pairing/)  

---

You are given two arrays, each containing $N$ integers ($N$ is always even). Group the elements of the two arrays in $N$ pairs such that:

Each pair contains an element from the first array and another element from the second array.Each element is assigned to exactly one pair.No pair contains equal values.

In addition, for each pair we look at the minimum of its two values. We call a pairing balanced if there are exactly $N/2$ pairs where the minimum is from the first array (and other $N/2$ pairs where the minimum is from the second array). Find a balanced pairing.

### Standard input

The first line contains an integer $T$ representing the number of test cases that will follow.

Each test case consists of three lines:

The first line contains a single integer $N$.The second line contains the $N$ elements of the first array.The third line contains the $N$ elements of the second array.

### Standard output

Output $T$ lines, each containing the answer for one test:

If a balanced pairing is not possible output $-1$.Otherwise, you should output a permutation representing the solution. If the $i$-th number in the permutation is $j$ then it means the $i$-th element in the first array is paired with the $j$-th element in the second array. If the solution is not unique you can output any of them.

### Constraints and notes

$1 \leq T \leq 25\ 000$$2 \leq N \leq 50\ 000$, $N$ is evenThe sum of $N$ for all $T$ tests is $\leq 50\ 000$The elements of the two arrays are integers between $1$ and $10^5$.

| Input | Output |
| --- | --- |
| 2<br>4<br>3 1 2 4<br>3 1 2 5<br>2<br>2 2<br>1 2 | 4 3 2 1<br>-1 |
