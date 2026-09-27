# Build the Towers

**Time Limit:** `1000 ms`  
**Memory Limit:** `128 MB`  
**Source:** [https://csacademy.com/contest/archive/task/build-the-towers/](https://csacademy.com/contest/archive/task/build-the-towers/)  

---

On an array, you are allowed to select any element equal to $0$. When you do this, the following happens:

If none of the element's neighbour(s) are equal to $1$, the selected element becomes $1$.If at least one of the neighbours is equal to $1$, but no neighbour is equal to $2$, the selected element becomes $2$. In addition, the neighbour(s) equal to $1$ become $0$.If one neighbour is equal to $1$ and the other one is equal to $2$, the selected element becomes $3$. In addition, the neighbours become $0$.

Initially you start with an array of size $N$ where all the elements are $0$. You are given another target array. Select the minimum number of elements in order to make the initial array equal to the target one.

### Standard input

The first line contains a single integer $N$.

The second line contains $N$ integers representing the elements of the target array.

### Standard output

If there is no solution output $-1$.

Otherwise, print on the first line the number $K$ of select operations.

On the second line print $K$ numbers representing the indices of the selected elements.

### Constraints and notes

$1 \leq N \leq 10^5$ The elements of the target array are integers between $0$ and $3$.

| Input | Output | Explanation |
| --- | --- | --- |
| 3<br>2 1 2 | 5<br>2 1 2 3 2 | 0 1 02 0 02 1 02 0 22 1 2 |
| 3<br>1 2 3 | -1 |  |
| 3<br>1 2 2 | -1 |  |
| 4<br>1 3 2 1 | 8<br>1 4 3 2 1 4 3 4 | 1 0 0 01 0 0 11 0 2 00 3 0 01 3 0 01 3 0 11 3 2 01 3 2 1 |
